import numpy as np 
from matplotlib.figure import Figure
import matplotlib.pyplot as plt


data = np.loadtxt("hover_step_bad.txt")

print(f"trj shape {data.shape}")


fig = plt.figure()

ax = fig.add_subplot()

time_array = data[:,0]
pos_array = data[:,1]
ref_array =  data[:,2]

ax.plot(time_array, ref_array, label = "Z-reference")
ax.plot(time_array, pos_array, label = "Vicon Z-value")

ax.set_xlabel('Time [s]')
ax.set_ylabel('Height [mm]')
ax.set_title('Z Step Response')

ax.legend()

#ax.imshow()

plt.show()