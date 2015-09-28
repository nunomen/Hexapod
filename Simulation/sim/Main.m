
%% Direct Kinematics and Jacobian

%clear all
clc

RobotDH= Robot_DH();
[T,Tt]=D_Kin(RobotDH);
display('Direct Kinematics for Hexapod calculated.');

%% display leg

Tr= displayLeg(T, pi/2, pi/2, pi/2);


%% Inverse Kinematics



% %%  Create Simulink Library file DirectK_Lib.mdl
% new_system('DirectK_Lib','Library');
% open_system('DirectK_Lib');
% 

% matlabFunctionBlock('DirectK_Lib/RobotX_Direct_Kinematics',R{7},p{8},J);
% 
% save_system('DirectK_Lib');
% close_system('DirectK_Lib');
% 
% 
% %%  Create Simulink Library file InverseK_Lib.mdl
% new_system('InverseK_Lib1','Library');
% open_system('InverseK_Lib1');
% 
% matlabFunctionBlock('InverseK_Lib1/RobotX_Inverse_Kinematics',Pe,Pw);
% 
% save_system('InverseK_Lib1');
% close_system('InverseK_Lib1');
% 
% 
% %% create virtual world for robot animation
% vrrobot(RobotDH);


