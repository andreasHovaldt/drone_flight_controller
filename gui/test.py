import numpy as np

traj_points_x = [1000, 750, 0, -750, -1000]
traj_points_y = [1000, 250, 0, -250, -1000]
traj_points_z = [1000, 500, 500, -500, -1000]

#print(list(zip(traj_points_x,traj_points_y,traj_points_z)))

#print(list(range(0,len(traj_points_x))))

traj_points_x = [1000, 930, 750, 375, 0, -375, -750, -875, -1000, -300, 0, 0, 500, 500, 400, -750]
traj_points_y = [1000, 500, 250, 125, 0, -125, -250, -680, -1000, -1000, -700, -400, 500, 600, 700, 750]
traj_points_z = [1000, 750, 500, 500, 500, -250, -500, -750, -1000, -700, -600, -600, -500, -500, -400, 0]
data = np.array(list(zip(traj_points_x,traj_points_y,traj_points_z)))
#print(data)

#print(data[0])
#print(list(range(0,len(data))))

pts_index = list(range(0,len(data)))
#print(list(zip(pts_index,data)))
#print(data)
#print(np.flip(data,1))
#print(f"y-values: {data[0:,1]}")




print(data)
print("---------------------------")
#data = np.append(data,[[69],[69],[69]])
data = np.append(data.copy(),[[69,69,69]],axis=0)
print(data)