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
            cout<<"������� �����"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }while(!good);
	return i;
}
float t1()
{
	cout<<"������� �1\n������� ���������� �������: �=/=0 �� �*�<-"<<C<<endl;
	float x=valid("������ �\n� = ");
	float y=valid("������ �\ny = ");
	float result=0;
	if(!y)
		cout<<"� �� �������� ���\n";
	else
	{
		float un_lo;
		if((un_lo=y*x+C)<=0)
			cout<<"x ��� � �� �������� ���\n";
		else
		{
			result=A*x/y+B/pow(y,2)*log10(un_lo);
			cout<<"��������� = "<<result<<endl;
		}
	}
	return result;
}
float t2()
{
	float root=sqrt(pow(C,2)-pow(B,2));
	float result=0;
	cout<<"������� �2\n������� ���������� �������: x � ( 0.4+3.9*n ; 3.5+3.9*n ) n � Z\n";
	float x=valid("������ �\n� = ");
	float un_lo=(root*tan(A*x)+2)/(root*tan(A*x)-2);
	if(un_lo<=0)
		cout<<"x �� �������� ���\n";
	else
	{
		result=1/(2*A*B)*log(un_lo);
		cout<<"��������� = "<<result<<endl;
	}
	return result;
}

int main()
{
	system("localiz.exe");
	int key=1;
	cout<<"³���� � �������\n";
	getchar();
	while(key!=0)
	{
		system("cls");
		key=valid("������ ��\n1) ���������� �� �������� 1\n2) ���������� �� �������� 2\n3) ����� � ��������\nĳ� - ");
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


























