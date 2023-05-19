import numpy as np
import time
from threading import Thread
from control_blocks import Pid_controller, Saturator

from crazy_link import Crazyflie_link
from cflib.utils import uri_helper
from vicon_link import viconUDP

from trajectory_generation import Trajectory


def exit_program(trajectory_done: bool):
    global cf, running, data_array_log, stop_point_position_array
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
    #np.savetxt("stop_point_trj_data9_new.txt", np.array(np_vicon_data))
    #np.savetxt("stop_point_deviations9_new.txt", np.array(stop_point_position_array))
    time.sleep(1)
    exit("Exiting program")


def get_vicon_data_update_pid():
    global running, RPYT_data, data_array_log, cool_trj, total_time, experimental, stop_point_position_array

    # RP_P = 25/1000
    # RP_I = 15/1000
    # RP_D = 9.8/1000

    match experimental:
        case True:
            # PID coefficients from theory
            RP_P = 1.1/1000
            RP_I = 0.051/1000
            RP_D = 5.88/1000

        case False:
            # PID coefficients from testing
            RP_P = 60/1000
            RP_I = 5/1000
            RP_D = 45/1000


    hover_thrust = 43308


    pid_x = Pid_controller(RP_P,RP_I,RP_D)
    pid_y = Pid_controller(RP_P,RP_I,RP_D)
    pid_z = Pid_controller(35,5,17)
    #pid_yaw = Pid_controller(1.4,0.3,1)

    pid_yaw = Pid_controller(13,1,12)

    print('connecting to vicon')
    vicon = viconUDP()

    # Test vicon connection
    if vicon.connection_test() != True:
        print('VICON TEST NOT PASSED!')
    else:
        print('Connected to vicon')

    roll_pitch_limiter = Saturator(5, -5)
    thrust_limiter = Saturator(21001, -21001)

    # For use with trajectory (find start postition)
    vicon_data_first_run = vicon.getTimestampedData()
    #print(f"vicon data {vicon_data}")

    
    # Trajectory plan for field scenario - no stop points
    trj_points_field = [[0,0,0], [0,0,1500], [0,0,1000]]  # starting point  
    # following for loops are used to generate the rest of the field points each representing
    # how many points in x- directon and y-direction       


    #Trajectory plan for field scenario
    trj_points_field = [[0,0,0], [0,0,1500], [0,0,1000]]           
    for x_point in range(5):
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
 
    #trj_points = [[vicon_data_first_run[1],vicon_data_first_run[2],vicon_data_first_run[3]],[vicon_data_first_run[1],vicon_data_first_run[2],vicon_data_first_run[3]+1000], [0,0,vicon_data_first_run[3]+1000]]
    
    drone_origin = np.array([vicon_data_first_run[1],vicon_data_first_run[2],vicon_data_first_run[3]])
    #trj_points = np.array(trj_points)
    #print(trj_points.shape)
    cool_trj = Trajectory(drone_origin,trj_points_field)
    
    stop_times = np.cumsum(cool_trj.get_time_array())
    stop_point_index = 0
    stop_point_position_array = []

    ref_data = trj_points_field[1,:]

    total_time = cool_trj.get_total_time()
    
    while running:

        vicon_data = vicon.getTimestampedData()


        ref = cool_trj.get_position(vicon_data[0])
        
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
        
        #place drone with blue lights facing the control suite
        #create object in vicon 
        #start flying with blue lights facing the control suite 
        RPYT_data = [-roll,pitch,-yaw,int(hover_thrust + thrust)]

        #code to check for stop point 
        if vicon_data[0] > stop_times[stop_point_index]:
            stop_point_index += 1
            stop_point_position_array.append([vicon_data[0], error[0], error[1], error[2]])

        time.sleep(1/900)





def send_RPYT():
    global RPYT_data, running, cf 
    
    # Unlocks CF motors
    cf.send_start_setpoint()

    while running:
        cf.send_setpoint(RPYT_data)
        #print(RPYT_data)
        # Find ud af hvorfor vi sover
        time.sleep(1/900)


def threads_vicon_crazy_start():
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

    # Global variables
    running = True
    RPYT_data = [0,0,0,0]
    data_array_log = []
    ref_array = None
    cool_trj = None
    total_time = 0.0
    experimental = False

    #for test 
    stop_point_position_array = []

    # uri for crazyflie drone
    uri = uri_helper.uri_from_env(default='radio://0/80/2M/E7E7E7E7E7')

    cf = Crazyflie_link(uri)
    print('connected to crazyflie')

    threads_vicon_crazy_start()

    timer = time.time()

    # Exit program with KeyboardInterrupt, and stop the other threads
    print('Entering main while loop - Cancel with: ctrl + c')
    while 1:
        try: 
            time.sleep(0.2)
            if timer+total_time < time.time():
                exit_program(1)

        except KeyboardInterrupt:
            exit_program(0)