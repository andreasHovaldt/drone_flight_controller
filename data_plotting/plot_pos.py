import numpy as np 
import matplotlib.pyplot as plt


data = np.loadtxt("trj_data_hover_accu6.txt")

print(f"trj shape {data.shape}")

time_array = data[:,0]
pos_array = data[:,1:4]
ref_array =  data[:,7:10]

plt.plot(time_array, ref_array, label = ["x-ref","y-ref","z-ref"])
plt.plot(time_array, pos_array, label = ["x-pos","y-pos","z-pos"])
plt.legend()

plt.show()
pz = pos_array[:,2]
py = pos_array[:,1]
px = pos_array[:,0]

rz = ref_array[:,2]
ry = ref_array[:,1]
rx = ref_array[:,0]

ax = plt.figure().add_subplot(projection='3d')

ax.plot(px, py, pz, label='pos curve')
ax.plot(rx, ry, rz, label='ref curve')
ax.legend("x", "y", "z")

plt.show()
