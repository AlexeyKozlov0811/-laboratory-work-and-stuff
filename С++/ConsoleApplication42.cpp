//Завдання №2
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <Windows.h>

#define a 12.5
#define b 1.3
#define c 14.1

using std::cout;
using std::endl;
using std::cin;

void main()
{
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);
	int choice = 100;
	double x1, y1 = 0;
	double x2;
	double t1=0, t2=0;
	double ax1, ax2, z1, z2, l;
	cout << "Вітаємо!\nЄ дві функції t1 та t2\n" << endl;
	while (choice != 0)
	{
		
		cout << "Натисніть 1, щоб підрахувати значення за формулою\nt1=ax/y+b*lg(yx+c)/y^2\n\nНатисніть 2, щоб підрахувати значення за формулою\nt2=1/2ab*ln((sqrt(c^2-b^2)*tg(ax)+2)/(sqrt(c^2-b^2)*tg(ax)-2))\n\nНатисніть 3, щоб показати результати розрахунків\n\nДля виходу натисніть 0\n" << endl;
		cout << ">> ";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "За умовою: \na=12.5 \nb=1.3 \nc=14.1\n" << endl;
			cout << "Область допустимих значень: y=/=0, y*x>-" <<c<< endl;
			while (!y1) {
				cout << "Введіть x: ";
				cin >> x1;
				cout << "Введіть y: ";
				cin >> y1;
				if (y1 != 0) {
					ax1 = a*x1;
					z1 = y1*x1 + c;
					if (z1 > 0)
					{
						t1 = (ax1) / y1 + b*log10(z1) / pow(y1, 2);
						cout << "t1 = " << t1 << endl;

					}
					else
						cout << "Підлогарифмічне число має бути більше 0" << endl;
				}
				else
					cout << "y не може дорівнювати нулю, оскільки він знаходиться в знаменнику" << endl;
			}
			cout << "Для продовження натисніть Enter" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
		case 2:
		{
			cout << "За умовою: \na=12.5 \nb=1.3 \nc=14.1\n" << endl;
			cout << "Область допустимих значень: x<-2, x>2" << endl;
			cout << "Введіть x: ";
			cin >> x2;
			ax2 = a*x2;
			z2 = sqrt(pow(c, 2) - pow(b, 2))*tan(ax2);
			if (z2 != 2)
			{
				l = (z2 + 2) / (z2 - 2);
				if (l > 0)
				{
					t2 = (1 / (2 * a*b))*log(l);
					cout << "t2 = " << t2 << endl;

				}
				else
					cout << "Підлогарифмічний вираз не може бути меньше нуля" << endl;
			}
			else
				cout << "Знаменник не може дорівнювати нулю" << endl;
			cout << "Для продовження натисніть Enter" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
		case 3:
		{
			if (t1 == 0 || t2 == 0)
				cout << "Недостатньо даних для виводу" << endl;
			else
				cout << "Результати обрахунків такі:\nt1=" << t1 << endl << "t2=" <<t2<< endl;
			cout << "Для продовження натисніть Enter" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
		}
	}
}

