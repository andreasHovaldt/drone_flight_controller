import cflib.crtp
from cflib.crazyflie import Crazyflie
import logging

class Crazyflie_link:

    def __init__(self,URI = None):
        # Set default value if URI is not specified
        self.URI = 'radio://0/80/2M' if not URI else URI

        # Initiate CF drivers
        cflib.crtp.init_drivers()

        # Start logging
        logging.basicConfig(level=logging.ERROR)

        # Make instance of crazyflie class & setup folder path for Crazyflie logs
        self.cf = Crazyflie(rw_cache='./cache')

    def send_start_setpoint(self):
        '''
        This function establishes the connection between
        the Crazyflie drone and the python script. \n
        After the connection is established, the motors 
        are unlocked so the CF is ready to fly.
        '''
        self.cf.open_link(self.URI)
        
        # Unlocks motors
        self.cf.commander.send_setpoint(0,0,0,0) # (R,P,Y-rate, T)

    def send_setpoint(self, RPYT_array):
        '''
        Sends new RPYT command to the Crazyflie
        '''
        self.cf.commander.send_setpoint(RPYT_array[0], RPYT_array[1], RPYT_array[2], RPYT_array[3])

    def send_stop_setpoint(self):
        '''
        Stop motors and close link.
        '''
        self.cf.commander.send_stop_setpoint()
        self.cf.close_link()