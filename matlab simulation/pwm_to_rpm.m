function [rpm] = pwm_to_rpm(pwm)
rpm = sqrt(pwm.*6.1258e-8+pwm.^2.*1.78324e-10-6.595564e-8).*4.587155963302752e+6+9.660550458715596e+2;
end