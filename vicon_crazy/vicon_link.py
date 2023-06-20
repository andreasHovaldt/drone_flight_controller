import socket
import time
import struct
import numpy as np

class viconUDP:

    # Computer - IP and VICON port
    def __init__(self,ip = '0.0.0.0',port = 51001):
        self.time_start = time.time()

        # Websocket setup
        self.in_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.in_sock.bind((ip, port))
        #print('Connected to vicon')

    def getPosRot(self):
        data, addr = self.in_sock.recvfrom(1024) # buffer size is 1024 bytes

        # We know from the vicon documentation that bytes 32-39 is translation along X and so on, in 8 bytes intervals (as double is 8 bytes)
        pos = [struct.unpack_from('d', data, 32+i*8)[0] for i in range(3)]
        rot = [struct.unpack_from('d', data, 56+i*8)[0] for i in range(3)]

        return pos,rot

    def getTimestampedData(self,unix_time = False):
        """
        Get Vicon data with timestamp
        Args:
            unix_time (bool) : Save timestamp as raw unix time instead of time since object creation
        return ( list[float] ) : timestamp, xpos, ypos, zpos, xrot, yrot, zrot
        """
        data, addr = self.in_sock.recvfrom(1024) # buffer size is 1024 bytes

        xdata = [struct.unpack_from('d', data, 32+i*8)[0] for i in range(6)]
        if unix_time: xdata.insert(0,time.time())
        else: xdata.insert(0,time.time()-self.time_start)
        return xdata
    

if __name__ == '__main__':
    vicon = viconUDP()
    while True:
        print(vicon.getTimestampedData())