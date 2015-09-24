
function [T01, T02, T03, T04, T05]=displayLeg(T01,  T02, T03, T04, T05, th2, th3, th4)

%t1 t2 t3 : teta1 teta2 teta3
%T1 T2 T3: transformation matrices 1 2 and 3

%apply angles to transformation matrices
%T01 is constant
T02=apptransf(T02, th2, th3, th4);
T03=apptransf(T03, th2, th3, th4);
T04=apptransf(T04, th2, th3, th4);
T05=apptransf(T05, th2, th3, th4);

%plot the position vector
figure;
hold on;
grid on;

line([0 T01(1,4)],[0 T01(2,4)],[0 T01(3,4)],'Color','k'); %deixa yellow para debugk
line([T01(1,4) T02(1,4)],[T01(2,4) T02(2,4)],[T01(3,4) T02(3,4)],'Color','y'); %yellow
line([T02(1,4) T03(1,4)],[T02(2,4) T03(2,4)],[T02(3,4) T03(3,4)],'Color','r'); %red
line([T03(1,4) T04(1,4)],[T03(2,4) T04(2,4)],[T03(3,4) T04(3,4)],'Color','g'); %green
line([T04(1,4) T05(1,4)],[T04(2,4) T05(2,4)],[T04(3,4) T05(3,4)],'Color','b'); %blue

xlabel('x');
ylabel('y');
zlabel('z');

hold off;



end



