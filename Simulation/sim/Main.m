
%% Direct Kinematics

clear all
clc

RobotDH= Robot_DH();
[Leg, Tt]=D_Kin(RobotDH);
display('Direct Kinematics for Hexapod calculated.');

%%%%%%%%%%%%%%%% CONTINUAR DAQUI%%%%%%%%%%%%%%%%%%%%%%%

%% display leg

Tr= displayLeg(T, pi/2, 0, 0);

%% Inverse Kinematics

syms px py pz real
p=[px;py;pz];
t=I_Kin(T,p);
display('Inverse Kinematics for Hexapod calculated.');


%%  Create Simulink Library file DirectK_Lib.mdl
new_system('DirectK_Lib','Library');
open_system('DirectK_Lib');

matlabFunctionBlock('DirectK_Lib/Hexa_Direct_Kinematics',Tt);

save_system('DirectK_Lib');
close_system('DirectK_Lib');


%%  Create Simulink Library file InverseK_Lib.mdl
new_system('InverseK_Lib','Library');
open_system('InverseK_Lib');

matlabFunctionBlock('InverseK_Lib/Hexa_Inverse_Kinematics',t);

save_system('InverseK_Lib');
close_system('InverseK_Lib');


%% create virtual world for robot referentials
vrrobot(RobotDH);


