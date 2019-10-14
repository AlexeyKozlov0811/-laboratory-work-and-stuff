#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>
using namespace std;
float input(string message);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float a = 0, b = 0, c = 0;
	std::cout << "Введіть довжини сторін трикутника (цілі числа):\n";
	a = input("a = ");
	b = input("b = ");
	c = input("c = ");
	
	if ((((b + c - a) > 0) && ((a + c - b) > 0) && ((a + b - c) > 0)))
	{
			if ((a == b) && (a == c) && (b == c))
				cout << "Трикутник є рівностороннім" <<endl;
			else if (((a == b) && a != c) || ((a == c) && a != b) || ((b == c) && b != a))
				cout << "Трикутник є рівнобедренним" <<endl;
			else if ((pow(a, 2) == pow(b, 2) + pow(c, 2)) || (pow(b, 2) == pow(a, 2) + pow(c, 2)) || (pow(c, 2) == pow(b, 2) + pow(a, 2)))
				cout << "Трикутник є прямокутним" <<endl;
			else if ((a != b) && ((a != c)) && (b != c))
				cout << "Трикутник є простим";
	}
	else
	{
		cout << "Трикутник не існує\n";
		if ((a == 0) || (b == 0) || (c == 0))
			cout << "Довжина сторони дорівнює нулю";
		if ((a < 0) || (b < 0) || (c < 0))
			cout << "Довжина сторони від’ємна";
	}
	return 0;
}

float input(string message)
{
	float n;
	while (true)
	{
		cout << message;
		cin >> n;
		if (!cin)
		{
			cout << "Довжина не є числом\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else if ((n != int(n)))
		{
			cout << "Довжина не цілим є числом\n";
		}
		else break;
	}
	return n;
}
