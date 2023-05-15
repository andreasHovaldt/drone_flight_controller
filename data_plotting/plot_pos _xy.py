import numpy as np 
from matplotlib.figure import Figure
import matplotlib.pyplot as plt


data = np.loadtxt("trj_data_hover_accu.txt")

print(f"trj shape {data.shape}")


fig = plt.figure()

ax = fig.add_subplot()

time_array = data[:,0]
pos_array = data[:,1:3]
ref_array =  data[:,7:9]

ax.plot(time_array, ref_array, label = ["X-reference","Y-reference"])
ax.plot(time_array, pos_array, label = ["Vicon X-position", "Vicon Y-position"])

ax.set_xlabel('Time [s]')
ax.set_ylabel('Position [mm]')
ax.set_title('XY Position')

ax.legend()

#ax.imshow()

plt.show()