#include <iostream>
using namespace std;

template <typename TYPE>
TYPE min(TYPE x, TYPE y, TYPE z)
{
	TYPE temp = x;
	if(temp > y)
		temp = y;
	if(temp > z)
		temp = z;
	return temp;
}

template <typename TYPE>
TYPE max(TYPE x, TYPE y, TYPE z)
{
	TYPE temp = x;
	if(temp < y)
		temp = y;
	if(temp < z)
		temp = z;
	return temp;
}

int min(int x, int y, int z)
{
	int temp = x;
	if(temp > y)
		temp = y;
	if(temp > z)
		temp = z;
	return temp;
}


void main()
{
	double a = min(0.75, 145.0, 0.8);
	char b = max('1', '3', '0');
	int c = min(4, 1, -4);
	cout << a << endl << b << endl << c << endl;

}

