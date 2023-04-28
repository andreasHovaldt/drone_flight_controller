import numpy as np
import matplotlib.pyplot as plt
from pid_control import Pid_controller

# step time - seconds
time_step = 0.001

# Simulation time - seconds
simulation_time = 50


class dynamic_system():
    def __init__(self, mass, max_force, setPoint):

        # system variables
        self.position = 0.0
        self.mass = mass
        self.target = setPoint # :)
        self.max_force = max_force


        # arrays for plotting
        self.position_array = []
        self.time_array = []
        self.force_array = []
        self.acc_array = []
        self.vel_array = []
        self.target_array = []

        # control variables
        self.error = 0.0
        self.acc = 0.0

        # Make a variable for the control system to adjust
        self.force = 0.0
        self.vel = 0.0

        # initiatize PID
        self.position_pid = Pid_controller(time_step,1,0,2)



    def update(self, time_sample):
        
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
        self.time_array.append(time_sample)
        self.target_array.append(self.target)



        




def main():

    # Initiate dynamic system class 
    system = dynamic_system(mass=5, max_force=25, setPoint=10)

    # Cycle through each step of the simulation time
    for cycle in np.arange(0,simulation_time,time_step):
        system.update(cycle)

    # Plot position and target
    plt.plot(system.time_array, system.position_array)
    plt.plot(system.time_array, system.target_array)
    
    # Plot force
    #plt.plot(system.time_array, system.force_array)

    plt.grid()
    plt.show()

if __name__ == '__main__':
    main()
