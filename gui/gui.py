import tkinter as tk
from tkinter import ttk

from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)

from matplotlib.figure import Figure
from matplotlib.backend_bases import key_press_handler

import numpy as np
import time, random, winsound
from threading import Thread



traj_points_x = [1000, 930, 750, 375, 0, -375, -750, -875, -1000, -300, 0, 0, 500, 500, 400, -750]
traj_points_y = [1000, 500, 250, 125, 0, -125, -250, -680, -1000, -1000, -700, -400, 500, 600, 700, 750]
traj_points_z = [1000, 750, 500, 500, 500, -250, -500, -750, -1000, -700, -600, -600, -500, -500, -400, 0]
data = np.array(list(zip(traj_points_x,traj_points_y,traj_points_z)))


def establish_connection(): #TODO: fix empty function
    print("Establishing connection to the Crazyflie!")
    time.sleep(1)
    randBool = random.choice([True, False])
    print(f"Connection {randBool} [WIP]")
    
    return randBool


def run_trajectory_flight(): #TODO: fix empty function
    print("Flying set trajectory...")
    time.sleep(2)
    print("Done flying! [WIP]")


def shutoff_motors(): #TODO: fix empty function
    print("Shutting off motors...")
    time.sleep(1)
    print("CrazyFlie has been put to sleep [WIP]")




class gui(tk.Tk):
    def __init__(self, root=None):
        super().__init__()
        
        self.root = root
        
        self.title("CrazyFlie Flight GUI")
        #self.geometry("1300x1000")
        self.resizable(width=False, height=False)
        self.iconphoto(False, tk.PhotoImage(file="gui\icon.png"))
        
        
        # Root title
        title_label = tk.Label(master=root,font=("Arial", 30, "bold underline"),text="CrazyFlie Flight GUI")
        title_label.grid(row=0,column=0,sticky=tk.W,padx=10)
        
        
        # Connection
        connection_frame = self.crazyflie_connection()
        connection_frame.grid(row=1,column=0,padx=10,pady=10,sticky=tk.W)
        
        
        # Controller
        controller_frame = self.crazyflie_controller()
        controller_frame.grid(row=2,column=0,padx=10,pady=10,sticky=tk.W)
        
        
        # Trajectory generation
        traj_frame = self.trajectory_gen()
        traj_frame.grid(row=6,column=0,sticky=tk.W,padx=10)
        
        
        # Trajectory 3D plot
        traj_plot = self.trajectory_plot()
        traj_plot.grid(row=1,column=1,rowspan=6,padx=10,pady=[0,10])
        
    
    
    def crazyflie_connection(self):
        def connection_helper_function(label):
            status = establish_connection()
            if status == True:
                label["text"] = "Connection success!"
            else:
                label["text"] = "Connection failure!"
        
        current_frame = tk.LabelFrame(text="CrazyFlie connection status", font=("Arial", 22, "underline"), padx=10, pady=10)
        
        
        # Connect button
        connect_btn = tk.Button(master=current_frame,font=("Arial", 12),text="Connect",command= lambda: connection_helper_function(status_label))
        connect_btn.grid(row=0,column=0)
        
        
        status_txt_label = tk.Label(master=current_frame,font=("Arial", 12),text="Status:")
        status_txt_label.grid(row=0,column=1,padx=[25,0])
        status_label = tk.Label(master=current_frame,font=("Arial", 12),text="Disconnected...")
        status_label.grid(row=0,column=2)
        
        
        return current_frame
    
    
    def crazyflie_controller(self):
        current_frame = tk.LabelFrame(text="CrazyFlie Controller", font=("Arial", 22, "underline"), padx=10, pady=10)
        
        
        ### Run current trajectory txt + button 
        run_traj_label = tk.Label(master=current_frame,font=("Arial", 16),text="Run current trajectory:")
        run_traj_label.grid(row=0,column=0,padx=[25,0])
        run_traj_btn = tk.Button(master=current_frame,font=("Arial", 12),text="Start",command= lambda: run_trajectory_flight())
        run_traj_btn.grid(row=0,column=1,padx=20,pady=10)
        
        
        ### Shut off Crazyflie motors txt + button 
        shutoff_label = tk.Label(master=current_frame,font=("Arial", 16),text="Shut-off motors:")
        shutoff_label.grid(row=1,column=0,padx=[25,0])
        shutoff_btn = tk.Button(master=current_frame,font=("Arial", 12),text="Stop",command= lambda: shutoff_motors())
        shutoff_btn.grid(row=1,column=1,padx=20)
        
        
        return current_frame
    
    
    def trajectory_gen(self):
        # Declare function for updating a treeview
        def update_treeview(treeview_object: ttk.Treeview):
            # Clear treeview
            treeview_object.delete(*treeview_object.get_children())
            
            # Insert waypoint entries
            pts_index = range(0,len(data))
            for pts in zip(pts_index,data[0:,0],data[0:,1],data[0:,2]): # Extracting x, y, z from data array
                treeview_object.insert(parent="",index="end", values=pts)
        
        # Declare function for adding new waypoint entries
        def add_entry(treeview_object: ttk.Treeview):
            # Append the entered data to global waypoint array
            global data
            data = np.append(data.copy(),[[int(new_x_var.get()),int(new_y_var.get()),int(new_z_var.get())]],axis=0)
            
            #print(data)
            
            # Update the treeview with the new waypoint
            update_treeview(treeview_object)
            
            # Delete entered waypoint coordinates
            x_entry.delete(0,"end")
            y_entry.delete(0,"end")
            z_entry.delete(0,"end")
            
        # Declare function for deleting a treeview entry
        def delete_entry(treeview_object: ttk.Treeview):
            # Get details of selected entry
            selected_entry = treeview_object.focus()
            entry_details = treeview_object.item(selected_entry)
            
            if selected_entry == "":
                # Play windows error sound if no entry is selected
                winsound.PlaySound("SystemExclamation", winsound.SND_ASYNC)
            else:
                # Remove entry from data
                global data
                data = np.delete(data.copy(),entry_details["values"][0],0)
                
                # Remove entry from treeview
                treeview_object.delete(selected_entry)
                
                # Update treeview
                update_treeview(treeview_object)
        
        
        # Define current frame
        current_frame = tk.LabelFrame(text="Trajectory Generation", font=("Arial", 22, "underline"), padx=10, pady=10)
        
        
        ##### Point list
        # Create treeview
        treeview = ttk.Treeview(master=current_frame,height=10)
        
        # Define header of treeview
        data_header = ["Waypoint #","X","Y","Z"]
        treeview["columns"] = data_header
        
        # Removes index column to the left
        treeview.column("#0", width=0, stretch=tk.NO)
        treeview.heading("#0",text="",anchor=tk.CENTER)
        
        # Set properties for each heading 
        for name in data_header:
            treeview.column(name,anchor=tk.CENTER, width=80)
            treeview.heading(name,text=name,anchor=tk.CENTER)
        
        # Update treeview data when frame is created
        update_treeview(treeview)
        
        # Pack the treeview into current_frame
        treeview.grid(row=1,column=0,rowspan=12)
        
        
        ### New waypoint entry
        new_waypoint_frame = tk.Frame(master=current_frame)
        
        # X entry
        x_label = tk.Label(master=new_waypoint_frame,font=("Arial", 12),text="X: ")
        new_x_var = tk.StringVar() # Creating tkinter variable which can be read
        x_entry = tk.Entry(master=new_waypoint_frame,font=("Arial", 12),textvariable=new_x_var,width=8)
        x_label.grid(row=0,column=0,pady=5)
        x_entry.grid(row=0,column=1,pady=5)
        
        # Y entry
        y_label = tk.Label(master=new_waypoint_frame,font=("Arial", 12),text="Y: ")
        new_y_var = tk.StringVar() # Creating tkinter variable which can be read
        y_entry = tk.Entry(master=new_waypoint_frame,font=("Arial", 12),textvariable=new_y_var,width=8)
        y_label.grid(row=1,column=0,pady=5)
        y_entry.grid(row=1,column=1,pady=5)
        
        # Z entry
        z_label = tk.Label(master=new_waypoint_frame,font=("Arial", 12),text="Z: ")
        new_z_var = tk.StringVar() # Creating tkinter variable which can be read
        z_entry = tk.Entry(master=new_waypoint_frame,font=("Arial", 12),textvariable=new_z_var,width=8)
        z_label.grid(row=2,column=0,pady=5)
        z_entry.grid(row=2,column=1,pady=5)
        
        # Place XYZ entries into their master frame
        new_waypoint_frame.grid(row=1,column=1,rowspan=8)
        
        
        ##### Treeview buttons
        # Create buttons under treeview
        treeview_add = tk.Button(master=current_frame,font=("Arial",12),text="Add new waypoint",command=lambda: add_entry(treeview))
        treeview_add.grid(row=10,column=1,padx=(10,0))
        
        treeview_delete = tk.Button(master=current_frame,font=("Arial",12),text="Delete Selected",command=lambda: delete_entry(treeview))
        treeview_delete.grid(row=11,column=1,padx=(10,0))
        
        treeview_update = tk.Button(master=current_frame,font=("Arial",12),text="Update table",command=lambda: update_treeview(treeview))
        treeview_update.grid(row=12,column=1,padx=(10,0))
        
        
        return current_frame
    
    
    def trajectory_plot(self):
        #current_frame = tk.Frame()
        current_frame = tk.LabelFrame(text="Trajectory 3D Plot", font=("Arial", 22, "underline"), padx=10, pady=10)
        #title
        
        
        ### Creating matplotlib plot
        fig = Figure(figsize=(8,6),tight_layout=True)
        ax = fig.add_subplot(projection="3d")
        
        ax.set_xlabel('X Pos [mm]')
        ax.set_ylabel('Y Pos [mm]')
        ax.set_zlabel('Z Pos [mm]')

        ### Creating tkinter plot/graph canvas
        figure_canvas = FigureCanvasTkAgg(fig, master=current_frame)  # A tk.DrawingArea.
        figure_canvas.draw()

        
        ### Matplotlib toolbar
        # pack_toolbar=False will make it easier to use a layout manager later on.
        # toolbar = NavigationToolbar2Tk(figure_canvas, current_frame, pack_toolbar=False)
        # toolbar.update()

        # figure_canvas.mpl_connect(
        #     "key_press_event", lambda event: print(f"you pressed {event.key}"))
        # figure_canvas.mpl_connect("key_press_event", key_press_handler)
        
        #toolbar.pack(side=tk.BOTTOM, fill=tk.X)
        
        
        ### Packing figure onto its master frame (current_frame)
        figure_canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
        
        
        ### Update 3D plot
        def update_plot(canvas,ax):
            global data
            
            # Clear plot
            ax.clear()
            
            # Plot all points
            ax.scatter(data[0:,0],data[0:,1],data[0:,2])
            
            # Plot lines between each point
            ax.plot(data[0:,0],data[0:,1],data[0:,2])
            
            # Plot labels to each point
            pts_index = range(0,len(data))
            for x, y, z, label in zip(data[0:,0],data[0:,1],data[0:,2], pts_index):
                ax.text(x, y, z, label)
            
            # Update plot
            canvas.draw()
        
        update_canvas_btn = tk.Button(master=current_frame,font=("Arial",12),text="Update 3D plot",command=lambda: update_plot(figure_canvas,ax))
        update_canvas_btn.pack(pady=[10,0])
        
        return current_frame
        
        
    

##### Thread testing

def tk_loop():
    gui_object = gui()
    gui_object.mainloop()


def external_loop():
    curr_count = 0
    while curr_count < 10:
        curr_count += 1
        print(f"External loop response {curr_count}")
        time.sleep(1)
        

    
##### Main code

if __name__ == "__main__":
    tk_thread = Thread(target=tk_loop)
    tk_thread.start()
    
    # external_thread = Thread(target=external_loop)
    # external_thread.start()
    