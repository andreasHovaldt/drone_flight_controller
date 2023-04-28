
from discrete_integrator import Integrator


class PID_control:
    def __init__(self, Ts, Kp, Ki, Kd):
        self.Ts = Ts
        self.Kp = Kp 
        self.Ki = Ki 
        self.Kd = Kd
       
        
        self.simulations = 0

        self.error_int = Integrator(0,Ts)
        
        self.prev_error = 0


    def update(self, error, time_step):
        #check if first step in simulation 
        self.Ts = time_step

        proportional = self.Kp * error

        integration = self.error_int.intgrate(error)

        integral = self.Ki * integration

        
        
        diff = self.Kd * (error - self.prev_error)/self.Ts
        
        self.prev_error=error

        return proportional+integral+diff
        #return self.Kp*error + self.Ki * self.Ts * (1/self.prev_error)  + self.Kd*(self.filterN/(1+self.filterN*self.Ts*(1/self.prev_error)))
        