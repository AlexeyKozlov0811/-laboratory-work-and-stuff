#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int fiz=0,s,t,h;
	ifstream base3("D:\\pr\\base3.txt");
	if(!base3)
	{
		cout<<"Немає доступу до бази\n";
	}
	else
	{
		base3>>fiz;
		base3.close();
		s=fiz&31;
		t=(fiz>>5)&511;
		h=(fiz>>14)&3;
		cout<<"номер сектора = "<<s<<endl<<"номер доріжки = "<<t<<endl<<"номер головки диску = "<<h<<endl;
	}
	getchar();
}