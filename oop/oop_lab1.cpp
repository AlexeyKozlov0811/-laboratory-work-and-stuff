#include <iostream>
#include <string>
#define FIELDS 3

using namespace std;

class data_object
{
	private:
		std::string name;
		std::string adress;
	public:
		void input_information();
		void print_information();
};

void data_object::input_information()
{
	cout<<"Input name: ";
	cin>>name;
	cout<<"Input address: ";
	cin>>adress;
}

void data_object::print_information()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Address: "<<adress<<endl;
}

int main()
{
	data_object data_base[FIELDS];
	for(int i=0;i<FIELDS;i++)
	{
		cout<<i+1<<')'<<endl;
		data_base[i].input_information();
	}
	cout<<endl;
	for(int i=0;i<FIELDS;i++)
	{
		cout<<i+1<<')'<<endl;
		data_base[i].print_information();
	}
	return 0;
}