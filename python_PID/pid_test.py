import random
import numpy as np #we always need tis gold 
import matplotlib.pyplot as plt 
import pid_control
from discrete_integrator import Integrator
from math import sin


#pushing a brick in one dimension 
def dynamic_function(f):
    M = 10 #kg 
    a = f/M
    noise = 0 #random.uniform(-10,10)
    return a + noise


position = 0
speed = 0
int_pos = 0

sim_time = 10000

data_array = np.zeros((6,sim_time))


prev_int = 0 
prev_error = 0
time_step = 0.001

my_PID = pid_control.PID_control(time_step, 2, 1, 10)

acc2speed_integrator = Integrator(0,time_step)
speed2pos_integrator = Integrator(0,time_step)

#testing the pid in a simulation 
for clock_ms in range(sim_time):
    
    data_array[0, clock_ms] = clock_ms
    time_step = 0.001
    ref = 1#sin(clock_ms*0.001)
    data_array[5,clock_ms] = ref

    
    error = ref-position
    force = my_PID.update(error)

    data_array[4,clock_ms] = force
    acc = dynamic_function(force)
    
    data_array[1, clock_ms] = acc 


    speed = acc2speed_integrator.intgrate(acc)
    
    data_array[2,clock_ms] = speed

    position = speed2pos_integrator.intgrate(speed)
    data_array[3, clock_ms] = position


    print(f"{(clock_ms+1)*100/sim_time}%")



#plt.plot(data_array[0,:], data_array[4,:]/100)
plt.plot(data_array[0,:], data_array[3,:])
plt.plot(data_array[0,:], data_array[5,:])
plt.grid()
print(np.argmax(data_array[3,:]))

plt.show()



    
