
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>


using namespace std;

using std::cout;
using std::endl;
using std::cin;

string bin_num(int num);
void dec_to_bin();
void bin_to_dec();

	

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice=-1;
	while (choice != 0)
	{
		std::cout << '\a';
		system("cls");
		cout << "1) ��������� ����� � ��������� � ������� ������� ��������\n2) ��������� ����� � ������� � ��������� ������� ��������\n3) �����" << endl;
		cout << ">> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			dec_to_bin();
			cin.get();
			cin.get();
			break;
		}
		case 2:
		{
			bin_to_dec();
			cin.get();
			cin.get();
			break;
		}
		default:
		{
			choice=0;
			break;
		}
		}
	}
	cin.get();
	cin.get();

	return 0;
}

string bin_num(int num) 
{
	string res = "";
	do {
		res += static_cast<char>(num % 2 + '0');
	} while (num /= 2);
	reverse(res.begin(), res.end());
	return res;
}
void dec_to_bin()
{
	int num;
	cout << "��������� �����: ";
	cin >> num;
	cout << "������� �����: " << bin_num(num) << endl;
}

void bin_to_dec()
{
	char c;
	int result = 0;
	cout << "������� �����: ";	
	while (cin >> c) 
	{
		if ((c<'0') || (c > '1'))
			break;
		result <<= 1;
		result += c - '0';
	}
	cout << "��������� �����: " << result << endl;
	cin.get();
	cin.get();
}
