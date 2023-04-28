import time


import vicon_communication
from pid_control import PID_control
from discrete_integrator import Integrator

# drone libraries
import logging
import time
from threading import Thread

import cflib
from cflib.crazyflie import Crazyflie
from cflib.utils import uri_helper


# Drone connection
uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')

logging.basicConfig(level=logging.ERROR)



# Vicon comm
ip = "0.0.0.0"

port = "51001"

vicon_comunicator = vicon_communication.viconUDP(ip,port)



z_pid = PID_control(0.1, 1, 0, 1)

ref = 1000


if __name__ == "__main__":
    data = vicon_comunicator.getTimestampedData()
    prev_time = data[0]
    while True:
        data = vicon_comunicator.getTimestampedData()
        time = data[0]
        error = ref - data[3]
        time_step = time - prev_time
        thrust = z_pid.update(error, time_step)
        prev_time = time
        


