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
	int key=-1;
	cout<<"³���� � �������\n";
	while(key!=0)
	{
		cout<<"������ ��\n1) ����������� �����\n2) ϳ��������� ������� ��� ������ �������� � ���������� ����������\n3) ����� �� ��������\nĳ� = ";
		cin>>key;
		switch(key)
		{
			case 1:
			{
				n=rand()%150+50;
				cout<<"����� ������: "<<n<< endl;
				arr=new int[n];
				for(int i=0;i<n;i++)
				{
					*(arr+i)=rand()%100-50;
				}
				for(int i=0;i<n;i++)
				{
					printf("%d ",*(arr+i));
				}
				cout<<endl<<endl;
				break;
			}
			case 2:
			{
				int same=0;
				for(int i=0;i<n;i++)
				{
					if (*(arr+i)==*(arr+i+1))
						same++;
				}
				cout <<"\nʳ������ ��� ������ �������� � ��������� ���������: "<<same<<endl<<endl;
				break;
			}
			default:
			{
				key=0;
				break;
			}
		}
	}
	delete[]arr;
	getchar();
	getchar();
}

