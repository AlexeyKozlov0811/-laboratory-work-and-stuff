#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

using namespace std;

void Copies(string* s, string* s1, int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		*s1 += *s;

	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string string1 = "";
	string string2 = "";
	int number = 0;
	cout << "Введіть рядок: ";
	getline(cin, string1);
	cout << "Скільки разів потрібно скопіювати рядок в інший: ";
	cin >> number;
	
	Copies(&string1, &string2, number);
	
	printf("\n%s \n\n", string2);

	cout << "Для завершення натисніть Enter" << endl;
	cin.get();
	cin.get();
}

