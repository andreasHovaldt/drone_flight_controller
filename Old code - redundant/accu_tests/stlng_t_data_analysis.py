import numpy as np
import matplotlib.pyplot as plt 
import os 
from scipy.ndimage import label

step_data_x = []
step_data_y = []
step_data_z = []

trj_data = []

for filepath in os.scandir("Data fra tests/Settling Time"):
    rfp = filepath.path #relative file path string 
    axis = rfp[48]
    if axis == 'x':
        step_data_x.append(np.loadtxt(rfp))
    elif axis == 'y':
        step_data_y.append(np.loadtxt(rfp))
    elif axis == 'z':
        step_data_z.append(np.loadtxt(rfp))
    else:
        print("axis not found")

#   zzzzzz
#       z
#      z
#     z
#    z
#   ZZZZZZ
fig, ax = plt.subplots(3)
ax[0].set_title("Z axis setteling time")
z_sttl_times =[]
for data in step_data_z:
    
    data[:,0] = data[:,0] - np.ones_like(data[:,0])*data[0,0]

    ax[0].plot(data[:,0],data[:,3])
    ax[0].plot(data[:,0],data[:,9])
    error = np.abs(data[:,9]-data[:,3])
    settling_point = np.ones_like(error)*(data[0,9]-data[0,3])*0.05 
    ax[1].plot(data[45:-1,0],error[45:-1])
    ax[1].plot(data[45:-1,0],settling_point[45:-1])
    rice_time = error < (data[0,9]-data[0,3])*0.63
    index = 0
    
    within_range = np.zeros_like(error)
    within_range[index+1:-1] = error[index+1:-1] < (data[0,9]-data[0,3])*0.05
    
    lb_data, num_features = label(within_range)

    ax[2].plot(data[:,0],lb_data)
    #print(f"dips {np.max(lb_data)}")

    crossovers = np.max(lb_data)

    last_within_range=lb_data==crossovers
    index = np.argmax(last_within_range)


    #print(f"index {index}")
    #print(f"rice time {data[np.argmax(rice_time),0]} ;-D ")
    print(f"Z sttl time {data[index,0]}")
    z_sttl_times.append(data[index,0])
#plt.show()




#yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
y_sttl_times = []
fig, ax = plt.subplots(3)
ax[0].set_title("Y axis setteling time")
for data in step_data_y:
    
    data[:,0] = data[:,0] - np.ones_like(data[:,0])*data[0,0]

    ax[0].plot(data[:,0],data[:,2])
    ax[0].plot(data[:,0],data[:,8])
    error = np.abs(data[:,8]-data[:,2])
    settling_point = np.ones_like(error)*(data[0,8]-data[0,2])*0.05 
    ax[1].plot(data[:,0],error)
    ax[1].plot(data[:,0],settling_point)
    rice_time = error < (data[0,8]-data[0,2])*0.63
    index = 0
    

    within_range = np.zeros_like(error)
    
    within_range[index+1:-1] = error[index+1:-1] < (data[0,8]-data[0,2])*0.05
    
    lb_data, num_features = label(within_range)

    ax[2].plot(data[:,0],lb_data)
    #print(f"dips {np.max(lb_data)}")

    crossovers = np.max(lb_data)

    last_within_range=lb_data==crossovers
    index = np.argmax(last_within_range)

    
    #index = np.argmax(within_range)
    
    #print(f"index out {index}")
    
    #print(f"index {index}")
    #print(f"rice time {data[np.argmax(rice_time),0]} ;-D ")
    print(f"y sttl time {data[index,0]}")
    y_sttl_times.append(data[index,0])
##plt.show()

#xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
x_sttl_times = []
fig, ax = plt.subplots(3)
ax[0].set_title("X axis setling time")
for data in step_data_x:
    
    data[:,0] = data[:,0] - np.ones_like(data[:,0])*data[0,0]

    ax[0].plot(data[:,0],data[:,1])
    ax[0].plot(data[:,0],data[:,7])
    error = np.abs(data[:,7]-data[:,1])
    settling_point = np.ones_like(error)*(data[0,7]-data[0,1])*0.05 
    ax[1].plot(data[:,0],error)
    ax[1].plot(data[:,0],settling_point)
    rice_time = error < (data[0,7]-data[0,1])*0.63
    index = 0
    
    within_range = np.zeros_like(error)
    within_range[index+1:-1] = error[index+1:-1] < (data[0,7]-data[0,1])*0.05
    lb_data, num_features = label(within_range)

    ax[2].plot(data[:,0],lb_data)
    #print(f"dips {np.max(lb_data)}")

    crossovers = np.max(lb_data)

    last_within_range=lb_data==crossovers
    index = np.argmax(last_within_range)

    #print(f"index out {index}")
    
    #print(f"index {index}")
    #print(f"rice time {data[np.argmax(rice_time),0]} ;-D ")
    print(f"x sttl time {data[index,0]}")
    x_sttl_times.append(data[index,0])
#plt.show()

x_trj_data = []
y_trj_data = []
z_trj_data = []
fig, ax = plt.subplots(3)
for filepath in os.scandir("Data fra tests/settling time trj"):
    data = np.loadtxt(filepath.path)
    trj_data.append(np.loadtxt(filepath.path))
    print(f"fn {filepath} length {np.loadtxt(filepath.path).shape}")
    id_arr = np.arange(data.shape[0])
    ax[0].plot(id_arr,data[:,1])
    ax[1].plot(id_arr,data[:,2])
    ax[2].plot(id_arr,data[:,3])
    x_trj_data.append(data[200:400,:])
    y_trj_data.append(data[400:600,:])
    z_trj_data.append(data[600:840,:])

x_trj_sttl_time=[]
fig, ax = plt.subplots(3)
ax[0].set_title("X-axis Settling Time with Trajectory")
for data in x_trj_data:
    ref_index = 7
    pos_index = 1
    start_time = data[0,0]
    time_arr = data[:,0]-np.ones_like(data[:,0])*start_time
    start_ref_pos = data[0,7]
    end_ref_pos = data[-1,7]
    error = np.abs(np.ones_like(data[:,0])*end_ref_pos - data[:,pos_index])
    within_range = error < (end_ref_pos-start_ref_pos)*0.05

    lb_data, num_features = label(within_range)

    sttl_point = np.argmax(lb_data==np.max(lb_data))
    
    x_trj_sttl_time.append(time_arr[sttl_point])
    ax[0].plot(time_arr, data[:,pos_index])
    ax[0].plot(time_arr, data[:,ref_index])
    ax[0].plot(time_arr, np.ones_like(data[:,0])*end_ref_pos)

    ax[1].plot(time_arr, error)
    ax[1].plot(time_arr, np.ones_like(time_arr)*(end_ref_pos-start_ref_pos)*0.05)

    ax[2].plot(time_arr, lb_data)

y_trj_sttl_time=[]
fig, ax = plt.subplots(3)
ax[0].set_title("Y-axis Settling Time with Trajectory")
for data in y_trj_data:
    ref_index = 8
    pos_index = 2
    start_time = data[0,0]
    time_arr = data[:,0]-np.ones_like(data[:,0])*start_time
    start_ref_pos = data[0,ref_index]
    end_ref_pos = data[-1,pos_index]
    error = np.abs(np.ones_like(data[:,0])*end_ref_pos - data[:,pos_index])
    within_range = error < (end_ref_pos-start_ref_pos)*0.05

    lb_data, num_features = label(within_range)

    sttl_point = np.argmax(lb_data==np.max(lb_data))
    
    y_trj_sttl_time.append(time_arr[sttl_point])
    ax[0].plot(time_arr, data[:,pos_index])
    ax[0].plot(time_arr, data[:,ref_index])
    ax[0].plot(time_arr, np.ones_like(data[:,0])*end_ref_pos)

    ax[1].plot(time_arr, error)
    ax[1].plot(time_arr, np.ones_like(time_arr)*(end_ref_pos-start_ref_pos)*0.05)

    ax[2].plot(time_arr, lb_data)


z_trj_sttl_time=[]
fig, ax = plt.subplots(3)
ax[0].set_title("Z-axis Settling Time with Trajectory")
for data in z_trj_data:
    ref_index = 9
    pos_index = 3
    start_time = data[0,0]
    time_arr = data[:,0]-np.ones_like(data[:,0])*start_time
    start_ref_pos = data[0,ref_index]
    end_ref_pos = data[-1,pos_index]
    error = np.abs(np.ones_like(data[:,0])*end_ref_pos - data[:,pos_index])
    within_range = error < (end_ref_pos-start_ref_pos)*0.05

    lb_data, num_features = label(within_range)

    sttl_point = np.argmax(lb_data==np.max(lb_data))
    
    z_trj_sttl_time.append(time_arr[sttl_point])
    ax[0].plot(time_arr, data[:,pos_index])
    ax[0].plot(time_arr, data[:,ref_index])
    ax[0].plot(time_arr, np.ones_like(data[:,0])*end_ref_pos)
    ax[0].set_ylabel("Position [mm]")

    ax[1].plot(time_arr, error)
    ax[1].plot(time_arr, np.ones_like(time_arr)*(end_ref_pos-start_ref_pos)*0.05)
    ax[1].set_ylabel("Error [mm]")

    ax[2].plot(time_arr, lb_data)
    ax[2].set_ylabel("Error crossover \ncount ")
    ax[2].set_xlabel("Time [s]")


sttl_times = []


sttl_times.append(x_sttl_times)
sttl_times.append(y_sttl_times)
sttl_times.append(z_sttl_times)

sttl_times.append(x_trj_sttl_time)
sttl_times.append(y_trj_sttl_time)
sttl_times.append(z_trj_sttl_time)

print(np.array(sttl_times).shape)
print(np.array(sttl_times).T)
print(np.mean(np.array(sttl_times),1))

fig,ax = plt.subplots()
c1 = "lightblue"
c2 = "pink"
ax.bar(["x_s","y_s","z_s","x_t","y_t","z_t"], np.mean(np.array(sttl_times),1), color = [c1,c1,c1,c2,c2,c2])
ax.set_ylabel("Mean settling time")
ax.set_xlabel("Test")


plt.show() 
    
    


plt.show()