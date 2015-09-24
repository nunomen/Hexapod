function Robot = Robot_DH()
%   Returns D-H table of parameters for Robotic Arm
%   Robot=[d v a alpha;
%          d v a alpha;
%          . . .   .  ;
%          d v a alpha];
%   Use symbolic variables for each joint coordinate of the robot: in the d
%   column for a prismatic joint and in the v column for a rotational
%   joint. Name the variables from q1 to qn.


syms t2 t3 t4 real

%d teta a alfa
Robot = [0   pi/6   0    0      0;
         0   t2     0.8  0      0;
         0   t3     0.8 -pi/2   0;
         0   t4     0.8  pi     0;
         0   0      0.8  0      0];

end

