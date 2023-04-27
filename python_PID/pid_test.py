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

data_array = np.zeros((6,sim_time))


prev_int = 0 
prev_error = 0
time_step = 0.01

my_PID = pid_control.PID_control(time_step, 20, 1, 10)

acc2speed_integrator = Integrator(0,time_step)
speed2pos_integrator = Integrator(0,time_step)


data_array = []

data_vector = []

#testing the pid in a simulation 
for clock in np.arange(0,sim_time,time_step):
    data_vector.append(clock)
    ref = 1#sin(clock_ms*0.001)
    data_vector.append(ref)

    
    error = ref-position
    force = my_PID.update(error)

    data_vector.append(force)
    acc = dynamic_function(force)
    

    speed = acc2speed_integrator.intgrate(acc)
    
    position = speed2pos_integrator.intgrate(speed)
    data_vector.append(position)
    data_array.append(data_vector)
    data_vector = []

    print(f"{(clock)*100/sim_time}%")



#plt.plot(data_array[0,:], data_array[4,:]/100)


data_array = np.transpose(np.array(data_array))
print(data_array.shape)



plt.plot(data_array[0,:], data_array[1,:])
plt.plot(data_array[0,:], data_array[3,:])
plt.grid()
print(np.argmax(data_array[3,:]))

plt.show()



    
