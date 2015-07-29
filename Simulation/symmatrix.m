syms ai ti real;

syms a1 a2 a3 t1 t2 t3 real;

DHT=[   cos(ti) -sin(ti)*cos(ai) sin(ti)*sin(ai)  ai*cos(ti) ;
        sin(ti) cos(ti)*cos(ai)  -cos(ti)*sin(ti) ai*sin(ti) ;
        0       sin(ti)          cos(ti)          0          ;
        0       0                0                1          ];

T1= subs(DHT, ti, t1);
T1= subs(T1, ai, a1);

T2= subs(DHT, ti, t2);
T2= subs(T2, ai, a2);

T3= subs(DHT, ti, t3);
T3= subs(T3, ai, a3);

Tbl= T1* T2 * T3;
simplify(Tbl);

subs(Tbl, a1, 0.05564);
subs(Tbl, a2, 0.09331);
subs(Tbl, a3, 0.110);

T12= T1*T2



clear DHT ai ti;

clear T1 T2 T3;






