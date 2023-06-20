import numpy as np
import matplotlib.pyplot as plt 
import matplotlib as mpl 
import os
from scipy import stats
data = []

for filename in os.scandir("data"):
    data.append(np.loadtxt(filename.path)[:,:])
    print(f"{filename}, {np.loadtxt(filename.path).shape}")



fig, axs = plt.subplots(3)

sv = 10


means = []
x_means =[]
y_means =[]
z_means =[]
means.append(x_means)
means.append(y_means)
means.append(z_means)

stds = []
x_stds =[]
y_stds =[]
z_stds =[]
stds.append(x_stds)
stds.append(y_stds)
stds.append(z_stds)

list_data = {"0":[], "1":[], "2":[]}
titels = ["x","y","z"]
cm = mpl._cm_listed._plasma_data
print(np.array(cm).shape)
print(np.array(data).shape)
for sample, nc in zip(data, range(10)):
    axis_means = []
    axis_stds = []
    c = cm[nc*24]
    for axis, axis_means, axis_stds in zip(range(3), means, stds):
        #print(f"axis {axis}, arr{axis_means}")
        axs[axis].plot(sample[:,0], sample[:,axis+1])
        axs[axis].plot(sample[:,0], sample[:,axis+7],color = "maroon")
        axs[axis].set_ylabel(f"position {titels[axis]} [mm]")
        axs[axis].set_xlabel("time [s]")
        print(f"axis{axis}, std {np.std(sample[:,axis+1])}")
        axis_means.append(np.mean(sample[:,axis+1]))
        axis_stds.append ( np.std(sample[:,axis+1]))
        list_data[f"{axis}"] = list_data[f"{axis}"] + sample[:,axis+1].tolist()
    
    

    means.append(axis_means)
    stds.append(axis_stds)

for axis_mean, axis_std, axis_list in zip(means,stds,list_data):
    mean = np.mean(np.array(axis_mean))
    std = np.mean(np.array(axis_std))
    print(f"axis, {mean}, {std}")



#print(list_data)
print(np.array(means).shape)
print(np.array(stds).shape)

#plt.show()
plt.rcParams.update({'font.size': 16})
fig, axs = plt.subplots(2, 3)
titels = ["x","y","z"]
wanted_means = [0,0,1000]
for axis in range(3):
    axdata = np.array(list_data[f"{axis}"])
    axs[1,axis].hist(axdata,50,density = True ,color = "tab:green", alpha = 0.2)
    axs[1,axis].set_xlabel(f"Postion {titels[axis]}-axis [mm]")
    #axs[axis].set_ylabel(f"axis {titels[axis]}")
    
    np_means = np.array(means)
    np_stds = np.array(stds)


    mean = np.mean(np.array(np_means[axis,:]))
    std = np.mean(np.array(np_stds[axis,:]))
    x_space = np.arange(axdata.min()-20,axdata.max()+20,0.1)
    norm_pdf = stats.norm.pdf(x_space,mean,std)
    norm_pdf2 = stats.norm.pdf(x_space,wanted_means[axis],10)
    axs[1,axis].plot(x_space,norm_pdf,linewidth=1)
    axs[1,axis].plot(x_space,norm_pdf2,linewidth=1)
    
    axs[1,axis].fill_between(x_space , norm_pdf,alpha=0.2, )
    axs[1,axis].fill_between(x_space , norm_pdf2,alpha=0.2, )

#fig, axs = plt.subplots(1,3)
titels = ["x","y","z"]
wanted_means = [0,0,1000]
for axis in range(3):
    axdata = np.array(list_data[f"{axis}"])
    axs[0,axis].hist(axdata,50 ,color = "tab:green", alpha = 0.2)
    axs[0,axis].set_xlabel(f"Postion {titels[axis]}-axis [mm]")
axs[0,0].set_ylabel(f"Count")
axs[1,0].set_ylabel(f"Probability")    
    #axs[axis].set_ylabel(f"axis {titels[axis]}")
    


errors = np.array([0,0,0])
points = 0
for tdata in data:
    pos_data = tdata[:,1:4]
    ref_data= np.ones_like(pos_data)*[0,0,1000]

    error = np.abs(pos_data-ref_data)
    errors += np.sum(error > 20,0)
    points += error.shape[0]

print((1-(errors/points))*100)




#plt.show()
    #list_data = list_data + sample.tolist()
#print(f"means {means}")
#print(f"stds {stds}")

#print(f"total mean {np.mean(np.array(list_data))}")
#plt.show()


#all_data = np.array(list_data)

#print(f"list_data {list_data}")
plt.show()