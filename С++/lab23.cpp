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
            cout<<"������� �����"<<endl;
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
	char a[]="�";
	char b[]="���";
	char c[]="�����";
	char da[]="1";
	char db[]="��������";
	char dc[]="t=1/(b^3)*(ln(y/x � a^2*x^2/(2*y^2)))";
	
	char ea[]="2";
	char eb[]="�����";
	char ec[]="t=1/(b^0,5)*(y^0,5/x � a^0,5*x^2/(2*y^0,5)))";
	
	char fa[]="3";
	char fb[]="������������";
	char fc[]="t=cos(bx+0,5)*sin(y/x � a^0,5*x^2)";	
	
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
	cout<<"������� �1\n";
	float result=0;
	float x=valid("������ �\n� = ");
	float y=valid("������ �\ny = ");
	if(x!=0&&y!=0&&(y/x-pow(A,2)*pow(x,2)/(2*pow(y,2)))>0)
	{
		result=1/pow(B,3)*log(y/x-pow(A,2)*pow(x,2)/(2*pow(y,2)));
		cout<<"��������� = "<<result;
	}
	else
		cout<<"x ��� � �� �������� ���\n";
	return result;
}
float t2()
{
	cout<<"������� �2\n";
	float result=0;
	float x=valid("������ �\n� = ");
	float y=valid("������ �\ny = ");
	if(x!=0&&y>0)
	{
		result=1/sqrt(B)*(sqrt(y)/x-sqrt(A)*pow(x,2)/(2*sqrt(y)));
		cout<<"��������� = "<<result;
	}
	else
		cout<<"x ��� � �� �������� ���\n";
	return result;
}
float t3()
{
	cout<<"������� �3\n";
	float result=0;
	float x=valid("������ �\n� = ");
	float y=valid("������ �\ny = ");
	if(x!=0)
	{
		result=cos(B*x+0.5)*sin(y/x-sqrt(A)*pow(x,2));
		cout<<"��������� = "<<result;
	}
	else
		cout<<"x �� �������� ���\n";
	return result;
}

void choose()
{
	show();
	char func[16];
	cout<<"\n������ ������� �� ������� ��� ����� ������\n������� - ";
	cin>>func;
	if(func[0]=='1'||!(strcmp(func,"��������")))
		t1();
	else if(func[0]=='2'||!(strcmp(func,"�����")))
		t2();
	else if(func[0]=='3'||!(strcmp(func,"������������")))
		t3();
	else
		cout<<"����� �� ������";
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
		key=valid("������ ��\n1) �������� ������� � ���������\n2) ������ �������\n3) ����� � ��������\nĳ� - ");
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




































