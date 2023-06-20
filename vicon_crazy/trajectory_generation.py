import numpy as np
import math


class Trajectory:
    def __init__(self,start_origin, np_point_array):
        
        # forskyder alle datapunkter med start position
        self.waypoints = np_point_array + np.ones_like(np_point_array)*start_origin

        self.number_of_points = np_point_array.shape[0]
        self.distance_array = []
        self.time_array = []
        self.cubic_func_data = []

        #adjust speed 
        self.time_per_mm = 0.002
        self.extra_time_per_section = 1

        #we go thrugh each waypoint and the next weypoint, first findinf the distance and then estimate the time i should take based on the distance 
        #we then find a0, a1, a2, and a3 as in craig to describe the polynomial 
        for start_point, end_point in zip(self.waypoints[0:], self.waypoints[1:]):
            distance =  math.sqrt(sum((end_point-start_point)**2)) #find the euclidian distance
            
            # Calculate time for this specific section
            section_time = distance * self.time_per_mm + self.extra_time_per_section

           

            start_speed = np.array([0, 0, 0]) 
            end_speed   = np.array([0, 0, 0])

            # Following equations are used to calculate the cubic polynomials used for the trajectory 
            # They are based on Craig section 7.1 
            a2 = ((3)/((section_time)**2))*(end_point-start_point)-(2/(section_time))*start_speed-(1/(section_time))*end_speed
            a3 = -((2)/((section_time)**3))*(end_point - start_point)+(1/((section_time)**2))*(end_speed+start_speed)
            
            cubic_data = [start_point, start_speed, a2, a3]
            self.cubic_func_data.append(cubic_data)    

            self.time_array.append(section_time)
            self.distance_array.append(distance)
        
        #we convert the data lists to np arrays to make the data easier to acsess in multidimensional order 
        self.cubic_func_data = np.array(self.cubic_func_data)
        self.time_array      = np.array(self.time_array)
        self.distance_array  = np.array(self.distance_array)
        self.cum_time        = np.insert(np.cumsum(self.time_array),0,0)

        #print(self.cubic_func_data.shape)

    def get_position(self, time_seconds):
        '''
        get_position, returns the position in np (x,y,z) of the trajectory for the time given
        '''
        #first we must find the cubic data depending on the time 
        
        if time_seconds >= self.cum_time[-1]:
            
            position = self.waypoints[-1]

        else:
            section = np.argmax(time_seconds < self.cum_time) #argmax finds the index for the section cubic data 
            
            #finds the a0, a1, a2 and a3 for the cubic function 
            cubic_data = self.cubic_func_data[section-1,:,:]
            
            section_start_time = self.cum_time[section-1]

            section_time = time_seconds-section_start_time

            #Finds position from the cubic function from Craig 
            position = cubic_data[0,:] + cubic_data[1,:] * section_time+cubic_data[2,:]*section_time**2 + cubic_data[3,:]*section_time**3
        return(position)


        #print(self.distance_array)

    def get_number_of_points(self):
        return self.number_of_points
    
    def get_total_time(self):
        return sum(self.time_array)
    
    def get_time_array(self):
        return self.time_array
    
    def get_distance_array(self):
        return self.distance_array

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