function [thrust] = pwm_to_thrust(pwm)
thrust = 0.409e-3*pwm^2 + 140.5e-3*pwm + (-0.099);
end