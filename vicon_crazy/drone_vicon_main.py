import numpy as np
import time
from threading import Thread
from control_blocks import Pid_controller, Saturator

from crazy_link import Crazyflie_link
from cflib.utils import uri_helper
from vicon_data import viconUDP




def get_vicon_data_update_pid():
    global running, RPYT_data

    pid_z = Pid_controller(55,5,10)
    #pid_z = Pid_controller(0.1,0,2.6)
    print('connecting to vicon')
    vicon = viconUDP()
    print('connected to vicon')
    thrust_limiter = Saturator(60001, 10001)

    ref = [0,0,1000+200]

    # For use with trajectory (find start postition)
    vicon_data = vicon.getTimestampedData()
    print(f"vicon data {vicon_data}")
    while running:
        vicon_data = vicon.getTimestampedData()

        error = np.array(ref) - np.array(vicon_data[1:4])

        thrust = pid_z.update(error[2],vicon_data[0])

        # Saturation
        thrust = thrust_limiter.limit(thrust)

        RPYT_data = [0,0,0,int(thrust)]

        time.sleep(1/900)





def send_RPYT():
    global RPYT_data, running, cf



    # Unlocks CF motors
    cf.send_start_setpoint()

    while running:
        cf.send_setpoint(RPYT_data)
        print(RPYT_data)
        # Find ud af hvorfor vi sover
        time.sleep(1/900)


def main():
    thread_cf = Thread(target=send_RPYT)
    thread_cf.start()
    print('cf thread started')

    # New thread to run vicon and PID
    print('starting vicon thread')
    thread_vicon = Thread(target=get_vicon_data_update_pid)
    thread_vicon.start()
    print('vicon thread started')
    time.sleep(0.2)
    



if __name__ == "__main__":
    running = True


    # uri for crazyflie drone
    uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')

    cf = Crazyflie_link(uri)
    print('connected to crazyflie')
    
    RPYT_data = [0,0,0,0]

    main()

        # Handle program exit correctly
    while 1:
        try: time.sleep(0.2)
        except KeyboardInterrupt:
            print(">>>> Sending stop command to Crazyflie <<<<")
            cf.send_setpoint(0,0,0,0)
            time.sleep(0.1)
            cf.send_stop_setpoint()
            time.sleep(0.1)
            running = False
            time.sleep(0.1)
            exit("Exiting program")