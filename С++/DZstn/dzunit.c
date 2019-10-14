#include<stdio.h>
#include"dz_head_help.h"
struct Unit_u
{
	char mark;//позначення персонажа
	unsigned int at;//показник атаки персонажа 
	int hp;//показник здоров'я персонажа
	unsigned int move;//показник рухомості персонажа
};
typedef struct Unit_u unit;
void Read_unit(unit *un_ptr,unsigned int unit_num)//считування юніта з файлу
{
	FILE *dt;
	dt=fopen("units.txt","r");
	if(dt==NULL)//якщо нема доступу до файлу
		perror("no access to the file\n");
	else
	{//считування характеристик
		char ch;
		for(int i=1;i<unit_num;i++)//перехід на строку з потрібним юнітом
			for(ch=getc(dt);ch!='\n'&&ch!=EOF;)//до кінця строки або файлу
				ch=getc(dt);
		ch=getc(dt);
		un_ptr->mark=ch;//запис позначення юніта
		ch=getc(dt);
		un_ptr->at=Char_to_int(ch=getc(dt));//запис перетвореної в ціле число атаки юніта
		ch=getc(dt);
		un_ptr->hp=Char_to_int(ch=getc(dt));//запис перетвореної в ціле число здоров'я юніта
		ch=getc(dt);
		un_ptr->move=Char_to_int(ch=getc(dt));//запис перетвореної в ціле число рухомості юніта
		fclose(dt);
	}	
}
void Units(unit *un_ptr,unsigned int num_un,unsigned int player)//створення армії гравця 
{
	for(int i=player-1;i<num_un*2;i+=2)//цикл створення армії
	{
		printf("Enter the unit number to add him to the army: ");
		int unit_num;
		scanf("%d",&unit_num);//номер юніта в списку
		Read_unit((un_ptr+i),unit_num);//додання його до армії
	}
}
void Army(unit *un_ptr,unsigned int num_un,unsigned int player)//виведення армії гравця
{	
	printf("\tPlayer %d army \n",player);
	printf("\t _______________________________________________________________\n");
	printf("\t|\t#\t|   Mark    |  Attack   |  Health   | Mobility  |");
	int n=1;
	for(int i=player-1;i<num_un*2;i+=2)//цикл виведення армії
		{
			printf("\n\t|\t%d\t|%c          |%d          |%d          |%d          |",n,(un_ptr+i)->mark,(un_ptr+i)->at,(un_ptr+i)->hp,(un_ptr+i)->move);//характеристики
			n++;
		}
	printf("\n\t|_______________|___________|___________|___________|___________|\n");
}
int win_ch(unit *un_ptr,unsigned int num_un)//перевірка закінчення гри
{
	int def_p1=0;//поразка гравця 1
	int def_p2=0;//поразка гравця 2
	for(int i=0;i<num_un*2;i++)//перевірка наявності живих юнітів
	{
		if(i&1)//юніти другого гравця
		{
			if((un_ptr+i)->hp!=0)//якщо нема живих
				def_p2=1;
		}
		else//юніти першого гравця
		{			
			if((un_ptr+i)->hp!=0)//якщо нема живих
				def_p1=1;
		}
	}
	if(!def_p1&&!def_p2)//якщо в обох гравців нема живих юнітів
	{
		printf("Game over. \nResult: Draw\n");
		return 1;
	}
	else if(!def_p1)//перемога гравця 2
	{
		printf("Game over. \nResult: The winner is player #2\n");
		return 1;
	}
	else if(!def_p2)//перемога гравця 1
	{
		printf("Game over. \nResult: The winner is player #1\n");
		return 1;
	}
	else//гра не закінчена
		return 0;
}