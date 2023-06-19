import numpy as np 
import matplotlib.pyplot as plt


data = np.loadtxt("trj_data.txt")

print(f"trj shape {data.shape}")

time_array = data[:,0]
pos_array = data[:,1:4]
ref_array =  data[:,7:10]

plt.plot(time_array, ref_array, label = "ref")
plt.plot(time_array, pos_array, label = "pos")
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
ax.legend()

plt.show()
