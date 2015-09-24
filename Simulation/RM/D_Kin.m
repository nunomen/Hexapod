function [T,Tt] = D_Kin( Robot )

%   T  -> Array de transformações
%   Tt -> Transformação de 0 a 7

n=size(Robot,1);      %get number of robot joints

Tt=eye(4);


for i=1:n
    
    line=Robot(i,:);
    
    %Transformation Matrix
    
    T{i}=[  cos(line(2)+line(5)) -sin(line(2)+line(5))*cos(line(4)) sin(line(2)+line(5))*sin(line(4))   line(3)*cos(line(2)+line(5));
            sin(line(2)+line(5))  cos(line(2)+line(5))*cos(line(4)) -cos(line(2)+line(5))*sin(line(4))  line(3)*sin(line(2)+line(5));
            0                    sin(line(4))                       cos(line(4))                        line(1)                     ;
            0                    0                                  0                                   1                           ];
    
    Tt=Tt*T{i};
end


%Simplify
Tt=simplify(Tt);

for i=1:n
    T{i}=simplify(T{i});
end


end