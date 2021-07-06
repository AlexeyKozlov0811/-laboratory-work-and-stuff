M = 1234567;
m = 10;

number_of_digits = 1000; 
number_of_interval_borders = 15;

x(1) = 2^(-m); 
for number_idx = (2:number_of_digits)
x(number_idx) = mod(M * x(number_idx-1),1);
end

% disp('Random numbers');
% for number_idx = (1:number_of_digits)
% fprintf('%d) %0.16f\n', number_idx, x(number_idx));
% end


Mx = mean(x);
fprintf('\nMathematical expectation = %0.16f\n', Mx);

Dx = var(x);
fprintf('Dispersion = %0.16f\n', Dx);

Ox = std(x); 
fprintf('Standart devitation = %0.16f\n', Ox);

Mm = mean(Mx);
fprintf('Sample mean = %0.16f\n \n', Mm);


interval_step = 1/number_of_interval_borders;
interval_borders = 0 : interval_step : 1;
n = length(interval_borders);
in_start = interval_borders(1:n-1); 
in_finish = interval_borders(2:n); 
freq = zeros(1, n-1); 
rel_freq = zeros(1, n-1);
for i = (1: n-1) 
	for value = x 
		if ((value >= in_start(i)) && (value <= in_finish(i))) 
		freq(i) = freq(i) + 1; 
rel_freq(i) = freq(i) / number_of_digits; 
end
end
end

bar(interval_borders(1: n-1), rel_freq)

headers={'LeftBorder','RightBorder','Frequency','Relative Frequency'};
data=flipud(rot90([in_start;in_finish;freq;rel_freq]));
uitable(figure,'Data',data, 'ColumnName',headers);
 
headers={'Random Value'};
data=rot90(x);
uitable(figure,'Data',data, 'ColumnName',headers);