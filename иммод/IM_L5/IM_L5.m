times = 100;
p = .8;
q = 1-p;
Y = zeros(1, times);
for i = (1:times)
    Y(i)=binornd(1,p);
end
fprintf('%1.1f ',Y)
X = [0,1];
P = [sum(Y == 0.0)/times,sum(Y == 1.0)/times];
plot(P,X)
title('Polygon of distribution of random variable X')
xlabel('P') 
ylabel('X') 

figure()
bar([0,1,2,3],[0,P,1])
title('Distribution function F(x) of a discrete random variable X')
xlabel('X') 
ylabel('F(x)') 
grid on

