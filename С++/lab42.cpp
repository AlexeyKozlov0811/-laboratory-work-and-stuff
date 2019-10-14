
#include <Windows.h>
#include <iostream>
#include<cstdlib>
#include <stdio.h>
#include <cctype>

using namespace std;

struct firms {
	char firm[25];
	int number_of_products;
	int annual_sales_volume;
	float part_of_the_market;
};

struct firms SKBD[10];

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

int add_el()
{
	int count = 0;
	int choice;
	for (int i = 0; (i<20); i++)
	{
		cout << "������ ����� �����: ";
		scanf("%s", SKBD[i].firm);
		cout << "������ ������� ��������: ";
		cin >> SKBD[i].number_of_products;
		/* while (!(cin >> SKBD[i].number_of_products) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ����� �����!" << endl;
			cout << "������ ������� ��������: ";
		} */

		cout << "������ ����� �ᒺ� �������: ";
		cin >> SKBD[i].annual_sales_volume;
		/* while (!(cin >> SKBD[i].annual_sales_volume) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ����� �����!" << endl;
			cout << "������ ����� �ᒺ� �������: ";
		} */
		cout << "������ ������� ����� (%): ";
		cin >> SKBD[i].part_of_the_market;
		/* while (!(cin >> SKBD[i].part_of_the_market) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ����� �����!" << endl;
			cout << "������ ������� ����� (%): ";
		} */

		cout << "\n������ �� ������ ���?\n1) ���\n2) �\n";
		cout << ">> ";
		cin >> choice;
		cout << endl;
		if (choice != 1)
			break;
		count++;
	}
	return count;
}

void main()
{
	cout << "³����� � �������\n";
	int choice = -1;
	int count;
	while(choice != 0)
	{
		cout << "1) ������ �������� �� �������\n2) ������� ������� �� �����\n3) ������� ����������� �� �������� ������� �� �����\n4) �����\nĳ� - ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				count=add_el();
				break;
			}
			case 2:
			{
				
				print(count);
				break;
			}			
			case 3:
			{
				sort(count);
				print(count);
				break;
			}
			default:
			{
				choice=0;
				break;
			}
		}
	}
	getchar();
	getchar();
}
