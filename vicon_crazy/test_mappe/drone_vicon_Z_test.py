import numpy as np
import time
from threading import Thread
from control_blocks import Pid_controller, Saturator

from crazy_link import Crazyflie_link
from cflib.utils import uri_helper
from vicon_link import viconUDP


def get_vicon_data_update_pid():
    global running, RPYT_data


    pid_z = Pid_controller(65,5,10)
    #pid_z = Pid_controller(0.1,0,2.6)

    print('connecting to vicon')
    vicon = viconUDP()
    
    print('connected to vicon')
    thrust_limiter = Saturator(60001, 10001)

    # Find the start height, in the vicon system
    vicon_data_first_run = vicon.getTimestampedData()


    # Define reference as the start height + 1000 mm
    ref = 1000 + vicon_data_first_run[3]


    while running:
        # Fetch new data from vicon
        vicon_data = vicon.getTimestampedData()

        # Log the ref and the actual position
        data_array_log.append([vicon_data[3], ref])

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
            cf.send_setpoint([0,0,0,0])
            time.sleep(0.1)
            cf.send_stop_setpoint()
            time.sleep(0.1)
            running = False
            time.sleep(0.1)
            np_vicon_data = np.array(data_array_log)
            np.savetxt("trj_data.txt", np.array(np_vicon_data))
            time.sleep(1)
            exit("Exiting program")