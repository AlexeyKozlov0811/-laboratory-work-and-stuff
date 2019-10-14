#include<iostream>
#include<time.h>
#define N_OF_THROWS 100000
using namespace std;

class dice
{
	public:
	int sides;
	int number_of_dices;
	int result=0;
	int score=0;
	virtual int throw_dice(){return 0;};
};

class Vasil: public dice
{
	public:
	Vasil()
	{
		sides=4;
		number_of_dices=9;
	}
	int throw_dice()
	{
		result=0;
		for(int i=0;i<number_of_dices;i++)
		{
			result+=rand()%sides+1;
		}
		return result;
	}
};

class Micola: public dice
{
	public:
	Micola()
	{
		sides=6;
		number_of_dices=6;
	}
	int throw_dice()
	{
		result=0;
		for(int i=0;i<number_of_dices;i++)
		{
			result+=rand()%sides+1;
		}
		return result;
	}
};

class Player1: public dice
{
	public:
	Player1(int sides_inp, int dices_inp)
	{
		sides=sides_inp;
		number_of_dices=dices_inp;
	}
	int throw_dice()
	{
		result=0;
		for(int i=0;i<number_of_dices;i++)
		{
			result+=rand()%sides+1;
		}
		return result;
	}
};

int main()
{
	srand(time(NULL));
	Vasil V;
	Micola M;
	dice *player;
	int draw=0;
	
	for(int i=0;i<N_OF_THROWS;i++)
	{
		player=&V;
		player->throw_dice();
		player=&M;
		player->throw_dice();
		
		if(V.result>M.result)
			V.score++;
		else if(V.result<M.result)
			M.score++;
		else
			draw++;
	}
	cout<<"Vasil wins "<<V.score<<endl;
	cout<<"Micola wins "<<M.score<<endl;
	cout<<"Draws "<<draw<<endl;
	
	float prob=0;
	prob=(float)V.score/(float)N_OF_THROWS*100;
	printf("Statistic chance to win for Vasil %.7f%%",prob);
	
	prob=1/pow(V.sides,V.number_of_dices);
	printf("Theoretical chance to win for Vasil %.7f%%",prob);
	
}