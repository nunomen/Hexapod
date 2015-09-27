function transf= apptransf(T, th2, th3, th4)

syms t2 t3 t4 real;

transf=subs(T, t2, th2);
transf=subs(transf, t3, th3);
transf=subs(transf, t4, th4);
transf=double(transf);

end