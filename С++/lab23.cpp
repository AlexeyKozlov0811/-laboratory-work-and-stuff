#include <iostream>
#include <limits>
#include <math.h>

#define A 9.1
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

void print_str(char a[], char b[], char c[])
{
	printf("\n\t|%-4s|%-15s|%-49s|\n",a,b,c);
	printf("\t|");
	for(int i=0;i<4;i++)
			printf("_");
	printf("|");
	for(int i=0;i<15;i++)
		printf("_");
	printf("|");
	for(int i=0;i<49;i++)
		printf("_");
	printf("|");
}
void show()
{
	char a[]="№";
	char b[]="Тип";
	char c[]="Вираз";
	char da[]="1";
	char db[]="логарифм";
	char dc[]="t=1/(b^3)*(ln(y/x – a^2*x^2/(2*y^2)))";
	
	char ea[]="2";
	char eb[]="корінь";
	char ec[]="t=1/(b^0,5)*(y^0,5/x – a^0,5*x^2/(2*y^0,5)))";
	
	char fa[]="3";
	char fb[]="тригонометрія";
	char fc[]="t=cos(bx+0,5)*sin(y/x – a^0,5*x^2)";	
	
	printf("\t ");
	for(int i=0;i<70;i++)
		printf("_");	
	print_str(a,b,c);
	print_str(da,db,dc);
	print_str(ea,eb,ec);
	print_str(fa,fb,fc);
}

float t1()
{
	cout<<"Функція №1\n";
	float result=0;
	float x=valid("Введіть х\nх = ");
	float y=valid("Введіть у\ny = ");
	if(x!=0&&y!=0&&(y/x-pow(A,2)*pow(x,2)/(2*pow(y,2)))>0)
	{
		result=1/pow(B,3)*log(y/x-pow(A,2)*pow(x,2)/(2*pow(y,2)));
		cout<<"Результат = "<<result;
	}
	else
		cout<<"x або у не належать ОДЗ\n";
	return result;
}
float t2()
{
	cout<<"Функція №2\n";
	float result=0;
	float x=valid("Введіть х\nх = ");
	float y=valid("Введіть у\ny = ");
	if(x!=0&&y>0)
	{
		result=1/sqrt(B)*(sqrt(y)/x-sqrt(A)*pow(x,2)/(2*sqrt(y)));
		cout<<"Результат = "<<result;
	}
	else
		cout<<"x або у не належать ОДЗ\n";
	return result;
}
float t3()
{
	cout<<"Функція №3\n";
	float result=0;
	float x=valid("Введіть х\nх = ");
	float y=valid("Введіть у\ny = ");
	if(x!=0)
	{
		result=cos(B*x+0.5)*sin(y/x-sqrt(A)*pow(x,2));
		cout<<"Результат = "<<result;
	}
	else
		cout<<"x не належить ОДЗ\n";
	return result;
}

void choose()
{
	show();
	char func[16];
	cout<<"\nОберіть функцію за номером або типом виразу\nФункція - ";
	cin>>func;
	if(func[0]=='1'||!(strcmp(func,"логарифм")))
		t1();
	else if(func[0]=='2'||!(strcmp(func,"корінь")))
		t2();
	else if(func[0]=='3'||!(strcmp(func,"тригонометрія")))
		t3();
	else
		cout<<"Функію не обрано";
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
		key=valid("Оберіть дію\n1) Показати таблицю з функціями\n2) Обрати функцію\n3) Вийти з програми\nДія - ");
		switch(key)
		{
			case 1:
			{
				show();
				break;
			}
			case 2:
			{
				choose();
				break;
			}
			default:
			{
				key=0;
				break;
			}
		}
		getchar();
		getchar();
	}
}




































