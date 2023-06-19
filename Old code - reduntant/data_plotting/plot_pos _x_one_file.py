import numpy as np 
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib.colors import ListedColormap, LinearSegmentedColormap
import os

data = np.loadtxt("/Users/mortenstephansen/Desktop/Projects/drone_flight_controller/Data fra tests/Settling Time/settling_time_step_x1.txt")
# for filepath in os.scandir(''):
#     data_list.append(np.loadtxt(filepath.path))



fig, ax = plt.subplots()

time_array = data[:,0]
pos_array = data[:,1]
ref_array = data[:,7]

pos_array -= data[0,1]
ref_array = ref_array - (ref_array[0]-1000)  #data[0,2] - (data[0,2] - 1000)
time_array -= data[0,0]

# print(max(pos_array))

ax.plot(time_array, pos_array, label = f"Vicon X-value")


c = "maroon"
ax.plot([0,0],[0,1000], color = c)
ax.plot(time_array, ref_array, label = ["X-reference", "Y-reference"], color = c)
ax.set_xlabel('Time [s]')
ax.set_ylabel('Position [mm]')
ax.set_title('X Step Response')

ax.legend()

#ax.imshow()

plt.show()