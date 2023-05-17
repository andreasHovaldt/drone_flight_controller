import numpy as np
import time
from threading import Thread
from control_blocks import Pid_controller, Saturator

from crazy_link import Crazyflie_link
from cflib.utils import uri_helper
from vicon_link import viconUDP



def get_vicon_data_update_pid():
    global running, RPYT_data, data_array_log


    RP_P = 60/1000
    RP_I = 5/1000
    RP_D = 45/1000
            
    pid_x = Pid_controller(RP_P,RP_I,RP_D)
    pid_y = Pid_controller(RP_P,RP_I,RP_D)
    pid_z = Pid_controller(100,25,15)
    #pid_yaw = Pid_controller(1.4,0.3,1)

    pid_yaw = Pid_controller(13,1,12)

    

    print('connecting to vicon')
    vicon = viconUDP()
    
    print('connected to vicon')
    thrust_limiter = Saturator(60001, 30001)

    # Find the start height, in the vicon system
    vicon_data_first_run = vicon.getTimestampedData()


    # Define reference as the start height + 1000 mm
    ref = 500 + vicon_data_first_run[3]


    while running:
        # Fetch new data from vicon
        vicon_data = vicon.getTimestampedData()

        # Log the ref and the actual position
        data_array_log.append([vicon_data[0], vicon_data[3], ref])

        # Update error with the new data
        error = ref - vicon_data[3]

        # Calculate the new thrust value using the pid-controller
        thrust = pid_z.update(error, vicon_data[0])

        # Saturation
        thrust = thrust_limiter.limit(thrust)

        # Update the global variable RPYT_data, in order for the crazyflie to act according to the newest data.
        RPYT_data = [0,0,0,int(thrust)]

        # Sleep to allow the other threads to run
        time.sleep(1/900)





def send_RPYT():
    global RPYT_data, running, cf
    
    # Unlocks CF motors
    cf.send_start_setpoint()

    while running:
        # Send the latest RPYT to the crazyflie
        cf.send_setpoint(RPYT_data)

        # Sleep to allow the other threads to run
        time.sleep(1/900)


def threads_vicon_crazy_start():
    # Start a new thread running the crayflie function
    thread_cf = Thread(target=send_RPYT)
    thread_cf.start()
    print('cf thread started')
    time.sleep(0.2)

    # Start new thread to run vicon and PID
    print('starting vicon thread')
    thread_vicon = Thread(target=get_vicon_data_update_pid)
    thread_vicon.start()
    print('vicon thread started')
    time.sleep(0.2)
    



if __name__ == "__main__":

    # Global variables
    running = True
    RPYT_data = [0,0,0,0]
    data_array_log = []


    # uri for crazyflie drone
    uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')

    # Establish connection to the cf drone
    cf = Crazyflie_link(uri)
    print('connected to crazyflie')
    

    # Start the other threads
    threads_vicon_crazy_start()

    # Exit program with KeyboardInterrupt, and stop the other threads
    print('Entering main while loop - Cancel with: ctrl + c')
    while 1:
        try: time.sleep(0.2)
        except KeyboardInterrupt:
            print("SHUTTING DOWN MOTORS - KEYBOARD INTERRUPT")
            cf.send_setpoint(0,0,0,0)
            time.sleep(0.1)
            cf.send_stop_setpoint()
            time.sleep(0.1)
            running = False
            time.sleep(0.1)
            exit("Exiting program")