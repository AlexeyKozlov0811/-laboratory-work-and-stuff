#include <iostream>  
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>

using namespace std;

struct reference_book 
{
	char position;
	char name[30];
	char email[20];
	int phone_number;

};

struct reference_book book[10];

void new_el()
{
	int choice = -1, choice2 = -1;
	int count = 0;
	for (int i = 0; (i<10); i++)
	{
		cout << "Введіть посаду (в - викладач, с - студент): ";
		cin >> book[i].position;
		if (book[i].position != 'с' && book[i].position != 'в')
		{
			cout << "Тест скрипт №1\nНе вірно: можна ввести лише символ 'в' або 'с'\n" << endl;
		}
		else
		{
			cout << "Тест скрипт №1\nВірно\n" << endl;
		}
		cout << "Введіть прізвище: ";
		scanf("%s", book[i].name);
		int str = strlen(book[i].name);
		for (int j = 0; j < str; j++)
		{
			if (iswalnum(book[i].name[j]))//iswalnum перевіряє наявність числових значень
			{
				cout << "Тест скрипт №2\nНе вірно: можна ввести лише літери\n" << endl;
			}
			else
			{
				cout << "Тест скрипт №2\nВірно\n" << endl;
			}
		}
		cout << "Введіть електрону адресу: ";
		scanf("%s", book[i].email);
		int mail = strlen(book[i].email);
		for (int j = 0; j < mail; j++)
		{
			if (book[i].email[j] >= 'А' && book[i].email[j] <= 'я')
			{
				cout << "Тест скрипт №3\nНе вірно: можна ввести лише латиницю\n" << endl;
				break;
			}
			else
			{
				cout << "Тест скрипт №3\nВірно\n" << endl;
			}
		}


		cout << "Введіть номер телефону: ";
		while (!(cin >> book[i].phone_number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			if (!(isdigit(book[i].phone_number)))//iswalnum перевіряє наявність символьних значень
			{
				cout << "Тест скрипт №4\nНе вірно: можна ввести лише цифри\n" << endl;
				break;
			}
		}
		cout << "Тест скрипт №4\nВірно\n" << endl;		
		cout << "\nБажаєте ще додати дані?\n1 - так\n0 - ні\n\n";
		cout << ">> ";
		cin >> choice;
		if (choice != 1 || choice != 0)
		{
			cout << "Тест скрипт №5\nНе вірно: можна ввести лише 1 або 0\n" << endl;//
		}
		else
		{
			cout << "Тест скрипт №5\nВірно\n" << endl;
		}
		cout << endl;
		if (choice == 0)
		{
			break;
		}
		count++;
	}
	cout << "Бажаєте вивести таблицю на екран?\n1 - так\n0 - ні\n" << endl;
	cout << ">> ";
	cin >> choice;
	if (choice != 0)
	{
		system("CLS");
		print(count);
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "Вітаемо в програмі. Будь ласка, заповніть таблицю." << endl;
	new_el();
	cout << "Для завершення натисніть Enter" << endl;

	getchar();
	getchar();
}