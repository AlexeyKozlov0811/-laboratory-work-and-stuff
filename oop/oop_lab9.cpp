#include <iostream>
#include <chrono>
#include <time.h> 

using namespace std;

class Sys_time
{
	struct tm *Time;
public:
	friend ostream &operator<<(ostream &stream, Sys_time obj);
	Sys_time()
	{
		time_t rawtime;
		time (&rawtime);
		Time=localtime(&rawtime);
	}
};

ostream &operator<<(ostream &stream, Sys_time obj)
{	
	stream<<obj.Time->tm_hour<<":"<<obj.Time->tm_min<<":"<<obj.Time->tm_sec<<endl;
	return stream;
}

class pwr 
{
	int base;
	int exponent;
	int result=1;
public:
	friend ostream &operator<<(ostream &stream, pwr obj);
	friend istream &operator>>(istream &stream, pwr &obj);
	pwr(int b, int e)
	{
		base=b;
		exponent=e;
		for(;e;e--) 
			result=result*base;
	}
};

ostream &operator<<(ostream &stream, pwr obj)
{
	stream<<obj.result<<" = 1*"<<obj.base<<"^"<<obj.exponent<<endl;
	return stream;
}

istream &operator>>(istream &stream, pwr &obj)
{
	int e;
	stream >> obj.base >> e;
	obj.exponent=e;
	obj.result=1;
	for (;e;e--)
		obj.result=obj.result*obj.base;
	return stream;
}

ostream &sethex(ostream &stream)
{
	stream.unsetf(ios::dec);
	stream.setf(ios::hex|ios::uppercase|ios::showbase);
	return stream;
};

ostream &result(ostream &stream)
{
	stream.setf(ios::dec);
	return stream;
};

int main()
{
	Sys_time tm;
	cout<<tm;
	pwr a(2,2);
	cout<<a;
	cin>>a;
	cout<<a;
	cout<<sethex<<100<<endl;
	cout<<result<<100<<endl;
}