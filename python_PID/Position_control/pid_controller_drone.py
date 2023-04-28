import numpy as np
import matplotlib.pyplot as plt


class Pid_controller():
    def __init__(self, P, I, D, I_Max=None):
        self.Kp = P
        self.Ki = I
        self.Kd = D

        self.clear()

    def clear(self):
        # Clears the output and resets values.
        self.i_part = 0.0
        self.previous_error = 0.0


    def update(self, error, time_step):
        
        # calculate the p_part
        p_part = error

        # Calculate the i_part
        self.i_part = self.i_part + error * time_step
        
        # Calculate the d_part
        d_part = (error - self.previous_error) / time_step

        # Update previous_error
        self.previous_error = error

        return self.Kp * p_part + self.Ki * self.i_part + self.Kd * d_part
        