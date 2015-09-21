

%a      -> distance from z(i) to z(i+1) along x(i)
%alpha  -> angle between z(i) and z(i+1) along x(i)
%d      -> distance from x(i-1) to x(i) along z(i)
%t      -> angle between x(i-1) and x(i) along z(i)

% ??? enter the links dimensions and references here ???
a_sh   = 0.01;    %-> shoulder link length
a_arm        = 0.1;     %-> arm link length
a_leg        = 0.1;     %-> leg length (to the EF)
d_sh         = 0;       %-> horizontal length of the shoulder-arm link
d_arm         = 0;       %-> horizontal length of the arm-leg link
d_leg        = 0;       %-> horizontal length of the leg-EF link
ref_shoulder = pi/2;    %-> reference for the shoulder servo
ref_arm      = 0;       %-> reference for the arm servo
ref_leg      = 0;       %-> reference for the leg servo
rc           = 110;     %-> center radius
h            = 5;       %-> height from the virtual center to the first servo
k            = 0;       %-> leg index starting in 0 ending in 5


syms alphai ai ti di ref real;
syms t2 t3 t4 real;

%Generic Denavit-Hartenberg transformation matrix
DHT=[cos(ti+ref) -sin(ti+ref)*cos(ai) sin(ti+ref)*sin(ai)      ai*cos(ti+ref) ;
     sin(ti+ref) cos(ti+ref)*cos(ai)  -cos(ti+ref)*sin(ti+ref) ai*sin(ti+ref) ;
     0           sin(alphai)          cos(alphai)              di             ;
     0           0                    0                        1              ];
    
%1 -> Rotation from the "front" to the desired leg
T1= subs(DHT, ref, k * pi/3 + pi/6);
T1= subs(T1, ti, 0);
T1= subs(T1, alphai, 0);
T1= subs(T1, ai, 0);
T1= subs(T1, di, h);

%2 -> Shoulder rotation
T2= subs(DHT, ref, pi/2);
T2= subs(T2, ti, t2);
T2= subs(T2, alphai, 0);
T2= subs(T2, ai, rc);
T2= subs(T2, di, h);

%3 -> Arm rotation
T3= subs(DHT, ref, 1234567890);
T3= subs(T3, ti, t3);
T3= subs(T3, alphai, -pi/2);
T3= subs(T3, ai, a_sh);
T3= subs(T3, di, d_sh);

%4 -> Leg rotation
T4= subs(DHT, ref, 1234567890);
T4= subs(T4, ti, t4);
T4= subs(T4, alphai, pi);
T4= subs(T4, ai, a_arm);
T4= subs(T4, di, d_al);

%5 -> Leg to the end effector
T5= subs(DHT, ref, 0);
T5= subs(T5, ti, 0);
T5= subs(T5, alphai, 0);
T5= subs(T5, ai, a_leg);
T5= subs(T5, di, d_lEF);


T01= T1;
T02= T01 * T2;
T03= T02 * T3;
T04= T03 * T4;
T05= T04 * T5;
% simplify(T02);
% simplify(T03);
% simplify(T04);
% simplify(T05);

clear a_shoulder a_arm a_leg d_sa d_al d_lEF ref_shoulder ref_arm ...
        ref_leg ref_arm rc h k;
    
clear DHT ai ti alphai ai ti di ref;




