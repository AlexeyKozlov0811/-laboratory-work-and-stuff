#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

using namespace std;

void Copies(string *s, string *s1, int n)
{
	for (int i=0;i<n;i++)
	{
		*s1+=*s;
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key=-1;
	cout<<"³���� � �������\n";
	while(key!=0)
	{
		cout<<"������ ��\n1) ��������� �����\n2) ����� �� ��������\nĳ� = ";
		cin>>key;
		cin.ignore(100000, '\n');
		switch(key)
		{
			case 1:
			{
				string st1="";
				string st2="";
				int n=0;
				cout<<"������ �����: ";
				getline(cin,st1);
				cout<<"������ ���� ��������� �����?: ";
				cin>>n;	
				Copies(&st1,&st2,n);	
				printf("\n%s\n",st2);
				break;
			}
			default:
			{
				key=0;
				break;
			}
		}
	}
	getchar();
	getchar();
}

