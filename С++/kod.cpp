//#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <Windows.h>

#define a 12.5
#define b 1.3
#define c 14.1

using std::cout;
using std::endl;
using std::cin;

double t1();
double t2();
void results(double t1, double t2);

void main()
{
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);
	int choice = 1000;
	double x,y;
	while (choice != 0)
	{
		/*system("cls");*/
		cout << "Вітаємо!\nЄ дві функції t1 та t2\n\nЩоб підрахувати значення за формулою\n t1=ax/y+b*lg(yx+c)/y^2\n натисніть 1\n\nЩоб підрахувати значення за формулою\n t2=1/2ab*ln((sqrt(c^2-b^2)*tg(ax)+2)/(sqrt(c^2-b^2)*tg(ax)-2)) \nнатисніть 2\n\nЩоб показати ркезультати розрахунків натисніть 3\n\nДля виходу натисніть 0\n" << endl;
		cin >> choice;
		/*system("cls");*/
		switch (choice) {
		case 1:
		{
			
			t1();
			
			/*cout << "t1 = " << t1(x,y) << endl;*/
			break;
		}
		case 2:
		{
			
			t2();
			break;
		}
		case 3:
		{
			results(t1(), t2());
			break;
		}
		}
	}
}


double t1()
{
	double t1;
	double ax, z;
	double x;
	double y;
	cout << "input x: ";
	cin >> x;
	cout << "input y: ";
	cin >> y;
	while (!y) {
		
		if (y != 0) {
			ax = a*x;
			z = y*x + c;
			cout << ax << endl;
			if (z > 0)
			{
				t1 = (ax) / y + b*log10(z) / pow(y, 2);
				
			}
		}
		else
			cout << "y cannot be equal to 0" << endl;
	}
	cout << "t1 = ax/y+b*lg(yx+c)/y^2" << endl;
	cin.get();
	cin.get();
	return t1;
}


double t2()
{
	cout << "За умовою: \na=12.5 \nb=1.3 \nc=14.1\n";
	double x;
	cout << "input x: ";
			cin >> x;
	double t2;
	double ax, z, l;

	
	ax = a*x;
	z = sqrt(pow(c, 2) - pow(b, 2))*tan(ax);
	if (z != 2)
	{
		l = (z + 2) / (z - 2);
		if (l > 0)
		{
			t2 = (1 / (2 * a*b))*log(l);
			/*cout << " a = 12.5\nb = 1.3\nc = 14.1" << endl;
			cout << "t2 = " << t2 << endl;*/

		}
		else
			cout << "ln cannot be less then 0" << endl;

	}
	else
		cout << "znametatel cannot be equal to 0" << endl;

cin.get();
cin.get();
return t2;
}

void results(double t1, double t2)
{
	cout << t1<<endl<<t2;
	system("pause");
}
