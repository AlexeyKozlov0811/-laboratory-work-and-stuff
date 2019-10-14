//Заввдання №1
#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>
#include <Windows.h>

using namespace std;


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	int n;
	int *arr;

	n = rand() % 151+50;

	cout << "Hозмірніть квадратної матриці: " << n << endl;
	

	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		*(arr+i) = rand() % 101-50;
	}

	for (int i = 0; i < n; i++)
	{
			printf("%3d ", *(arr + i));
		}
		cout << endl << endl;


		int same = 0;

	for (int i = 0; i < n; i++)
	{
		if (*(arr+i) == *(arr + i + 1))
			same++;
	}

	cout <<"Кількість однакових елементів, що знаходяться поруч: "<< same << endl;

		delete[]arr;
		system("pause");

}

