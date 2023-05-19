close;
%% Drone 3D simulation
figure('Name','3D Drone animation','NumberTitle','off');
xlimit = [-2 2];
ylimit = [-2 2];
zlimit = [-2 6];
width = 750;
height = 650;

NewFigure(xlimit,ylimit,zlimit,60,25,width,height);

% t = out.tout;



%rotor_dist = 1.42; % Real rotor_dist
rotor_dist = 0.2; % Artificial rotor_dist
rotor_angle = pi/4;
s1 = [cos(rotor_angle); sin(rotor_angle); 0] * rotor_dist;
s2 = [cos(rotor_angle); -sin(rotor_angle); 0] * rotor_dist;
s3 = [-cos(rotor_angle); -sin(rotor_angle); 0] * rotor_dist;
s4 = [-cos(rotor_angle); sin(rotor_angle); 0] * rotor_dist;

pause(1)

for i = 1:1000:length(out.XYZ)
    currentPos = out.XYZ(i,:);
    currentRPY = out.RPY(i,:);

    R = rotx(currentRPY(1)) * roty(currentRPY(2)) * rotz(currentRPY(3));
    
    m1_pos = (R*s1) + transpose(currentPos);
    m2_pos = (R*s2) + transpose(currentPos);
    m3_pos = (R*s3) + transpose(currentPos);
    m4_pos = (R*s4) + transpose(currentPos);
    
    line1 = plot3([m1_pos(1) m3_pos(1)], [m1_pos(2) m3_pos(2)], [m1_pos(3) m3_pos(3)],'b', 'LineWidth', 2.5);
    line2 = plot3([m2_pos(1) m4_pos(1)], [m2_pos(2) m4_pos(2)], [m2_pos(3) m4_pos(3)], 'b', 'LineWidth', 2.5);


    X = out.XYZ(1:i,1);
    Y = out.XYZ(1:i,2);
    Z = out.XYZ(1:i,3);
    traj = plot3(X,Y,Z,'r');

    drawnow
    pause(0.01)

    delete(line1)
    delete(line2)
    delete(traj)

end
line1 = plot3([m1_pos(1) m3_pos(1)], [m1_pos(2) m3_pos(2)], [m1_pos(3) m3_pos(3)],'b', 'LineWidth', 2.5);
line2 = plot3([m2_pos(1) m4_pos(1)], [m2_pos(2) m4_pos(2)], [m2_pos(3) m4_pos(3)], 'b', 'LineWidth', 2.5);
drawnow



X = out.XYZ(:,1);
Y = out.XYZ(:,2);
Z = out.XYZ(:,3);
plot3(X,Y,Z,'r')


%% Local functions

function NewFigure(xlim,ylim,zlim,viewx,viewy,w,h)
    set(gca, 'XLim', xlim,'YLim',ylim,'ZLim',zlim);
    view(viewx,viewy)
    x0=10;
    y0=10;
    set(gcf,'position',[x0,y0,w,h])
    xlabel('X pos')
    ylabel('Y pos')
    zlabel('Z pos')
    hold on;
    grid on;
end