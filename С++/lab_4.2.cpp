
#include <Windows.h>
#include <iostream>
#include<cstdlib>
#include <stdio.h>
#include <cctype>

using namespace std;

void add_el();
void print(int a);
void sort(int a);

struct firms {
	char firm[25];
	int number_of_products;
	int annual_sales_volume;
	float part_of_the_market;
};

struct firms SKBD[10];

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "³����� � ��� ������ ����. ���� �����, �������� �������." << endl;
	add_el();
	
	getchar();
	getchar();
}

void add_el()
{
	int choice = -1, choice2 = -1;
	int count = 0;
	for (int i = 0; (i<20); i++)
	{
		cout << "������ ����� �����: ";
		scanf("%s", SKBD[i].firm);
		cout << "������ ������� ��������: ";
		while (!(cin >> SKBD[i].number_of_products) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ����� �����!" << endl;
			cout << "������ ������� ��������: ";
		}

		cout << "������ ����� �ᒺ� �������: ";
		while (!(cin >> SKBD[i].annual_sales_volume) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ����� �����!" << endl;
			cout << "������ ����� �ᒺ� �������: ";
		}
		cout << "������ ������� ����� (%): ";
		while (!(cin >> SKBD[i].part_of_the_market) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ����� �����!" << endl;
			cout << "������ ������� ����� (%): ";
		}

		cout << "\n������ �� ������ ���?\n1 - ���\n0 - �\n\n";
		cout << ">> ";
		cin >> choice;
		cout << endl;
		if (choice == 0)
			break;
		count++;
	}
	cout << "������ ������� ������� �� �����?\n1 - ���\n0 - �\n" << endl;
	cout << ">> ";
	cin >> choice;
	if (choice != 0)
	{
		system("CLS");
		print(count);
	}

	cout << "������ ������� ����������� �� �������� ������� �� �����?\n1 - ���\n0 - �\n" << endl;
	cout << ">> ";
	cin >> choice2;
	if (choice2 != 0)
	{
		sort(count);
		print(count);
	}



	cout << "��� ���������� �������� Enter" << endl;
}


void print(int a)
{
	printf(" __________________________________________________________________________________________________\n");
	printf("|Գ��� � ��������� ����                                                                            |\n");
	printf("|__________________________________________________________________________________________________|\n");
	printf("|Գ���               |ʳ������ ��������      |г���� �ᒺ� ������� ($) |������� ����� (%%)        |\n");
	printf("|____________________|_________________________|_________________________|_________________________|\n");
	for (int i = 0; i < a + 1; i++)
	{
		printf("|%-20s|%-25d|%-25d|%-25.2f| \n", SKBD[i].firm, SKBD[i].number_of_products, SKBD[i].annual_sales_volume, SKBD[i].part_of_the_market);
		printf("|____________________|_________________________|_________________________|_________________________|\n");
	}
	printf("|�������: �� ������ Gartner Group �� 1999�                                                        |\n");
	printf("|__________________________________________________________________________________________________|\n");
	cout << endl << endl << endl;
	
	/*getchar();
	getchar();*/
}

void sort(int a)
{
	firms frms;
	
	for (int i = 0; i < a + 1; i++)
	{
		for (int j = a ; j > i; j--)
		{
			if (strcmp(SKBD[j].firm, SKBD[j - 1].firm) < 0)
			{
				frms = SKBD[j];
				SKBD[j] = SKBD[j - 1];
				SKBD[j - 1] = frms;
			}
		}
	}
}