#include <iostream>
#include <time.h>

using namespace std;

class timer
{
	private:
		time_t creation_time;
		time_t destruction_time;
	public:
		timer()
		{
			creation_time = time(NULL);
			cout<<"Creation time: "<<ctime(&creation_time);
		}
		~timer()
		{
			destruction_time = time(NULL);
			cout<<"Destruction time: "<<ctime(&destruction_time);
			cout<<"Executing time: "<<difftime(destruction_time, creation_time)<<" sec";
		}
};

int main()
{
	timer start;
	cout<<"Press any key";
	getchar();
	return 0;
}