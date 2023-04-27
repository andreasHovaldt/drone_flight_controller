
from discrete_integrator import Integrator


class PID_control:
    def __init__(self, Ts, Kp, Ki, Kd):
        self.Ts = Ts
        self.Kp = Kp 
        self.Ki = Ki 
        self.Kd = Kd
       
        self.prev_integration = 0
        self.simulations = 0

        self.error_int = Integrator(0,Ts)
        
        self.prev_error = 0


    def update(self, error):
        #check if first step in simulation 
        

        proportional = self.Kp * error

        integration = self.error_int.intgrate(error)

        integral = self.Ki * integration

        #self.prev_integration = integration
        
        diff = self.Kd * (error - self.prev_error)/self.Ts
        
        self.prev_error=error

        return proportional+integral+diff
        #return self.Kp*error + self.Ki * self.Ts * (1/self.prev_error)  + self.Kd*(self.filterN/(1+self.filterN*self.Ts*(1/self.prev_error)))
        