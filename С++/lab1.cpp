#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <fstream>
#define SIZE 20
using namespace std;

int entrance_check(char login[],char password[],int mode);
void sign_in();

int entrance_check(char login[],char password[],int mode)
{
	char log[SIZE];
	char pass[SIZE];
	ifstream base("D:\\pr\\base.txt");
	if(!base)
		cout<<"Немає доступу до бази\n";
	else
	{
		if(mode==0)
		{
			int found=0;
			while(!base.eof()&&found==0)
			{
				base.getline(log,SIZE,'\n');
				base.getline(pass,SIZE,'\n');
				if(strcmp(login,log)==0)
					found=1;
			}
			if(found==0)
			{
				ofstream base("D:\\pr\\base.txt",ios_base::app);
				base<<login<<endl<<password<<endl;
				
			}
			else
			{
				cout<<"Користувач с таким логіном вже існує\n";
				sign_in();
			}
		}
		if(mode==1)
		{
			int enter=0;
			while(!base.eof())
			{
				base.getline(log,SIZE,'\n');
				base.getline(pass,SIZE,'\n');
				if(strcmp(login,log)==0)
					if(strcmp(password,pass)==0)
						enter=1;
					else
						enter=0;
			}
			if(enter==1)
				return 1;
		}
		base.close();
	}
	return 0;
}
void sign_in()
{
	char login[SIZE];
	char password[SIZE];	
	cout<<"Для реєстрації в системі введіть логін і пароль\nЛогін: ";
	cin>>login;
	cout<<"Пароль: ";
	cin>>password;
	entrance_check(login,password,0);
}
void change_password(char login[])
{
	ofstream base("D:\\pr\\base.txt",ios_base::app);
	if(!base)
		cout<<"Немає доступу до бази\n";
	else
	{
		char new_pass[SIZE];
		if(strcmp(login,"admin")==0)
		{
			char some_login[SIZE];
			cout<<"Введіть логін користувача\nЛогін: ";
			cin>>some_login;
			base<<some_login<<endl;
		}
		else
			base<<login<<endl;
		cout<<"Введіть новий пароль\nПароль: ";
		cin>>new_pass;
		base<<new_pass<<endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key_enter=0;
	int key_do=3;
	int attempt=0;
	char login[SIZE];
	char password[SIZE];
	cout<<"Вітаємо в програмі, оберіть дію\n1)Реєстрація\n2)Вхід в систему\n3)Вихід з програми\n";
	cin>>key_do;
	switch (key_do)
	{
		case 1:
		{
			sign_in();
		}
		case 2:
		{
			cout<<"Введіть логін і пароль\n";
			while(attempt!=3&&key_enter==0)
			{
				cout<<"Логін: ";
				cin>>login;
				cout<<"Пароль: ";
				cin>>password;
				attempt++;				
				if(entrance_check(login,password,1)==1)
					key_enter=1;
				else
					cout<<"Невірний логін чи пароль\n";
			}
			if(key_enter==0)
			{
				cout<<"Спроба несанкціонованого доступу ";
			}
			else
			{
				int key=2;
				cout<<"Вітаємо в системі, оберіть дію\n1)Змінити пароль\n2)Вийти з програми\n";
				cin>>key;
				if(key==1)
					change_password(login);
			}
			break;
		}
	}
}