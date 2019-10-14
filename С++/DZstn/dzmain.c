#include<stdio.h>
#include"dz_head_field.h"
#include"dz_head_unit.h"
#include"dz_head_files.h"
#include"dz_head_units_and_field.h"
#define UNITS 5%10//кількість юнітів
#define CELLS 9%10//довжина і ширина ігрового поля
struct Unit_u//структура юнітів
{
	char mark;//позначення персонажа
	unsigned int at;//показник атаки персонажа 
	int hp;//показник здоров'я персонажа
	unsigned int move;//показник рухомості персонажа
};
typedef struct Unit_u unit;
struct Field_u//структура поля
{
	unsigned int x;//координата х
	unsigned int y;//координата у
	struct Field_u *next;//наступна клітинка
	struct Field_u *prev;//попередня клітинка
	struct Field_u *up;//верхня клітинка
	struct Field_u *down;//нижня клітинка
	unit *un;//юніт в клітинці
};
typedef struct Field_u field;
unit units[UNITS*2];//массив юнітів
unit *un_ptr=units;//вказівник на массив юнітів
int main()
{
	#ifdef _WIN32//Препроцесорна логічна умова для Windows системи
		system("cls");
	#endif
	unsigned int key_exit=0;//ключ виходу із програми
	unsigned int key_do=0;//ключ дії
	printf("\nEnter a key to do smth\n1st to create new unit\n2nd to view all units\n3rd to start game\nOr other to exit\n");
	for(;key_exit==0;)//цикл роботи програми
	{		
		printf("\tkey = ");
		scanf("%d",&key_do);//введення ключа дії
		switch (key_do)
		{
			case 1://створення нового юніта
			{
				Unit_Create();
				break;
			}
			case 2://виведення всіх юнітів
			{
				Print_all_units();
				break;
			}
			case 3://гра
			{
				field *head=NULL;//Початок списка (ігрового поля)
				field *last=NULL;//Кінець списка (ігрового поля)
				unsigned int key_end_game=0;//ключ виходу з гри
				unsigned int turn_num=0;//номер ходу
				Cr_field(&head,&last,CELLS);//створення поля
				Print_all_units();//виведення всіх юнітів
				printf("Chose units player №1\n");
				Units(un_ptr,UNITS,1);//армія 1го гравця
				printf("Chose units player #2\n");
				Units(un_ptr,UNITS,2);//армія 2го гравця
				Place_un(un_ptr,&head,UNITS,CELLS);//розміщення юнітів на полі
				for(;key_end_game==0&&turn_num<50;turn_num++)//цикл гри
				{
					Show_field(&head,CELLS);//виведення ігрового поля
					printf("Player #%d turn\n",(turn_num&1)+1);
					Army(un_ptr,UNITS,(turn_num&1)+1);//виведення армії гравця
					Move_un(un_ptr,&head,CELLS,(turn_num&1)+1);//хід гравця
					key_end_game=win_ch(un_ptr,UNITS);//перевірка закінчення гри
				}
				printf("Number of moves = %d\n",turn_num);//кількість ходів
				#ifdef _WIN32
					free(head);//звільнення пам'яті
					free(last);//звільнення пам'яті
				#endif
				break;
			}
			default://вихід з програми
			{
				key_exit=1;
			}	
		}
	}
	getchar();
	getchar();
	return 0;
}