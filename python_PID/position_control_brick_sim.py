import numpy as np #we always need tis gold 
import matplotlib.pyplot as plt 
import pid_control
from discrete_integrator import Integrator
from trajectory_generation import Trajectory
from math import sin
time_step = 0.01 


#start values 


point_array = np.random.random((5,3))
point_array[0] = [0,0,0]
position = point_array[0]
acceleration = np.array([0,0,0]) 
print(point_array)

brick_ref_trj = Trajectory(point_array)

sim_time = brick_ref_trj.get_total_time()



#we create the PID controlers for x y and z 
x_pid = pid_control.PID_control(time_step, 110, 1, 100)
y_pid = pid_control.PID_control(time_step, 120, 1, 100)
z_pid = pid_control.PID_control(time_step, 130, 1, 100)

#we create the integrators 
acc_to_speed = Integrator(np.array([0,0,0]),time_step)
speed_to_pos = Integrator(np.array([0,0,0]),time_step)




#temporarily we simulate the drone with a dynamic function 
def brick_dynamics(thrust_vector):
    mass = 10
    acc_vector = thrust_vector/mass
    return acc_vector


time_array = []

ref_array = [] 

pos_array = []


for clock in np.arange(0,sim_time,time_step):
    ref = brick_ref_trj.get_position(clock)


    time_array.append(clock)
    
    ref_array.append(ref.T)

    error = ref-position
    
    thrust = np.array([0,0,0])

    thrust[0] = x_pid.update(error[0],time_step)
    thrust[1] = y_pid.update(error[1],time_step)
    thrust[2] = z_pid.update(error[2],time_step)

    acc = brick_dynamics(thrust)

    speed = acc_to_speed.intgrate(acc,time_step)
    position = speed_to_pos.intgrate(speed,time_step)

    pos_array.append(np.transpose(position))


ref_array = np.array(ref_array)

fig, axs = plt.subplots(3)
axts = ["x", "y", "z"]

for ax, axt, data_index in zip(axs, axts, range(3)):
    ax.plot(time_array, ref_array[:,data_index])
    ax.set_ylabel(f"{axt} position")


axs[2].set_xlabel("Time [s]")
#plt.plot(time_array, pos_array)

plt.show()

pos_array = np.array(pos_array)
ref_array = np.array(ref_array)


print(ref_array.shape)

pz = pos_array[:,2]
py = pos_array[:,1]
px = pos_array[:,0]

rz = ref_array[:,2]
ry = ref_array[:,1]
rx = ref_array[:,0]

ax = plt.figure().add_subplot(projection='3d')

#ax.plot(px, py, pz, label='pos curve')
ax.plot(rx, ry, rz, label='ref curve')
ax.legend()

plt.show()














