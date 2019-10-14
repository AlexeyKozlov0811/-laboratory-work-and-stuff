
#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>

using namespace std;

void main()
{

	srand(time(0));
	int success_changing = 0, success_staying = 0, num_iterations = 100;

	for (int i = 0; i < num_iterations; i++)
	{
		int chosen = rand() % 3 + 1;
		int prize = rand() % 3 + 1;
		int shown = rand() % 3 + 1;
		if (shown == chosen || shown == prize)
		{
			while (shown == chosen || shown == prize)
			{
				shown = rand() % 3 + 1;
			}
		}
		int questioned = rand() % 3 + 1;
		if (questioned == chosen || questioned == shown)
		{
			while (questioned == chosen || questioned == shown)
			{
				questioned = rand() % 3 + 1;
			}
		}
		if (chosen == prize)
			success_staying++;	
		if (questioned == prize)
			success_changing++;
	}
		cout << "Results:" << endl;
		cout << "number of iterations: " << num_iterations << endl;
		cout << "Stay and be right: " << success_staying << endl;	
		cout << "Change and be right: " << success_changing << endl;	
	getchar();
	getchar();

}

