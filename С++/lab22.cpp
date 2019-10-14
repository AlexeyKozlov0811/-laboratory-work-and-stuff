#include <iostream>
#include <limits>
#include <math.h>

#define A 32.22
#define B 3.31
#define C 6

using namespace std;
float valid(char message[])
{
	float i;
    bool good=true;
    do
    {
        cout<<message;
        cin>>i;
        if (!(good=cin.good()))
            cout<<"Помилка вводу"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }while(!good);
	return i;
}
float t1()
{
	cout<<"Функція №1\nОбласть допустимих значень: у=/=0 та х*у<-"<<C<<endl;
	float x=valid("Введіть х\nх = ");
	float y=valid("Введіть у\ny = ");
	float result=0;
	if(!y)
		cout<<"у не належить ОДЗ\n";
	else
	{
		float un_lo;
		if((un_lo=y*x+C)<=0)
			cout<<"x або у не належать ОДЗ\n";
		else
		{
			result=A*x/y+B/pow(y,2)*log10(un_lo);
			cout<<"Результат = "<<result<<endl;
		}
	}
	return result;
}
float t2()
{
	float root=sqrt(pow(C,2)-pow(B,2));
	float result=0;
	cout<<"Функція №2\nОбласть допустимих значень: x є ( 0.4+3.9*n ; 3.5+3.9*n ) n є Z\n";
	float x=valid("Введіть х\nх = ");
	float un_lo=(root*tan(A*x)+2)/(root*tan(A*x)-2);
	if(un_lo<=0)
		cout<<"x не належить ОДЗ\n";
	else
	{
		result=1/(2*A*B)*log(un_lo);
		cout<<"Результат = "<<result<<endl;
	}
	return result;
}

int main()
{
	system("localiz.exe");
	int key=1;
	cout<<"Вітаємо в програмі\n";
	getchar();
	while(key!=0)
	{
		system("cls");
		key=valid("Оберіть дію\n1) Обрахувати за функцією 1\n2) Обрахувати за функцією 2\n3) Вийти з програми\nДія - ");
		switch(key)
		{
			case 1:
			{
				t1();
				break;
			}
			case 2:
			{
				t2();
				break;
			}
			default:
			{
				key=0;
				break;
			}
		}
		getchar();
	}
    
}


























