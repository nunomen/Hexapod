
function Tr=displayLeg(T, th2, th3, th4)

%t1 t2 t3 : teta1 teta2 teta3
%T1 T2 T3: transformation matrices 1 2 and 3
syms t2 t3 t4 real

%apply angles to transformation matrices
Tr{1}= T{1};                        %T01 is constant
Tr{2}=Tr{1}*T{2};
Tr{3}=subs(Tr{2}*T{3}, t2, th2);
Tr{4}=subs(Tr{3}*T{4}, t3, th3);
Tr{5}=subs(Tr{4}*T{5}, t4, th4);

%plot the position vector
figure;
hold on;
grid on;

line([0 Tr{1}(1,4)],[0 Tr{1}(2,4)],[0 Tr{1}(3,4)],'Color','k'); %black
line([Tr{1}(1,4) Tr{2}(1,4)],[Tr{1}(2,4) Tr{2}(2,4)],[Tr{1}(3,4) Tr{2}(3,4)],'Color','y'); %yellow
line([Tr{2}(1,4) Tr{3}(1,4)],[Tr{2}(2,4) Tr{3}(2,4)],[Tr{2}(3,4) Tr{3}(3,4)],'Color','r'); %red
line([Tr{3}(1,4) Tr{4}(1,4)],[Tr{3}(2,4) Tr{4}(2,4)],[Tr{3}(3,4) Tr{4}(3,4)],'Color','g'); %green
line([Tr{4}(1,4) Tr{5}(1,4)],[Tr{4}(2,4) Tr{5}(2,4)],[Tr{4}(3,4) Tr{5}(3,4)],'Color','b'); %blue

fprintf('Centro->Shoulder - yellow \nShoulder->Arm - red \nArm->Leg - green \nLeg->Eff - blue\n');
        
xlabel('x');
ylabel('y');
zlabel('z');

hold off;



end



