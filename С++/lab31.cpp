#include <iostream>
#include <fstream>
using namespace std;
//s 5
//t 9
//h 2
int valid(char message[])
{
	int i;
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
int main()
{ 
	system("localiz.exe");
	int fiz=0,key=1;
	cout<<"³���� � �������\n";
	while(key!=0)
	{
		cout<<"������ ��\n1) ���������� ����������\n2) ����������� ����������\n3) ����� �� ��������\nĳ� = ";
		cin>>key;
		switch(key)
		{
			case 1:
			{
				int s=-1,t=-1,h=-1;
				while(!(s>=0&&s<=31))
					s=valid("������ ����� ������� (0-31)>");
				while(!(t>=0&&t<=511))
					t=valid("������ ����� ������ (0-511)>");
				while(!(h>=0&&h<=3))
					h=valid("������ ����� ������� ����� (0-3)>");
				fiz=s&0x1F;
				fiz=fiz|(t<<5);
				fiz=fiz|((h&0xFF)<<14);
				ofstream base3("D:\\pr\\base3.txt");
				if(!base3)
				{
					cout<<"���� ������� �� ����\n";
				}
				else
				{
					base3<<fiz;
					base3.close();
				}
				getchar();
				break;
			}
			case 2:
			{
				printf("���������� ���������� = %04x\n",fiz);
				system("lab32.exe");
				break;
			}
			default:
			{
				key=0;
				break;
			}
		}
	}
}