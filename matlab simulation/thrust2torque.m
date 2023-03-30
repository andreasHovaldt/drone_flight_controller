function torque = thrust2torque(thrust)

%constanst to find the motor torques 
C_Q = 0.024;

air_density = 1.293; %kg/m^3

propeller_radius = 0.045/2; %m
 
disc_area = pi*propeller_radius^2;% - pi*0.002^2

%this must be done to avoide complex numbers 
if thrust < 0.00013
    torque = 0;
else
    rpm = 966.0550459 + 0.001868495301* sqrt(-1.373657841*10^11 +1.070380000*10^15 * thrust);
    torque = air_density * C_Q * disc_area * propeller_radius^3 * (rpm*0.1047198)^2;
end 
end