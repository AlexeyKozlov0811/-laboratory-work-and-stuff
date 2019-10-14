
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
		cout << "1) Перевести число з десяткової в двійкову систему числення\n2) Перевести число з двійкової в десяткову систему числення\n3) Вихід" << endl;
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
	cout << "Десяткове число: ";
	cin >> num;
	cout << "Двійкове число: " << bin_num(num) << endl;
}

void bin_to_dec()
{
	char c;
	int result = 0;
	cout << "Двійкове число: ";	
	while (cin >> c) 
	{
		if ((c<'0') || (c > '1'))
			break;
		result <<= 1;
		result += c - '0';
	}
	cout << "Десяткове число: " << result << endl;
	cin.get();
	cin.get();
}
