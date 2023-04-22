

class PID_control:
    def __init__(self, Ts, Kp, Ki, Kd):
        self.Ts = Ts
        self.Kp = Kp 
        self.Ki = Ki 
        self.Kd = Kd
        self.prev_integration = 0
        self.simulations = 0
        
    def update(self, error):
        #check if first step in simulation 
        if self.simulations == 0:
            self.prev_error = error
            self.simulations = 1

        proportional = self.Kp * error

        integration = error*self.Ts + self.prev_integration

        integral = self.Ki * integration
        
        self.prev_integration = integration

        diff = self.Kd * (error-self.prev_error)/self.Ts
        self.prev_error=error

        return proportional+integral+diff
        