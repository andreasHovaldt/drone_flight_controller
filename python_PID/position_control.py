import numpy as np #we always need tis gold 
import matplotlib.pyplot as plt 
import pid_control
from discrete_integrator import Integrator
from math import sin
time_step = 0.001 
sim_time = 10000 #ms 

#start values 
position = np.array([0, 0, 0])
acceleration = np.array([0,0,0]) 

#we create the PID controlers for x y and z 
x_pid = pid_control.PID_control(time_step, 11, 1, 10)
y_pid = pid_control.PID_control(time_step, 12, 1, 10)
z_pid = pid_control.PID_control(time_step, 13, 1, 10)

#we create the integrators 
acc_to_speed = Integrator(np.array([0,0,0]),time_step)
speed_to_pos = Integrator(np.array([0,0,0]),time_step)

data_array = data_array = np.zeros((8,sim_time))


#temporarily we simulate the drone whith a dynamic function 
def brick_dynamics(thrust_vector):
    mass = 10
    acc_vector = thrust_vector/mass
    return acc_vector


for clock_ms in range(sim_time):
    ref = np.array([sin(clock_ms/1000),sin(clock_ms/1200),sin(clock_ms/1100)])
    data_array[0,clock_ms] = clock_ms
    
    data_array[5:8,clock_ms] = ref.T

    error = ref-position
    
    thrust = np.array([0,0,0])

    thrust[0] = x_pid.update(error[0])
    thrust[1] = y_pid.update(error[1])
    thrust[2] = z_pid.update(error[2])

    acc = brick_dynamics(thrust)

    speed = acc_to_speed.intgrate(acc)
    position = speed_to_pos.intgrate(speed)

    data_array[1:4,clock_ms] = np.transpose(position)

print(data_array)


plt.plot(data_array[0,:], data_array[3,:])
plt.plot(data_array[0,:], data_array[7,:])

plt.show()

pz = data_array[3,:]
py = data_array[2,:]
px = data_array[1,:]

rz = data_array[7,:]
ry = data_array[6,:]
rx = data_array[5,:]

ax = plt.figure().add_subplot(projection='3d')

ax.plot(px, py, pz, label='pos curve')
ax.plot(rx, ry, rz, label='ref curve')
ax.legend()

plt.show()














