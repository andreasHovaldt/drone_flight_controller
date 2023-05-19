import numpy as np 
from matplotlib.figure import Figure
import matplotlib.pyplot as plt


data = np.loadtxt("PID_40_6_15.txt")

print(f"trj shape {data.shape}")


fig = plt.figure()

ax = fig.add_subplot()

time_array = data[:,0]
pos_array = data[:,1]
ref_array =  data[:,2]

ax.plot(time_array, ref_array, label = "Z-reference")
ax.plot(time_array, pos_array, label = "Vicon Z-position")

ax.set_xlabel('Time [s]')
ax.set_ylabel('Position [mm]')
ax.set_title('Z Position')

ax.legend()

#ax.imshow()

plt.show()