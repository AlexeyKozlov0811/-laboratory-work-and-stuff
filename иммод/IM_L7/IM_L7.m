Q = 10;
U = 10;
R = 1;

N = 100;

t = zeros(1, N);
q = zeros(1, N);

for i = (2:N)
    t(i) = t(i-1)+rand(1,1);
end

for i = (1:N)
    q(i) = U*Q*(1-exp(-t(i)/(Q*R)));
end

plot(t,q);
xlabel('t')
ylabel('q')