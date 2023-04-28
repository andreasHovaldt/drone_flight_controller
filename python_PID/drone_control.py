import time


import vicon_comunication
from pid_control import PID_control
from discrete_integrator import Integrator



ip = "172.26.51.222"

port = "51001"

vicon_comunicator = vicon_comunication.viconUDP(ip,port)

time_step = 0.3

z_pid = PID_control(time_step, 1, 1, 1)

ref = 1


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
        


