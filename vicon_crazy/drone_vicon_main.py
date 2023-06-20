#------------------------------------------------------------------------------------

# Place drone with blue lights facing the control suite
# Create object in vicon 
# Start flying with blue lights facing the control suite 

#------------------------------------------------------------------------------------

import numpy as np
import time
from threading import Thread
from control_blocks import Pid_controller, Saturator

from crazy_link import Crazyflie_link
from cflib.utils import uri_helper
from vicon_link import viconUDP

from trajectory_generation import Trajectory


def exit_program(trajectory_done: bool):
    global cf, running, data_array_log
    if trajectory_done:
        print("Trajectory fulfilled")
    else:
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


def get_vicon_data_update_pid():
    global running, RPYT_data, data_array_log, field_trj, trj_time, experimental

    match experimental:
        case True:
            # PID coefficients from theory (without unit conversion)
            RP_P = 1.1
            RP_I = 0.051
            RP_D = 5.88

        case False:
            # PID coefficients from testing
            RP_P = 60/1000
            RP_I = 5/1000
            RP_D = 45/1000


    # Set PID values
    pid_x = Pid_controller(RP_P,RP_I,RP_D)
    pid_y = Pid_controller(RP_P,RP_I,RP_D)
    pid_z = Pid_controller(25,5,13)
    pid_yaw = Pid_controller(13,1,12)


    # Hover thrust
    hover_thrust = 43308

    print('Connecting to vicon')
    vicon = viconUDP()

    # Make instance of saturators
    roll_pitch_limiter = Saturator(5, -5) # degrees
    thrust_limiter = Saturator(21001, -21001) # 16-bit integer - thrust command


    # Find start postition (For use with trajectory)
    vicon_data_first_run = vicon.getTimestampedData()
    drone_origin = np.array([vicon_data_first_run[1],vicon_data_first_run[2],vicon_data_first_run[3]])


    # Trajectory plan for field scenario
    trj_points_field = [[0,0,0], [0,0,1000], [0,0,1000]]           
    for x_point in range(3):
        for y_point in range(5):
            if (x_point % 2) == 0:
                trj_points_field.append([x_point*500, y_point*500, 1000])
                trj_points_field.append([x_point*500, y_point*500, 1000])
            else:
                trj_points_field.append([x_point*500, -y_point*500+2000, 1000])
                trj_points_field.append([x_point*500, -y_point*500+2000, 1000])
                
    trj_points_field.append([0,0,1000])
    trj_points_field.append([0,0,250])
    trj_points_field = np.array(trj_points_field)
 
    # Create trajectory array for field observation
    field_trj = Trajectory(drone_origin,trj_points_field)

    # The total time for the calculated trajectory
    trj_time = field_trj.get_trj_time()
    
    while running:
        vicon_data = vicon.getTimestampedData()
        ref = field_trj.get_position(vicon_data[0])
        
        data_array_log.append(vicon_data + ref.tolist())
        error = ref - np.array(vicon_data[1:4])

        roll = pid_y.update(error[1],vicon_data[0])
        pitch = pid_x.update(error[0], vicon_data[0])
        thrust = pid_z.update(error[2],vicon_data[0])
        #(yaw error, time)
        yaw = pid_yaw.update(0-vicon_data[-1],vicon_data[0])

        # Saturation
        thrust = thrust_limiter.limit(thrust)
        roll = roll_pitch_limiter.limit(roll)
        pitch = roll_pitch_limiter.limit(pitch)
        
        # Update data which is sent to the Crazyflie in "send_RPYT()"
        RPYT_data = [-roll,pitch,-yaw,int(hover_thrust + thrust)]

        time.sleep(1/500)





def send_RPYT():
    global RPYT_data, running, cf 
    
    # Unlocks CF motors
    cf.send_start_setpoint()

    while running:
        cf.send_setpoint(RPYT_data)

        # Sleep to allow the other threads run
        time.sleep(1/500)


def threads_vicon_crazy_start():
    '''
    Starts two threads: Vicon and Crazyflie 
    '''
    thread_cf = Thread(target=send_RPYT)
    thread_cf.start()
    print('cf thread started')
    time.sleep(0.2)
    
    # New thread to run vicon and PID
    print('starting vicon thread')
    thread_vicon = Thread(target=get_vicon_data_update_pid)
    thread_vicon.start()
    print('vicon thread started')
    time.sleep(0.2)
    



if __name__ == "__main__":

    # Initiate global variables
    running = True
    RPYT_data = [0,0,0,0]
    data_array_log = None
    field_trj = None
    trj_time = None
    experimental = False # Changes XY-PID coefficients between theory and tested coefficients (True = theory)

    # Uniform Resource Identifier for crazyflie drone 
    uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')
    # radio://<channel>/<address>/<datarate>/<custom_identifier>


    # Establish connection to crazyflie
    cf = Crazyflie_link(uri)
    print('connected to crazyflie')

    # Start threads
    threads_vicon_crazy_start()

    timer = time.time()

    # Exit program with KeyboardInterrupt, and stop the other threads
    print('Entering main while loop - Cancel with: ctrl + c')
    while True:
        try: 
            time.sleep(0.2)
            if timer+trj_time < time.time():
                exit_program(1)

        except KeyboardInterrupt:
            exit_program(0)