//�������� �2
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
	cout << "³����!\n� �� ������� t1 �� t2\n" << endl;
	while (choice != 0)
	{
		
		cout << "�������� 1, ��� ���������� �������� �� ��������\nt1=ax/y+b*lg(yx+c)/y^2\n\n�������� 2, ��� ���������� �������� �� ��������\nt2=1/2ab*ln((sqrt(c^2-b^2)*tg(ax)+2)/(sqrt(c^2-b^2)*tg(ax)-2))\n\n�������� 3, ��� �������� ���������� ����������\n\n��� ������ �������� 0\n" << endl;
		cout << ">> ";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "�� ������: \na=12.5 \nb=1.3 \nc=14.1\n" << endl;
			cout << "������� ���������� �������: y=/=0, y*x>-" <<c<< endl;
			while (!y1) {
				cout << "������ x: ";
				cin >> x1;
				cout << "������ y: ";
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
						cout << "ϳ������������ ����� �� ���� ����� 0" << endl;
				}
				else
					cout << "y �� ���� ���������� ����, ������� �� ����������� � ����������" << endl;
			}
			cout << "��� ����������� �������� Enter" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
		case 2:
		{
			cout << "�� ������: \na=12.5 \nb=1.3 \nc=14.1\n" << endl;
			cout << "������� ���������� �������: x<-2, x>2" << endl;
			cout << "������ x: ";
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
					cout << "ϳ������������� ����� �� ���� ���� ������ ����" << endl;
			}
			else
				cout << "��������� �� ���� ���������� ����" << endl;
			cout << "��� ����������� �������� Enter" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
		case 3:
		{
			if (t1 == 0 || t2 == 0)
				cout << "����������� ����� ��� ������" << endl;
			else
				cout << "���������� ��������� ���:\nt1=" << t1 << endl << "t2=" <<t2<< endl;
			cout << "��� ����������� �������� Enter" << endl;
			cin.get();
			cin.get();
			system("cls");
			break;
		}
		}
	}
}

