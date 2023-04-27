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

sim_time = 10

data_array = np.zeros((6,sim_time*1000))


prev_int = 0 
prev_error = 0
time_step = 0.001

my_PID = pid_control.PID_control(time_step, 6, 1, 10)

acc2speed_integrator = Integrator(0,time_step)
speed2pos_integrator = Integrator(0,time_step)

#testing the pid in a simulation 
for clock_ms in np.arange(0,sim_time,time_step):
    
    data_array[0, int(clock_ms*1000)] = clock_ms
    
    ref = 1#sin(clock_ms*0.001)
    data_array[5,int(clock_ms*1000)] = ref

    
    error = ref-position
    force = my_PID.update(error)

    data_array[4,int(clock_ms*1000)] = force
    acc = dynamic_function(force)
    
    data_array[1, int(clock_ms*1000)] = acc 


    speed = acc2speed_integrator.intgrate(acc)
    
    data_array[2,int(clock_ms*1000)] = speed

    position = speed2pos_integrator.intgrate(speed)
    data_array[3, int(clock_ms*1000)] = position


    print(f"{(clock_ms+1)*100/sim_time}%")



#plt.plot(data_array[0,:], data_array[4,:]/100)
plt.plot(data_array[0,:], data_array[3,:])
plt.plot(data_array[0,:], data_array[5,:])
plt.grid()
print(np.argmax(data_array[3,:]))

plt.show()



    
