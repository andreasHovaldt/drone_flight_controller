function [lin_acc, ang_acc] = quad_dynamics(motor_rpm, rpy, omega)

%constanst to find the motor torques 
C_Q = 0.024;

air_density = 1.293; %kg/m^3

propeller_radius = 0.045/2; %m
 
disc_area = pi*propeller_radius^2;% - pi*0.002^2

%functions to find motor thrust and torque from rpm 
syms rpm
rpm2torque(rpm) = air_density * C_Q * disc_area * propeller_radius^3 * (rpm*0.1047198)^2;

rpm2thrust(rpm) = (0.109e-6*rpm^2 + (-210.6e-6)*rpm+0.154)*0.001*9.82*0.25;


%% Define constants
rotor_dist = 0.04; %m
body_mass = 0.02989; %kg
g_constant = [0;0;-9.82]; %Nm/s^2




% Vectors from CoM to motors
% We create a X-configured drone
rotor_angle = pi/4;
s1 = [cos(rotor_angle); sin(rotor_angle); 0] * rotor_dist;
s2 = [cos(rotor_angle); -sin(rotor_angle); 0] * rotor_dist;
s3 = [-cos(rotor_angle); -sin(rotor_angle); 0] * rotor_dist;
s4 = [-cos(rotor_angle); sin(rotor_angle); 0] * rotor_dist;
s_vectors = [s1 s2 s3 s4];

% Local motor force vectors
motor_forces = rpm2thrust(motor_rpm);
m1_vec = [0;0;motor_forces(1)];
m2_vec = [0;0;motor_forces(2)];
m3_vec = [0;0;motor_forces(3)];
m4_vec = [0;0;motor_forces(4)];
local_motor_forces = [m1_vec m2_vec m3_vec m4_vec];

%finding the absolute tourques of each motor 
motor_torques = rpm2torque(motor_rpm);

%change the minuses if it rotates in the wrong direction, they are just
%random now
tau2m1 = [0;0;-motor_torques(1)];
tau2m2 = [0;0; motor_torques(2)];
tau2m3 = [0;0;-motor_torques(3)];
tau2m4 = [0;0; motor_torques(4)];
local_motor_torques = [tau2m1 tau2m2 tau2m3 tau2m4];

% Local inertia tensor
I_local = [1.132869584e-05 0 0; 0 1.132869584e-05 0; 0 0 2.028869584e-05];



%% Calculate drone components

% Rotation matrix
%R = rpy2r(rpy(1), rpy(2), rpy(3));
R = rotx(rpy(1)) * roty(rpy(2)) * rotz(rpy(3));

% Global inertia tensor
I_global = (R * I_local) * transpose(R);


%% Equation of motion

% Total force
total_force = R * sum(local_motor_forces,2) + (body_mass * g_constant);

% Total moment
total_moment = R * sum(cross(s_vectors,local_motor_forces),2)+sum(local_motor_torques,2);

%% Linear and angular acceleration
a = total_force/body_mass;
lin_acc = [a(1) a(2) a(3)];

alpha = inv(I_global) * (total_moment - cross(omega,(I_global * omega)));
ang_acc = [alpha(1) alpha(2) alpha(3)];
% omega = angular velocity
% alpha = angular acceleration
end