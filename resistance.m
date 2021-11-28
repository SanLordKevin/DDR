close all
syms Rs 

R_=[1000 2000 3000 4000 5000 10000]

%%f(Rs)=R/(R+Rs)

for i=1:6
    R=R_(i)
    f(Rs)=R/(R+Rs)

    hold on
    fplot(f,[400 11000])
    grid on
    legend()
end

%%

syms F

Rs=271*F^(-0.69)

fplot(Rs,[0 1000])
grid on



