M = 1234567;
m = 10;

number_of_digits = 100; 
%number_of_interval_borders = 15;

Xi = [1,6,8,13,19,24,27];
Pi = [0.09,0.1,0.21,0.17,0.23,0.15,0.05];
% numbers = rand(1, number_of_digits);

numbers(1) = 2^(-m); 
for number_idx = (2:number_of_digits)
numbers(number_idx) = mod(M * numbers(number_idx-1),1);
end

intervals = [0.00]; % ?????? ?????? ??????????
for i = (1: length(Pi))
 intervals = [intervals, intervals(i) + Pi(i)]; % ????????? ??????? ? ??????
end

x = [];
in_start = intervals(1 : length(intervals)-1); 
in_finish = intervals(2 : length(intervals) ); 

for value = numbers
 for i = (1 : length(intervals)-1)
 if ((value >= in_start(i)) && (value <= in_finish(i))) % ???? ?? ? ?????????
    x = [x, Xi(i)]; % ??????????? ?? ???????? Xi ?? ???????
 end
 end
end

assert(length(x) == length(numbers))


Mx = mean(x);
fprintf('\nMathematical expectation = %0.16f\n', Mx);

Dx = var(x);
fprintf('Dispersion = %0.16f\n', Dx);

Ox = std(x); 
fprintf('Standart devitation = %0.16f\n', Ox);

Mm = mean(Mx);
fprintf('Sample mean = %0.16f\n \n', Mm);

n = length(intervals);
in_start = intervals(1:n-1); 
in_finish = intervals(2:n); 
freq = zeros(1, n-1); 
rel_freq = zeros(1, n-1);
for i = (1: n-1) 
	for value = numbers 
		if ((value >= in_start(i)) && (value <= in_finish(i))) 
		freq(i) = freq(i) + 1; 
        rel_freq(i) = freq(i) / number_of_digits; 
end
end
end

bar(intervals(1: n-1), rel_freq)

headers={'LeftBorder','RightBorder','Frequency','Relative Frequency'};
data=flipud(rot90([in_start;in_finish;freq;rel_freq]));
uitable(figure,'Data',data, 'ColumnName',headers);
 
headers={'prng','x'};
data=rot90([numbers;x]);
uitable(figure,'Data',data, 'ColumnName',headers);