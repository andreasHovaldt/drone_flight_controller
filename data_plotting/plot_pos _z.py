import numpy as np 
from matplotlib.figure import Figure
import matplotlib.pyplot as plt
import matplotlib as mpl
from matplotlib.colors import ListedColormap, LinearSegmentedColormap
import os

data_list = []
for filepath in os.scandir('./Data fra tests/Z-overshoot'):
    data_list.append(np.loadtxt(filepath.path))


data_number = 1
fig, ax = plt.subplots()
for data in data_list:

    time_array = data[:,0]
    pos_array = data[:,1]
    ref_array =  data[:,2]

    pos_array -= data[0,1]
    ref_array = ref_array - (ref_array[0]-1000)  #data[0,2] - (data[0,2] - 1000)
    time_array -= data[0,0]

    # print(max(pos_array))

    ax.plot(time_array, pos_array, label = f"Vicon Z-value - {data_number}")
    data_number += 1


c = "maroon"
ax.plot([0,0],[0,1000], color = c)
ax.plot(time_array, ref_array, label = "Z-reference", color = c)
ax.set_xlabel('Time [s]')
ax.set_ylabel('Height [mm]')
ax.set_title('Z Step Response')

# ax.legend()

#ax.imshow()

plt.show()