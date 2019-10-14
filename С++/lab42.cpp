
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
	printf("|Фірми – виробники СКБД                                                                            |\n");
	printf("|__________________________________________________________________________________________________|\n");
	printf("|Фірма               |Кількість продуктів      |Річний об’єм продажу ($) |Частина ринку (%%)        |\n");
	printf("|____________________|_________________________|_________________________|_________________________|\n");
	for (int i = 0; i < a + 1; i++)
	{
		printf("|%-20s|%-25d|%-25d|%-25.2f| \n", SKBD[i].firm, SKBD[i].number_of_products, SKBD[i].annual_sales_volume, SKBD[i].part_of_the_market);
		printf("|____________________|_________________________|_________________________|_________________________|\n");
	}
	printf("|Примітки: за даними Gartner Group за 1999р                                                        |\n");
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
		cout << "Введіть назву фірми: ";
		scanf("%s", SKBD[i].firm);
		cout << "Введіть кількість продуктів: ";
		cin >> SKBD[i].number_of_products;
		/* while (!(cin >> SKBD[i].number_of_products) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Помилка вводу даних!" << endl;
			cout << "Введіть кількість продуктів: ";
		} */

		cout << "Введіть річний об’єм продажу: ";
		cin >> SKBD[i].annual_sales_volume;
		/* while (!(cin >> SKBD[i].annual_sales_volume) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Помилка вводу даних!" << endl;
			cout << "Введіть річний об’єм продажу: ";
		} */
		cout << "Введіть частину ринку (%): ";
		cin >> SKBD[i].part_of_the_market;
		/* while (!(cin >> SKBD[i].part_of_the_market) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Помилка вводу даних!" << endl;
			cout << "Введіть частину ринку (%): ";
		} */

		cout << "\nБажаєте ще додати дані?\n1) так\n2) ні\n";
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
	cout << "Вітаемо в програмі\n";
	int choice = -1;
	int count;
	while(choice != 0)
	{
		cout << "1) Додати елементи до таблиці\n2) Вивести таблицю на екран\n3) Вивести відсортовану за алфавітом таблицю на екран\n4) Вихід\nДія - ";
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
