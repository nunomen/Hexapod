function [th2, th3, th4] = I_Kin(px, py, pz)

% ??? enter the links dimensions and references here ???
a_sh         = 0.01;    %-> shoulder link length
a_arm        = 0.1;     %-> arm link length
a_leg        = 0.1;     %-> leg length (to the EF)

th2= atan2(py, px);

c4= (px^2 + py^2 + pz^2 - a_arm - a_leg) / (2 * a_arm * a_leg);

th4= atan2(-sqt(1-c4^2), c4);

eps= atan2(pz, sqrt(px^2 + py^2);

delt= acos( (a_leg^2 - a_arm^2 - px^2 - py^2 - pz^2)/(-2 * a_arm * ...
                                            sqrt(px^2 + py^2 + pz^2)));

th3= -delt - eps;

end