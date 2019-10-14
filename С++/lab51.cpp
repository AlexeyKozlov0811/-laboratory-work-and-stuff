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
	cout<<"Вітаємо в програмі\n";
	while(key!=0)
	{
		cout<<"Оберіть дію\n1) Сгенерувати масив\n2) Підрахувати кількість пар сусідніх елементів з однаковими значеннями\n3) Вийти із програми\nДія = ";
		cin>>key;
		switch(key)
		{
			case 1:
			{
				n=rand()%150+50;
				cout<<"Розмір масиву: "<<n<< endl;
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
				cout <<"\nКількість пар сусідніх елементів з однаковим значенням: "<<same<<endl<<endl;
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

