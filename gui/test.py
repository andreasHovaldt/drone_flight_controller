# import numpy as np

# traj_points_x = [1000, 750, 0, -750, -1000]
# traj_points_y = [1000, 250, 0, -250, -1000]
# traj_points_z = [1000, 500, 500, -500, -1000]

# #print(list(zip(traj_points_x,traj_points_y,traj_points_z)))

# #print(list(range(0,len(traj_points_x))))

# traj_points_x = [1000, 930, 750, 375, 0, -375, -750, -875, -1000, -300, 0, 0, 500, 500, 400, -750]
# traj_points_y = [1000, 500, 250, 125, 0, -125, -250, -680, -1000, -1000, -700, -400, 500, 600, 700, 750]
# traj_points_z = [1000, 750, 500, 500, 500, -250, -500, -750, -1000, -700, -600, -600, -500, -500, -400, 0]
# data = np.array(list(zip(traj_points_x,traj_points_y,traj_points_z)))
# #print(data)

# #print(data[0])
# #print(list(range(0,len(data))))

# pts_index = list(range(0,len(data)))
# #print(list(zip(pts_index,data)))
# #print(data)
# #print(np.flip(data,1))
# #print(f"y-values: {data[0:,1]}")




# print(data)
# print("---------------------------")
# #data = np.append(data,[[69],[69],[69]])
# data = np.append(data.copy(),[[69,69,69]],axis=0)
# print(data)


import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk  
import numpy as np

class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self,master)
        self.createWidgets()

    def createWidgets(self):
        fig=plt.figure(figsize=(8,8))
        ax=fig.add_axes([0.1,0.1,0.8,0.8],polar=True)
        canvas=FigureCanvasTkAgg(fig,master=root)
        canvas.get_tk_widget().grid(row=0,column=1)
        canvas.draw()

        self.plotbutton=tk.Button(master=root, text="plot", command=lambda: self.plot(canvas,ax))
        self.plotbutton.grid(row=0,column=0)

    def plot(self,canvas,ax):
        c = ['r','b','g']  # plot marker colors
        ax.clear()         # clear axes from previous plot
        for i in range(3):
            theta = np.random.uniform(0,360,10)
            r = np.random.uniform(0,1,10)
            ax.plot(theta,r,linestyle="None",marker='o', color=c[i])
            canvas.draw()

root=tk.Tk()
app=Application(master=root)
app.mainloop()