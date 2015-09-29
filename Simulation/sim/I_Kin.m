function t = I_Kin(T, p)

% ??? enter the links dimensions and references here ???
%a_sh         = 0.8;    %-> shoulder link length
a_arm        = 0.8;     %-> arm link length
a_leg        = 0.8;     %-> leg length (to the EF)

syms t2 t3 t4 real

%Calculate inverse matrices
for i=1:3
Ti{i}=[T{i}(1:3,1:3)' -T{i}(1:3,1:3)'*T{i}(1:3,4);0 0 0 1];
end

%p to ref 2
p=[p; 1];
p=Ti{2}*Ti{1}*p;

%Calculate t2
th2= atan2(p(2), p(1));

%p to ref 3
Ti3=subs(Ti{3},t2,th2);
p=Ti3*p;

%Calculate t4
c4= (p(1)^2 + p(2)^2 + p(3)^2 - a_arm^2 - a_leg^2) / (2 * a_arm * a_leg);

th4= atan2(-sqrt(1-c4^2), c4); %elbow up

%Calculate auxs
eps= atan2(p(3), sqrt(p(1)^2 + p(2)^2));

cdelt= (a_leg^2 - a_arm^2 - p(1)^2 - p(2)^2 - p(3)^2)/(-2 * a_arm * ...
                                            sqrt(p(1)^2 + p(2)^2 + p(3)^2));
delt=atan2(sqrt(1-cdelt^2),cdelt);

%Calculate t3
th3= -delt - eps;

t=[th2, th3, th4];

end