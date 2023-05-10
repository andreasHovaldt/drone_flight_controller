import numpy as np
import matplotlib.pyplot as plt
import math

# PID controller that continously updates the time step.
class Pid_controller():
    def __init__(self, P, I, D):
        self.Kp = P
        self.Ki = I
        self.Kd = D

        self.clear()

    def clear(self):
        # Clears the output and resets values.
        self.i_part = 0.0
        self.previous_error = 0.0
        self.previous_time = 0.0
        self.elapsed_time = 0.0


    def update(self, error, current_time):
        
        # Calculate new time (this will be in seconds)
        self.elapsed_time = current_time - self.previous_time
        
        # calculate the p_part
        p_part = error

        # Calculate the i_part
        self.i_part = self.i_part + error * self.elapsed_time
        
        # Calculate the d_part
        d_part = (error - self.previous_error) / self.elapsed_time

        # Update previous_error and previous_time
        self.previous_error = error
        self.previous_time = current_time

        return self.Kp * p_part + self.Ki * self.i_part + self.Kd * d_part
        


class Saturator():
    '''Class used to ensure that the motors dont exceed a set max or min value
    this is used to ensre that the data send to the crazyflie control stack is consistent
    with the documentation'''
    def __init__(self, upper_limit, lower_limit):
        self.max = upper_limit
        self.min = lower_limit

    def limit(self, input):
        # Make sure input is within the defined range.
        if input > self.max:
            input = self.max

        elif input < self.min:
            input = self.min     

        return input




    
def thrust_to_command(input_thrust_grams):
    return 604462909807314587353088*math.sqrt((7544718326147207*input_thrust_grams/302231454903657293676544 + 11472845254943727195617/37778931862957161709568000000))/7544718326147207 - 41468280677699072032768/943089790768400875



def main():
    time = 0.01

    error = 1000

    PID = Pid_controller(0.1, 0, 2)

    print(PID.update(error,time))


if __name__ == '__main__':
    main()