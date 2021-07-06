%F(x) = x^2 
a = 0.2;
b = 0.8;
N = 100;
eps = rand(1,N);
eps = sort(eps);
fprintf('%f ',eps)
fprintf('\n')
x = sqrt(eps);
fprintf('%f ',x)
plot(x,eps)
title('Distribution function')
xlabel('X')
ylabel('e')
grid on
P = sqrt(0.8) - sqrt(0.2);
fprintf('\n')
fprintf('Probability that x is in [%.1f;%.1f] range = %f', a, b, P)