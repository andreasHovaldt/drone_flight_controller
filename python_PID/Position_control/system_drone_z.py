import numpy as np
import matplotlib.pyplot as plt
import time

# PID controller library
from pid_controller_drone import Pid_controller

# Vicon library
from vicon_data import viconUDP

# drone libraries
import cflib
from cflib.crazyflie import Crazyflie
from cflib.utils import uri_helper

# Python script, connecting to CF
from python_PID.drone_RPYT_control import Crazyflie_control



class position_control():
    def __init__(self, drone, setPointZ):
        self.drone = drone
        self.target = setPointZ
        self.thrust = 0 # Thrust of the crazyflie drone (A 16-bit number: 0 -> 65535)

        # Define max and min values for the thrust value on the crazyflie drone.
        self. max_thrust = 65535
        self.min_thrust = 0

        # Initiate the PID controller
        self.position_pid = Pid_controller(1, 0, 1)

    def update(self, vicon_data_array):
        '''Updates the control commands sent to the crazyflie'''
        
        # Compute error (I have the reference position and the current location from the vicon data)
        self.error = self.target - vicon_data_array[3]

        # calculate new thrust 
        self.thrust = self.position_pid.update(self.error, vicon_data_array[0])

        # Make sure thrust is within the defined range.
        if self.thrust > self.max_thrust:
            self.thrust = self.max_thrust
        elif self.thrust < self.min_thrust:
            self.thrust = self.min_thrust


        # Move the drone
        self.drone.send_commands(0, 0, 0, self.thrust)



    def set_ref(self, setPointZ):
        self.target = setPointZ

        




def main():

    # Initialize the low-level drivers on the crazyflie.
    cflib.crtp.init_drivers()

    # connect to vicon system
    vicon_ip = '0.0.0.0'
    vicon_port = 51001
    vicon_comm = viconUDP(vicon_ip,vicon_port)

    # Get initial info from vicon (Used to check the while loop before first cycle)
    vicon_data = vicon_comm.getTimestampedData()

    # uri for crazyflie drone
    uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')

    # Initialize the class.
    drone = Crazyflie_control(link_uri=uri)

    # Initialize the drone class that calculates the new thrust sends the commands to the drone.
    system = position_control(drone, setPointZ=1000) # setPointZ is meassured in mm.


    # While loop that runs the control system and drone (No stop)
    '''while True:
        # Update new position (and time) from vicon
        vicon_data = vicon_comm.getTimestampedData()

        # Send new position (and time) to the control system
        system.update(vicon_data)'''

    
    # Experimental loop (lands after target is reached)
    while vicon_data[3] :
        # Update new position (and time) from vicon
        vicon_data = vicon_comm.getTimestampedData()

        # Send new position (and time) to the control system
        system.update(vicon_data)



if __name__ == '__main__':
    main()
