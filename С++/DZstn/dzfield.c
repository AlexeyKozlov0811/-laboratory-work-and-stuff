#include<stdio.h>
#include<malloc.h>
struct Unit_u
{
	char mark;//позначення персонажа
	unsigned int at;//показник атаки персонажа 
	int hp;//показник здоров'я персонажа
	unsigned int move;//показник рухомості персонажа
};
typedef struct Unit_u unit;
struct Field_u
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
void Cr_field(field **head,field **last,unsigned int cells)//функція створення поля
{
	field *current;
	for(int i=0;i<cells*cells;i++)//цикл формування поля заданого розміру
	{
		if((current=(field *)malloc(sizeof(field)))==NULL)//перевірка наявності пам'яті 
		{
			perror("no free memory\n");
		}
		else
		{
			current->next=NULL;//ініціалізація по замовченню
			current->prev=NULL;
			current->up=NULL;
			current->down=NULL;
			current->un=NULL;
			current->x=1+i%cells;
			current->y=1+i/cells;
			if(!(*head))//вказівник на перший елемент
				*head=current;
			else
				(*last)->next=current;//вказівник на наступний елемент 
			if(*last)
				current->prev=*last;//вказівник на попередній елемент
			*last=current;
			if(current->y!=1)//якщо обраобляеться не перший рядок
			{
				field *curr;//вказівник на верхній елемент
				curr=current->prev;
				for(;curr->x!=current->x;)
					curr=curr->prev;
				curr->down=current;//ініціалізація відповідних полів
				current->up=curr;								
			}			
		}
	}
}
void Show_field(field **head,unsigned int cells)//функція виводу поля
{
	printf("\tField\n");
	field *current;
	current=*head;
	printf("\t x|");
	for(int i=1;i<=cells;i++)
		printf(" %d |",i);
	printf("\n\ty  ");
	for(int i=1;i<=cells*4-1;i++)
		printf("_");
	for(int i=0;i<cells;i++)//виведення елементів
	{
		if(current->x==1)//виведення першого елемента в рядку
			{
				printf("\n");
				printf("\t%d |",current->y);
				if(current->un!=NULL)
					printf("%c  |",(current->un)->mark);
				else
					printf("   |");
				current=current->next;				
			}
		for(int i=0;i<cells-1;i++)//виведення наступних
		{
			if(current->un!=NULL)
				printf("%c  |",(current->un)->mark);
			else
				printf("   |");
			current=current->next;
		}		
			printf("\n\t  ");//останняй рядок
			printf("|___|");
			for(int i=0;i<cells-1;i++)
				printf("___|");
	}
	printf("\n");
}