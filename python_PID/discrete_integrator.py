class Integrator:
    def __init__(self, initial_condition,time_step):
        self.prev_int = initial_condition
        self.time_step = time_step
    def intgrate(self, input):
        prev_int = self.prev_int
        self.prev_int = prev_int+input*self.time_step
        return self.prev_int