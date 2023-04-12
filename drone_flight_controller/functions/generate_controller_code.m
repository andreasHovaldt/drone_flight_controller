function generate_controller_code()
%generate_controller_code
%

%   Copyright 2012 The MathWorks, Inc.

% Use the Simulink Coder API to generate code for controllerModel:

controllerModel = 'drone_simulation_3D';

if(~bdIsLoaded(controllerModel))
    open_system(controllerModel);
end

slbuild(controllerModel);
coder.report.generate(controllerModel);

end

