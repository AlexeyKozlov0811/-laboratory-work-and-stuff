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
		cout << "������ ������ (� - ��������, � - �������): ";
		cin >> book[i].position;
		if (book[i].position != '�' && book[i].position != '�')
		{
			cout << "���� ������ �1\n�� ����: ����� ������ ���� ������ '�' ��� '�'\n" << endl;
		}
		else
		{
			cout << "���� ������ �1\n³���\n" << endl;
		}
		cout << "������ �������: ";
		scanf("%s", book[i].name);
		int str = strlen(book[i].name);
		for (int j = 0; j < str; j++)
		{
			if (iswalnum(book[i].name[j]))//iswalnum �������� �������� �������� �������
			{
				cout << "���� ������ �2\n�� ����: ����� ������ ���� �����\n" << endl;
			}
			else
			{
				cout << "���� ������ �2\n³���\n" << endl;
			}
		}
		cout << "������ ��������� ������: ";
		scanf("%s", book[i].email);
		int mail = strlen(book[i].email);
		for (int j = 0; j < mail; j++)
		{
			if (book[i].email[j] >= '�' && book[i].email[j] <= '�')
			{
				cout << "���� ������ �3\n�� ����: ����� ������ ���� ��������\n" << endl;
				break;
			}
			else
			{
				cout << "���� ������ �3\n³���\n" << endl;
			}
		}


		cout << "������ ����� ��������: ";
		while (!(cin >> book[i].phone_number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			if (!(isdigit(book[i].phone_number)))//iswalnum �������� �������� ���������� �������
			{
				cout << "���� ������ �4\n�� ����: ����� ������ ���� �����\n" << endl;
				break;
			}
		}
		cout << "���� ������ �4\n³���\n" << endl;		
		cout << "\n������ �� ������ ���?\n1 - ���\n0 - �\n\n";
		cout << ">> ";
		cin >> choice;
		if (choice != 1 || choice != 0)
		{
			cout << "���� ������ �5\n�� ����: ����� ������ ���� 1 ��� 0\n" << endl;//
		}
		else
		{
			cout << "���� ������ �5\n³���\n" << endl;
		}
		cout << endl;
		if (choice == 0)
		{
			break;
		}
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
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "³����� � �������. ���� �����, �������� �������." << endl;
	new_el();
	cout << "��� ���������� �������� Enter" << endl;

	getchar();
	getchar();
}