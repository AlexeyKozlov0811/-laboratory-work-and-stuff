#include<iostream>
using namespace std;


class complex
{
	float real, imaginable;

	public:
	complex(){real=imaginable=0;}
	complex(float i, float j) {real=i; imaginable=j;}
	complex(const complex &copied_from) {cout<<"cop"<<endl;real=copied_from.real; imaginable=copied_from.imaginable;}
	
	complex& operator+(complex& op2);
	complex& operator-(complex& op2);
	complex& operator*(complex& op2);
	complex& operator/( complex& op2);
	complex& operator=(complex& op2);
	bool operator==(complex& op2);
	
	void show();
};

complex& complex::operator+(complex& op2)
{
	complex temp;
	
	temp.real=real+op2.real;
	temp.imaginable=imaginable+op2.imaginable;
	
	return temp;
}

complex& complex::operator-(complex& op2)
{
	complex temp;
	
	temp.real=real-op2.real;
	temp.imaginable=imaginable-op2.imaginable;
	
	return temp;
}

complex& complex::operator*(complex& op2)
{
	complex temp;
	
	temp.real=real*op2.real-imaginable*op2.imaginable;
	temp.imaginable=real*op2.imaginable+imaginable*op2.real;
	
	return temp;
}

complex& complex::operator/( complex& op2)
{
	complex temp;
	
	if (op2.real!=0 || op2.imaginable!=0)
	{
		temp.real=(real*op2.real+imaginable*op2.imaginable)/(op2.real*op2.real+op2.imaginable*op2.imaginable);
		temp.imaginable=(imaginable*op2.real-real*op2.imaginable)/(op2.real*op2.real+op2.imaginable*op2.imaginable);
		
	}
	else
		cout<<"Second operand is equal to 0"<<endl;
	return temp;
}

complex& complex::operator=(complex& op2)
{	
	real=op2.real;
	imaginable=op2.imaginable;
	
	return *this;
}

bool complex::operator==(complex& op2)
{
	if ((real == op2.real) && (imaginable == op2.imaginable))
		return true;
	else
		return false;
}

void complex::show()
{
	cout<<"complex digit = "<<real;
	if (imaginable>=0)
		cout<<'+';
	cout<<imaginable<<"i"<<endl;
}


int main()
{
	complex z1(5,5), z2(5,5), z3(-65,22.22), z4,z5;
	//complex z5(z2);
	z1=z1;
	/* z1=z1+z2;
	z1=z1-z2;
	z1=z1/z2; */
	z3=z1-z2;
	z3.show();
	z3=z1+z2;
	z3.show();
	/* 	z1.show();
	z2.show();
	z3.show();
	z4.show();
	z5.show();
	
	z1=z1+z2;
	z1.show();
	
	z3=z1*z3;
	z3.show();
	
	z3=z3/z1;
	z3.show();
	
	z1=z1-z2;
	z1.show();
	z1.show();
	if (z5==z2) cout<<"z5=z2"<<endl;
	else cout<<"z5!=z2"<<endl;
	
	if (z5==z3) cout<<"z5=z3"<<endl;
	else cout<<"z5!=z3"<<endl;
	
	z5=z3;
	
	if (z5==z3) cout<<"z5=z3"<<endl;
	else cout<<"z5!=z3"<<endl;
	z1.show();
	z1=z1/z4;
	z1.show(); */
}















