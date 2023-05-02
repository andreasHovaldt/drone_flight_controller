import numpy as np
import math


class Trajectory:
    def __init__(self, np_point_array):
        self.waypoints = np_point_array
        self.number_of_points = np_point_array.shape[0]
        self.distance_array = []
        self.time_array = []
        self.cubic_func_data = []

        for start_point, end_point in zip(self.waypoints[0:], self.waypoints[1:]):
            distance =  math.sqrt(sum((end_point-start_point)**2))
            section_time = distance*0.004+1
            #print(f"start point{start_point}, end point {end_point} ,distance {math.sqrt(sum((end_point-start_point)**2))}")
            

            start_speed = np.array([0, 0, 0]) 
            end_speed   = np.array([0, 0, 0])

            a2 = ((3)/((section_time)**2))*(end_point-start_point)-(2/(section_time))*start_speed-(1/(section_time))*end_speed
            a3 = -((2)/((section_time)**3))*(end_point - start_point)+(1/((section_time)**2))*(end_speed+start_speed)
            cubic_data = [start_point, start_speed, a2, a3]
            self.cubic_func_data.append(cubic_data)    

            self.time_array.append(section_time)
            self.distance_array.append(distance)
        
        self.cubic_func_data = np.array(self.cubic_func_data)
        self.time_array      = np.array(self.time_array)
        self.distance_array  = np.array(self.distance_array)
        self.cum_time        = np.insert(np.cumsum(self.time_array),0,0)

        #print(self.cubic_func_data.shape)

    def get_position(self, time_seconds):
        #first we must find the cubic data depending on the time 
        
        if time_seconds >= self.cum_time[-1]:
            
            position = self.waypoints[-1]

        else:
            section = np.argmax(time_seconds < self.cum_time)
            cubic_data = self.cubic_func_data[section-1,:,:]
            
            section_start_time = self.cum_time[section-1]
            section_time = time_seconds-section_start_time
        
            position = cubic_data[0,:] + cubic_data[1,:] * section_time+cubic_data[2,:]*section_time**2 + cubic_data[3,:]*section_time**3
        return(position)


        #print(self.distance_array)

    def get_number_of_points(self):
        return self.number_of_points
    
    def get_total_time(self):
        return sum(self.time_array)

if __name__ == "__main__":
    point_array = np.random.random((10,3))*1000
    point_array[0,:] = [0,0,0]
    print(point_array)
    my_trj = Trajectory(point_array)
    time_space = np.arange(0,my_trj.cum_time[-1]+10, 0.1)
    trj_out = []
    for time in time_space:
        trj_out.append(my_trj.get_position(time))
    print(np.array(trj_out))

    #print(my_trj.cum_time)
    #print(my_trj.time_array)