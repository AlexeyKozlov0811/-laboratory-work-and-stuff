#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int fiz=0,s,t,h;
	ifstream base3("D:\\pr\\base3.txt");
	if(!base3)
	{
		cout<<"���� ������� �� ����\n";
	}
	else
	{
		base3>>fiz;
		base3.close();
		s=fiz&31;
		t=(fiz>>5)&511;
		h=(fiz>>14)&3;
		cout<<"����� ������� = "<<s<<endl<<"����� ������ = "<<t<<endl<<"����� ������� ����� = "<<h<<endl;
	}
	getchar();
}