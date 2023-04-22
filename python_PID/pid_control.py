

class PID_control:
    def __init__(self, Ts, Kp, Ki, Kd, start_error):
        self.Ts = Ts
        self.Kp = Kp 
        self.Ki = Ki 
        self.Kd = Kd
        self.prev_error = start_error
        self.prev_integration = 0
        
    def update(self, ref, current):
        error = ref-current
        proportional = self.Kp * error

        integration = error*self.Ts + self.prev_integration
        integral = self.Ki * integration
        self.prev_integration = integration

        diff = self.Kd * (error-self.prev_error)/self.Ts
        self.prev_error=error

        return proportional+integral+diff
        