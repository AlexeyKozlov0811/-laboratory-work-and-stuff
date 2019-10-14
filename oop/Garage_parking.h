#pragma once
#include <string.h>
#include <string>
class Garage_parking
{
private:
	int number_of_parking_places;
	char *data;

public:
	Garage_parking();
	Garage_parking(int places);

	char & operator[](int index);
	int get_number_of_places();
	void erase();
	void insertBefore(char value, int index);
	void remove(int index);

	void show_garage(Garage_parking &obj);

	int entry(char value, int index_needed, Garage_parking &obj);
	int departure(char value, int index_needed, Garage_parking &obj);
	int available_places(Garage_parking &obj);
	std::string vehicles_in_the_garage(Garage_parking &obj);
	void info_about_vehicle(Garage_parking &obj, char vehicle);

	~Garage_parking();
};

