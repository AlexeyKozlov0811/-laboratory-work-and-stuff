#include<iostream>
#include<time.h>
#include<windows.h>
#include<string.h>
using namespace std;
class Rahunok
{
	unsigned int id;
	protected:
	unsigned int value;
	float percentage;
	
	Rahunok(unsigned int value_inp, float percentage_inp)
	{
		cout<<"Rahunok constructor"<<endl;
		id=rand()%999999+100000;
		value=value_inp;
		if(percentage_inp<0)
			percentage_inp+=-(percentage_inp*2);
		if(percentage_inp>1)
			percentage_inp-=1;
		percentage=percentage_inp;
	}
	void show_Rah()
	{
		cout<<"id: "<<id<<endl;
		cout<<"account: "<<value<<endl;
		cout<<"percentage: "<<percentage<<endl;
	}
	void new_percentage(float n_percentage)
	{
		percentage=n_percentage;
	}
	public:
	void interest_accrual()
	{
		value=int(value*(1+percentage));
	}
};

class Vkladnyk
{
	char* name;
	char* Surname;
	char* patronymic;
	unsigned int passport_series,passport_number;
	//public:
	protected:
	Vkladnyk(char name_inp[],char Surname_inp[],char patronymic_inp[], unsigned int passport_series_inp, unsigned int passport_number)
	{
		cout<<"Vkladnyk constructor"<<endl;
		name=name_inp;
		Surname=Surname_inp;
		patronymic=patronymic_inp;
		passport_series=passport_series_inp;
		passport_number=passport_number;
	}
	void show_Vkl()
	{
		cout<<"Surname: "<<Surname<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Patronymic: "<<patronymic<<endl;
		cout<<"Passport series: "<<passport_series<<endl;
		cout<<"Passport number: "<<passport_number<<endl;
	}
};

class RahunokVkladnyka : public Vkladnyk, public Rahunok
{
	unsigned int withdrawal_amount, minimum_account_balance;
	char* password;
	public:
	RahunokVkladnyka(char password_inp[] ,unsigned int withdrawal_amount_inp, unsigned int minimum_account_balance_inp, 
		char name_inp[],char Surname_inp[],char patronymic_inp[], unsigned int passport_series_inp, unsigned int passport_number,
		unsigned int value_inp, float percentage_inp):
		Vkladnyk(name_inp, Surname_inp, patronymic_inp, passport_series_inp, passport_number),
		Rahunok(value_inp, percentage_inp)
	{
		cout<<"RahunokVkladnyka constructor"<<endl<<endl;
		password=password_inp;
		withdrawal_amount=withdrawal_amount_inp;
		minimum_account_balance=minimum_account_balance_inp;
	}
	void show()
	{
		char pass_inp[100];
		cout<<"Input password: ";
		cin>>pass_inp;
		if(!strcmp(password,pass_inp))
		{
			show_Vkl();
			show_Rah();
			cout<<"Withdrawal amount: "<<withdrawal_amount<<endl;
			cout<<"Minimum account balance: "<<minimum_account_balance<<endl;
			cout<<"Password: "<<password<<endl;
		}
		else
		{
			cout<<"Wrong password"<<endl;
		}
	}
	void change_password()
	{
		char pass_inp[100];
		cout<<"Input password: ";
		cin>>pass_inp;
		if(!strcmp(password,pass_inp))
		{
			cout<<"Input new password: ";
			cin>>pass_inp;
			password=pass_inp;
		}
		else
		{
			cout<<"Wrong password"<<endl;
		}
	}
	void invest_money(unsigned int add)
	{
		value+=add;
	}
	void withdraw_money(unsigned int sub)
	{
		char pass_inp[100];
		cout<<"Input password: ";
		cin>>pass_inp;
		if(!strcmp(password,pass_inp))
		{
			if((value>=minimum_account_balance)&&(sub<=withdrawal_amount))
			{
				value-=sub;
			}
			else
				cout<<"too small account balance or too big withdrawal amount"<<endl;
			}
		else
		{
			cout<<"Wrong password"<<endl;
		}
	}
};


int main()
{
	SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	srand(time(NULL));
	
	RahunokVkladnyka RV("123456",100,100,"Валерий","Жмышенко","Альбертович",1234,22222,1000,-1.2);
	RV.show();
	RV.interest_accrual();
	//RV.show_Rah();
}