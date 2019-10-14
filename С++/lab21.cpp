#include <iostream>
//#include <windows.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <limits>

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
void add_el()
{
	char firm[20];//20
	int number_of_products;//5
	int annual_sales_volume;//10
	float part_of_the_market;//2
	ofstream base2("D:\\pr\\base2.txt",ios_base::app);
	if(!base2)
	{
		cout<<"Немає доступу до бази\n";
	}
	else
	{
		cout<<"Введіть назву фірми: ";
		cin>>firm;
		base2<<endl<<firm<<endl;
		number_of_products=valid("Введіть кількість продуктів фірми: ");
		base2<<number_of_products<<endl;
		annual_sales_volume=valid("Введіть річний об'єм продажу фірми (в доларах): ");
		base2<<annual_sales_volume<<endl;
		part_of_the_market=valid("Введіть частину ринку, що належить фірмі (в відсотках): ");
		base2<<part_of_the_market;
		base2.close();
	}
}
void show()
{
	char firm[20];//20
	char number_of_products[19];//5
	char annual_sales_volume[24];//10
	char part_of_the_market[17];//2
	ifstream base2("D:\\pr\\base2.txt");
	if(!base2)
		cout<<"Немає доступу до бази\n";
	else
	{
		char a[]="Фірми виробники СКБД";
		char b[]="Фірма";
		char c[]="Кількість продуктів";
		char d[]="Річний об’єм продажу ($)";
		char e[]="Частина ринку (%)";
		char f[]="Примітки: за даними Gartner Group за 1999р";
		printf("\t ");
		for(int i=0;i<83;i++)
			printf("_");
		printf("\n\t|%-83s|\n",a);
		printf("\t|");
		for(int i=0;i<83;i++)
			printf("_");
		printf("|\n\t|%-20s|%-19s|%-24s|%-17s|\n",b,c,d,e);
		printf("\t|");
		for(int i=0;i<20;i++)
			printf("_");
		printf("|");
		for(int i=0;i<19;i++)
			printf("_");
		printf("|");
		for(int i=0;i<24;i++)
			printf("_");
		printf("|");
		for(int i=0;i<17;i++)
			printf("_");
		printf("|");
		while(!base2.eof())
		{
			base2.getline(firm,30,'\n');
			base2.getline(number_of_products,30,'\n');
			base2.getline(annual_sales_volume,30,'\n');
			base2.getline(part_of_the_market,30,'\n');
			printf("\n\t|%-20s|%-19s|%-24s|%-17s|\n",firm,number_of_products,annual_sales_volume,part_of_the_market);
			printf("\t|");
			for(int i=0;i<20;i++)
				printf("_");
			printf("|");
			for(int i=0;i<19;i++)
				printf("_");
			printf("|");
			for(int i=0;i<24;i++)
				printf("_");
			printf("|");
			for(int i=0;i<17;i++)
				printf("_");
			printf("|");
		}
		printf("\n\t|%-83s|\n\t|",f);
		for(int i=0;i<83;i++)
			printf("_");
		printf("|\n");
	}
}


int main()
{
	/* SetConsoleCP(1251);
	SetConsoleOutputCP(1251); */
	//setlocale(LC_CTYPE, "ukr");
	system("localiz.exe");
	int key_do=1;
	cout<<"Вітаємо в программі\n";
	while(key_do!=0)
	{
		cout<<"Оберіть дію\n1) Додати інформацію до таблиці\n2) Показати таблицю\n3) Для виходу з програми\n";
		cin>>key_do;
		switch(key_do)
		{
			case 1:
			{
				add_el();
				break;
			}
			case 2:
			{
				show();
				break;
			}		
			default:
			{
				key_do=0;
				break;
			}						
		}
	}	
}