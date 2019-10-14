#include<iostream>

using namespace std;

class helicopter;

class plane
{
	int speed,lifting_capacity;
	public:
	friend void compare(plane&, helicopter&);
	plane()
	{
		cout<<"Enter the speed of the plane: ";
		cin>>speed;
		cout<<"Enter the lifting capacity of the plane: ";
		cin>>lifting_capacity;
	}
};

class helicopter
{
	int speed,lifting_capacity;
	public:
	friend void compare(plane&, helicopter&);
	helicopter()
	{
		cout<<"Enter the speed of the helicopter: ";
		cin>>speed;
		cout<<"Enter the lifting capacity of the helicopter: ";
		cin>>lifting_capacity;
	}
};

void compare(plane& plane_cmp, helicopter& helicopter_cmp)
{
	if (plane_cmp.speed>helicopter_cmp.speed)
		cout<<"Plane is faster"<<endl;
	else if(plane_cmp.speed<helicopter_cmp.speed)
		cout<<"Helicopter is faster"<<endl;
	else
		cout<<"They are equally fast"<<endl;
	
	if (plane_cmp.lifting_capacity>helicopter_cmp.lifting_capacity)
		cout<<"Plane can lift more"<<endl;
	else if(plane_cmp.lifting_capacity<helicopter_cmp.lifting_capacity)
		cout<<"Helicopter can lift more"<<endl;
	else
		cout<<"Lifting capacity is equal"<<endl;
}

int main()
{
	plane plane1;
	helicopter helicopter1;
	compare(plane1, helicopter1);
}