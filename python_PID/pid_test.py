import numpy as np #we always need tis gold 
import matplotlib.pyplot as plt 
import pid_control
from math import sin


#pushing a brick in one dimension 
def dynamic_function(f):
    M = 10 #kg 
    a = f/M
    return a 


position = 0
speed = 0
int_pos = 0

sim_time = 1000

data_array = np.zeros((6,sim_time))


prev_int = 0 
prev_error = 0


my_PID = pid_control.PID_control(0.001, 9000, 1, 700)


for clock_ms in range(sim_time):
    
    data_array[0, clock_ms] = clock_ms
    time_step = 0.001
    ref = 1#sin(clock_ms*0.001)
    data_array[5,clock_ms] = ref
    error = ref-position
    f = my_PID.update(error)
    data_array[4,clock_ms] = f
    a = dynamic_function(f)
    data_array[1, clock_ms] = a 


    speed = a*time_step+speed
    data_array[2,clock_ms] = speed

    position = speed*time_step+position
    data_array[3, clock_ms] = position

    int_pos = position*time_step+int_pos

    print(f"{(clock_ms+1)*100/sim_time}%")

print (data_array)


plt.plot(data_array[0,:], data_array[3,:])
plt.plot(data_array[0,:], data_array[4,:])
plt.show()



    
