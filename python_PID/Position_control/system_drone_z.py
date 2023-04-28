import numpy as np
import matplotlib.pyplot as plt

# PID controller library
from pid_controller_drone import Pid_controller

# Vicon library
from vicon_data import viconUDP

# drone libraries
import logging
import time
from threading import Thread

import cflib
from cflib.crazyflie import Crazyflie
from cflib.utils import uri_helper



class position_control():
    def __init__(self, uri_for_crazyflie, setPointZ, ):
        self.target = setPointZ
        self.uri = uri_for_crazyflie


    def update(self, time_step):
        
        # Compute error
        self.error = self.target - self.position

        # calculate new force
        self.force = self.position_pid.update(self.error)

        # Make sure force does not exceed max force.
        if self.force > self.max_force:
            self.force = self.max_force
        elif self.force < -self.max_force:
            self.force = -self.max_force


        
        # Calculate acc with new force + append new acc
        self.acc = self.force / self.mass
  

        # Integrate twice to obtain position 
        self.vel = self.vel + self.acc * time_step # First integration: acc -> velocity

        self.position = self.position + self.vel * time_step # Second integration: vel -> position


        # Append new variables to the data arrays, in order to plot the results later.
        self.force_array.append(self.force)
        self.acc_array.append(self.acc)
        self.vel_array.append(self.vel)
        self.position_array.append(self.position)
        self.time_array.append(time_step)
        self.target_array.append(self.target)



        




def main():

    # Initialize the low-level drivers on the crazyflie.
    cflib.crtp.init_drivers()

    # connect to vicon system
    vicon_ip = '0.0.0.0'
    vicon_port = 51001
    vicon_comm = viconUDP(vicon_ip,vicon_port)


    # uri for crazyflie drone
    uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')

    # 

    # Initialize the drone class that calculates the new thrust sends the commands to the drone.
    position_control(setPointZ=1000) # setPointZ is meassured in mm.



    # # Plot position and target
    # plt.plot(system.time_array, system.position_array)
    # plt.plot(system.time_array, system.target_array)
    
    # # Plot force
    # #plt.plot(system.time_array, system.force_array)

    # plt.grid()
    # plt.show()



if __name__ == '__main__':
    main()
