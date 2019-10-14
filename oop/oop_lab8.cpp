#include<iostream>
#include<cmath>
#include <fstream>

using namespace std;

int main()
{
	int value=100;
	int flags_state=cout.setf(0);
	cout<<value<<endl;
	
	cout.unsetf(ios::dec);
	cout.setf(ios::hex|ios::showbase);
	
	cout<<value<<endl;
	
	cout.setf(flags_state);
	
	cout<<value<<endl;
	
	cout<<hex<<showbase<<value<<endl;
	//cout<<noshowbase<<value<<endl;
	cout<<dec<<value<<endl;
	
	cout<<"natural logarithm from 2 to 100"<<endl;
	
	for(int i=2;i<=100;i++)
	{
		cout.setf(ios::left);
		cout.fill('-');
		cout.width(10);
		cout.precision(5);
		cout<<log(i)<<endl;
	}
	
	cout<<endl<<"decimal logarithm from 2 to 100"<<endl;
	
	for(int i=2;i<=100;i++)
	{
		cout.setf(ios::left);
		cout.fill('-');
		cout.width(10);
		cout.precision(5);
		cout<<log10(i)<<endl;
	}
	
	ifstream file("oop_lab8.txt");
	if(!file.is_open())
	{
		cerr<<"file is absent";
	}
	else
	{
		char buff[1000];
		int words=0;
		while(file>>buff) ++words;
		cout<<endl<<"Number of words = "<<words<<endl;
		file.close();
	}
}