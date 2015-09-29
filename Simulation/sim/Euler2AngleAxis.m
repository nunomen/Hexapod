function axisangle = Euler2AngleAxis(u)
% This block supports an embeddable subset of the MATLAB language.
% See the help menu for details.

theta = u(1); % yaw y
phi = u(2); % pitch z
psi = u(3); % roll x

c1 = cos(theta/2);
s1 = sin(theta/2);
c2 = cos(phi/2);
s2 = sin(phi/2);
c3 = cos(psi/2);
s3 = sin(psi/2);
% c1c2 = c1*c2;
% s1s2 = s1*s2;
w =c1*c2*c3 - s1*s2*s3;
x =c1*c2*s3 + s1*s2*c3;
y =s1*c2*c3 + c1*s2*s3;
z =c1*s2*c3 - s1*c2*s3;
angle = 2 * acos(w);
norm = x*x+y*y+z*z;
if (norm < 0.001) % when all euler angles are zero angle =0 so we can set axis to anything to avoid divide by zero
    x=1;
    y=0;
    z=0;
else
    norm = sqrt(norm);
    x =x/ norm;
    y =y/ norm;
    z =z/ norm;
end
axisangle = [x y z angle];
end