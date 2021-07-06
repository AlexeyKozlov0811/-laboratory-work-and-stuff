

min_value = 0.0;
max_value = 6.0;
% max_value = 4.0;
num_values = 50; 

numbers = ((max_value-min_value).* rand(1, num_values) + min_value);

Ri = [0, 0.25, 0, 0.5, 0];
Xi = [0, 2, 4, 4, 6];
% Ri = [0.25, 0.25, 0.5, 0];
% Xi = [0, 2, 2, 4];
nRi = [0, 0.25, 0, 0.5, 0];
nXi = [0, 2, 4, 6];
% 1 1 2 =1*2-1
% 2 2 3 =2*2-2
% 3 4 5 =3*2-2
plot(Xi, Ri, '-b')

x = [];
in_start = nXi(1 : 1 : end-1); 
in_finish = nXi(2 : 1 : end); 
% fprintf('%d ', in_start)
% fprintf('%d ', in_finish)

for num = numbers
    if((num >= in_start(1)) && (num <= in_finish(1)))
        t = interp1([in_start(1), in_finish(1)], [Ri(1), Ri(2)], num);
        x = [x, t];
    else if((num >= in_start(2)) && (num <= in_finish(2)))
        t = interp1([in_start(2), in_finish(2)], [Ri(2), Ri(3)], num);
        x = [x, t];
    else if((num >= in_start(3)) && (num <= in_finish(3)))
        t = interp1([in_start(3), in_finish(3)], [Ri(4), Ri(5)], num);
        x = [x, t];
        end
        end
    end
end

fprintf('\n%d\n%d\n', length(x),length(numbers))
assert(length(x) == length(numbers))

hold on % ????????? - ???????? ?????? ???????? ???????
plot(numbers, x, '*r') 


Mx = mean(x);
fprintf('\nMathematical expectation = %0.16f\n', Mx);

Dx = var(x);
fprintf('Dispersion = %0.16f\n', Dx);

Ox = std(x); 
fprintf('Standart devitation = %0.16f\n', Ox);

Mm = mean(Mx);
fprintf('Sample mean = %0.16f\n \n', Mm);

n_intervals = length(in_start);
freq = zeros(1, n_intervals);
rel_freq = zeros(1, n_intervals);

for i = (1: n_intervals)
 for value = numbers 
 if ((value >= in_start(i)) && (value <= in_finish(i))) 
 freq(i) = freq(i) + 1;
 rel_freq(i) = freq(i) / num_values/2;
 end
 end
end


figure
hold off % ????????? ??????????? ?????? ???????? ????? – ?????? ? ?????
bar(Xi(1 : n_intervals), rel_freq)

headers={'LeftBorder','RightBorder','Frequency','Relative Frequency'};
data=flipud(rot90([in_start;in_finish;freq;rel_freq]));
uitable(figure,'Data',data, 'ColumnName',headers);
 
headers={'prng','x'};
data=rot90([numbers;x]);
uitable(figure,'Data',data, 'ColumnName',headers);
