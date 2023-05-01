import time


import Position_control.vicon_data as vicon
from pid_control import PID_control
from discrete_integrator import Integrator

# drone libraries
from crazy_link import Crazyflie_link
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

vicon_comunicator = vicon.viconUDP()



P = 0.2

I = 0

D = 2.6


z_pid = PID_control(0.1, P, I, D)

ref = 1000


if __name__ == "__main__":
    cflib.crtp.init_drivers()
    drone = Crazyflie_link(link_uri=uri)
    drone.send_start_setpoint()
    data = vicon_comunicator.getTimestampedData()
    prev_time = data[0]
    while True:
        data = vicon_comunicator.getTimestampedData()
        time = data[0]
        error = ref - data[3]
        time_step = time - prev_time
        thrust = z_pid.update(error, time_step)
        print(thrust)
        # Make sure thrust is within the defined range.
        if thrust > 65000:
            thrust = 65000
        elif thrust < 0:
            thrust = 0
        drone.send_setpoint(0, 0, 0, thrust)
        prev_time = time
        


