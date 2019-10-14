﻿
#include <iostream>

#include <string>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <conio.h> 


#define N 10
using namespace std;

class Garage_parking
{
private:
	int number_of_parking_places;
	char *data;

public:
	Garage_parking(int places)
	{
		number_of_parking_places = places;
		assert(number_of_parking_places >= 0);
		if (number_of_parking_places > 0)
			data = new char[number_of_parking_places];
		else
			data = nullptr;
	}

	char &operator[](int index);
	int get_number_of_places();
	void erase();
	void insertBefore(char value, int index);
	void remove(int index);

	void show_garage(Garage_parking &obj);

	int entry(char value, int index_needed, Garage_parking &obj);
	int departure(char value, int index_needed, Garage_parking &obj);
	int available_places(Garage_parking &obj);
	string vehicles_in_the_garage(Garage_parking &obj);
	void info_about_vehicle(Garage_parking &obj, char vehicle);

	~Garage_parking();
};

char &Garage_parking::operator[](int index)
{
	assert(index >= 0 && index < number_of_parking_places);
	return data[index];
}

void Garage_parking::erase()//очистка контейнера
{
	delete[] data;
	// Здесь нужно указать data значение nullptr, чтобы на выходе не было висячего указателя
	data = nullptr;
	number_of_parking_places = 0;
}

void Garage_parking::insertBefore(char value, int index)//вставака элемента перед элементом с указаным индексом
{
	assert(index >= 0 && index <= number_of_parking_places);// Проверка корректности передаваемого индекса
	
	char *data_new = new char[number_of_parking_places + 1];// Создаем новый массив на один элемент больше старого массива
	
	for (int before = 0; before < index; ++before)// Копируем все элементы аж до index-а
		data_new[before] = data[before];
	
	data_new[index] = value;// Вставляем наш новый элемент в наш новый массив
	
	for (int after = index; after < number_of_parking_places; ++after)// Копируем все значения после вставляемого элемента
		data_new[after + 1] = data[after];

	delete[] data;// Удаляем старый массив и используем вместо него новый массив
	data = data_new;
	++number_of_parking_places;
}

void Garage_parking::remove(int index)//удаление элемента с указаным индексом
{
	assert(index >= 0 && index < number_of_parking_places);// Проверка на корректность передаваемого индекса

	if (number_of_parking_places == 1)// Если это последний элемент массива, то делаем массив пустым и return
	{
		erase();
		return;
	}
	
	char *data_new = new char[number_of_parking_places - 1];// Cоздаем новый массив на один элемент меньше старого массива

	for (int before = 0; before < index; ++before)// Копируем все элементы аж до index-а
		data_new[before] = data[before];

	for (int after = index + 1; after < number_of_parking_places; ++after)// Копируем все значения после удаляемого элемента
		data_new[after - 1] = data[after];

	delete[] data;// Удаляем старый массив и используем вместо него новый массив
	data = data_new;
	--number_of_parking_places;
}

int Garage_parking::get_number_of_places()//возвращает размер массива
{
	return number_of_parking_places; 
}

void Garage_parking::show_garage(Garage_parking &obj)//выводит на экран гараж
{
	for (int j = 0; j < obj.get_number_of_places(); j++)
		cout << obj[j];
}

int Garage_parking::entry(char value, int index_needed, Garage_parking &obj)//функция въезд в гараж
{
	getchar();
	system("cls");
	obj.show_garage(obj);
	cout << "\n";

	char temp=' ';
	int index=-1;

	for (int i = 0; i <= index_needed; i++)
	{
		getchar();
		system("cls");
		if (obj.data[i] != '-' && obj.data[i] != '|')
		{
			temp = obj.data[i];
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

		cout << "\n";
	}
	getchar();
	system("cls");
	obj.show_garage(obj);
	cout << "\nVehicle " << value << " has arrived\n";
	return 0;
}

int Garage_parking::departure(char value, int index_needed, Garage_parking &obj)//отъезд из гаража
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
		cout << "\n";
	}
	obj.data[number_of_parking_places - 1] = '|';
	getchar();
	system("cls");
	obj.show_garage(obj);
	cout << "\nVehicle " << value << " has departed\n";
	return 0;
}

int Garage_parking::available_places(Garage_parking &obj)//количество доступных парковочных мест
{
	int counter = 0;
	
	for (int i = 0; i < obj.number_of_parking_places; i++)
	{
		if (obj.data[i] != '-' && obj.data[i] != '|')
			counter++;
	}

	return number_of_parking_places - 2 - counter;
}

string Garage_parking::vehicles_in_the_garage(Garage_parking &obj)//транспорт, который находится в гараже
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

void Garage_parking::info_about_vehicle(Garage_parking &obj, char vehicle)//информация о конкретном транспорте в гараже
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
	if (flag == 1)
	{
		cout << "Vehicle " << vehicle << " is in the garage\nIt stands at the "<< number_of_place<<" parking place\n";
	}
	else
		cout << "Vehicle " << vehicle << " is absent\n";
}

Garage_parking::~Garage_parking()
{
	delete[] data;
}


void main()
{
	Garage_parking garage(N);

	for (int i = 0; i < N; i++)
	{
		garage[i] = '-';
	}
	garage[0] = '|';
	garage[N - 1] = '|';

	garage.entry('A', 1, garage);
	cout << "\n";
	garage.entry('B', 3, garage);
	cout << "\n";
	garage.entry('C', 5, garage);
	cout << "\n";

	cout << "Number of available places is: " << garage.available_places(garage) << endl;
	cout << "\n";
	cout << "Vehicles in the garage: " << garage.vehicles_in_the_garage(garage) << endl;
	cout << "\n";

	garage.info_about_vehicle(garage, 'A');
	cout << "\n";
	garage.info_about_vehicle(garage, 'B');
	cout << "\n";
	garage.info_about_vehicle(garage, 'C');
	cout << "\n";
	garage.info_about_vehicle(garage, 'D');
	cout << "\n";

	garage.departure('A', 1, garage);
	cout << endl;
	garage.departure('B', 3, garage);
	
	cout << "Number of available places is: " << garage.available_places(garage) << endl;
	cout << "\n";
	cout << "Vehicles in the garage: " << garage.vehicles_in_the_garage(garage) << endl;
	cout << "\n";
}


