#include "pch.h"
#include "Garage_parking.h"
#include <assert.h>
#include <iostream>
#include <conio.h> 
#include <string.h>
#include <string>
#define N 10
using namespace std;



Garage_parking::Garage_parking()
{
	number_of_parking_places = 0;
}

char &Garage_parking::operator[](int index)
{
	assert(index >= 0 && index < number_of_parking_places);
	return data[index];
}

Garage_parking::Garage_parking(int places)
{
	number_of_parking_places = places;

	assert(number_of_parking_places >= 0);

	if (number_of_parking_places > 0)
		data = new char[number_of_parking_places];
	else
		data = nullptr;
}

void Garage_parking::erase()//������� ����������
{
	delete[] data;
	// ����� ����� ������� data �������� nullptr, ����� �� ������ �� ���� �������� ���������
	data = nullptr;
	number_of_parking_places = 0;
}

void Garage_parking::insertBefore(char value, int index)//�������� �������� ����� ��������� � �������� ��������
{
	assert(index >= 0 && index <= number_of_parking_places);// �������� ������������ ������������� �������

		char *data_new = new char[number_of_parking_places + 1];// ������� ����� ������ �� ���� ������� ������ ������� �������

		for (int before = 0; before < index; ++before)// �������� ��� �������� �� �� index-�
			data_new[before] = data[before];

		data_new[index] = value;// ��������� ��� ����� ������� � ��� ����� ������

		for (int after = index; after < number_of_parking_places; ++after)// �������� ��� �������� ����� ������������ ��������
			data_new[after + 1] = data[after];
	

		delete[] data;// ������� ������ ������ � ���������� ������ ���� ����� ������
		data = data_new;
		++number_of_parking_places;
	
}

void Garage_parking::remove(int index)//�������� �������� � �������� ��������
{
	assert(index >= 0 && index < number_of_parking_places);// �������� �� ������������ ������������� �������

	if (number_of_parking_places == 1)// ���� ��� ��������� ������� �������, �� ������ ������ ������ � return
	{
		erase();
		return;
	}
	
	char *data_new = new char[number_of_parking_places - 1];// C������ ����� ������ �� ���� ������� ������ ������� �������

	for (int before = 0; before < index; ++before)// �������� ��� �������� �� �� index-�
		data_new[before] = data[before];

	for (int after = index + 1; after < number_of_parking_places; ++after)// �������� ��� �������� ����� ���������� ��������
		data_new[after - 1] = data[after];

	delete[] data;// ������� ������ ������ � ���������� ������ ���� ����� ������
	data = data_new;
	--number_of_parking_places;
}

int Garage_parking::get_number_of_places()//���������� ������ �������
{
	return number_of_parking_places; 
}

void Garage_parking::show_garage(Garage_parking &obj)//������� �� ����� �����
{
	for (int j = 0; j < obj.get_number_of_places(); j++)
		std::cout << obj[j];
}

int Garage_parking::entry(char value, int index_needed, Garage_parking &obj)//������� ����� � �����
{
	getchar();
	system("cls");
	obj.show_garage(obj);
	std::cout << "\n";

	char temp=' ';
	int index=-1;

	for (int i = 0; i < index_needed + 1; i++)
	{
		getchar();
		system("cls");
		if (obj.data[i ] != '-' && obj.data[i ] != '|')
		{
			temp = obj.data[i ];
			index = i ;
		}
		obj.insertBefore(value, i);
		obj.remove(i + 1);
		if (i == 1)
		{
			obj.data[0] = '|';
		}
		else if (i > 1)
		{
			obj.data[i - 1] = '-';
		}		
		if (temp != ' ' && i > index)
		{
			obj.data[index] = temp;
		}
		obj.show_garage(obj);

		std::cout << "\n";
	}
	getchar();
	system("cls");
	obj.show_garage(obj);
	std::cout << "\nVehicle " << value << " has arrived\n";
	return 0;
}

int Garage_parking::departure(char value, int index_needed, Garage_parking &obj)//������ �� ������
{
	char temp = ' ';
	int index = -1;
	for (int i = index_needed; i < number_of_parking_places; i++)
	{
		getchar();
		system("cls");
		
		if (obj.data[i] != '-' && obj.data[i] != '|')
		{
			temp = obj.data[i];
			index = i;
		}
		obj.insertBefore(value, i);
		obj.remove(i + 1);
		if (i == number_of_parking_places)
		{
			obj.data[i] = '|';
		}
		else if (i > index_needed)
		{
			obj.data[i - 1] = '-';
		}
		if (temp != ' ' && temp != value && i > index)
		{
			obj.data[index] = temp;
		}
		obj.show_garage(obj);
		std::cout << "\n";
	}
	obj.data[number_of_parking_places - 1] = '|';
	getchar();
	system("cls");
	obj.show_garage(obj);
	std::cout << "\nVehicle " << value << " has departed\n";
	return 0;
}

int Garage_parking::available_places(Garage_parking &obj)//���������� ��������� ����������� ����
{
	int counter = 0;
	
	for (int i = 0; i < obj.number_of_parking_places; i++)
	{
		if (obj.data[i] != '-' && obj.data[i] != '|')
			counter++;
	}

	return number_of_parking_places - 2 - counter;
}

std::string Garage_parking::vehicles_in_the_garage(Garage_parking &obj)//���������, ������� ��������� � ������
{
	string vehicles = " ";
	for (int i = 0; i < obj.number_of_parking_places; i++)
	{
		if (obj.data[i] != '-' && obj.data[i] != '|')
		{
			vehicles += obj.data[i];
			vehicles += " ";
		}
	}
	return vehicles;
}

void Garage_parking::info_about_vehicle(Garage_parking &obj, char vehicle)//���������� � ���������� ���������� � ������
{
	int flag = 0, number_of_place=0;
	for (int i = 0; i < obj.number_of_parking_places; i++)
	{
		if (obj.data[i] == vehicle)
		{
			flag = 1;
			number_of_place = i;
		}
	}
	if (flag==1)
	{
		std::cout << "Vehicle " << vehicle << " is in the garage\nIt stands at the "<< number_of_place<<" parking place\n";
	}
	else
		std::cout << "Vehicle " << vehicle << " is absent\n";
}

Garage_parking::~Garage_parking()
{
	delete[] data;
}

