#include<stdio.h>
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
int Att(unit *un_ptr,unit *un_ptr1,unit *un_ptr2,unsigned int player,field *current)//функція атаки
{
	if((un_ptr1-un_ptr2)%2!=0)//якщо атакуючий і атакований не належать до одному гравцю
	{
		printf("Enemy takes %d damage\n",un_ptr1->at);
		un_ptr2->hp-=un_ptr1->at;//нанесення пошкоджень
		if(un_ptr2->hp<=0)//якщо атакований загинув
		{
			un_ptr2->hp=0;
			current->un=NULL;
			printf("Enemy unit died\n");		
		}
		return 1;//атака відбулася 
	}
	else
		return 0;//атака не відбулася 
}
void Move_un(unit *un_ptr,field **head,unsigned int cells,unsigned int player)//функція руху юніта
{
	printf("Choose unit for turn: ");
	unsigned int unit_tu=0;
	scanf("%d",&unit_tu);
	unit *curr_un=(un_ptr+(player-1)+2*(unit_tu-1));//выбір юніта для ходу
	if(unit_tu>cells||curr_un->hp==0)//якщо цього юніта нама на полі
	{
		for(int i=player-1;curr_un->hp==0&&i<cells*2;i+=2)//обрання першого живого юніта
			curr_un=(un_ptr+i);
		printf("This is absent. \nFirst live unit is chosen for turn\n");
	}
	field *current=*head;
	for(int i=0;current->un!=curr_un&&i<cells*cells;i++)//поточне положення юніта
		current=current->next;
	unsigned int dx,dy;//кординати точки призначення
	printf("Enter coordinates x,y to move and / or attack: \n");
	for(int val=1;val==1;)//поки координати не буде введено правильно
	{
		printf("\tx = ");//введення координат
		scanf("%d",&dx);
		printf("\ty = ");
		scanf("%d",&dy);
		val=0;
		if((dx<1||dx>cells)||(dy<1||dy>cells))
		{
			val=1;
			printf("Enter the coordinates correctly\n");
		}
	}
	unsigned int key_at=0;//наявність атаки при русі
	for(int mp=curr_un->move;mp>0&&key_at==0;mp--)//цикл руху і атаки
	{
		if(current->x<dx)//якщо юніт зліва від точки призначення
		{
			if(current->next->un==NULL)//якщо наступна клітинка пуста
			{
			current->next->un=current->un;//рухатись
			current->un=NULL;
			current=current->next;
			}			
			else
				key_at=Att(un_ptr,curr_un,current->next->un,player,current->next);//атакувати
		}
		else if(current->x>dx)//якщо юніт справа від точки призначення
		{
			if(current->prev->un==NULL)//якщо наступна клітинка пуста
			{
			current->prev->un=current->un;//рухатись
			current->un=NULL;
			current=current->prev;
			}			
			else
				key_at=Att(un_ptr,curr_un,current->prev->un,player,current->prev);//атакувати
		}
		if(current->y>dy&&key_at==0)//якщо юніт знизу від точки призначення
		{
			if(current->up->un==NULL)//якщо наступна клітинка пуста
			{
			current->up->un=current->un;//рухатись
			current->un=NULL;
			current=current->up;
			}			
			else
				key_at=Att(un_ptr,curr_un,current->up->un,player,current->up);//атакувати
		}
		else if(current->y<dy)//якщо юніт зверху від точки призначення
		{
			if(current->down->un==NULL)//якщо наступна клітинка пуста
			{
			current->down->un=current->un;//рухатись
			current->un=NULL;
			current=current->down;
			}			
			else
				key_at=Att(un_ptr,curr_un,current->down->un,player,current->down);//атакувати
		}
	}
}
void Place_un(unit *un_ptr,field **head,unsigned int num_un,unsigned int cells)//розміщення юнітів на полі
{
	field *current=*head;
	if (num_un>cells)//якщо кількість юнітів більша за кількість клітинок в одному столбці
		num_un=cells;//юніти займають весь стовбчик
	for(int i=0;i<num_un*2;i+=2)//цикл розміщення по одному ряду
	{
		current->un=(un_ptr+i);//розмістити в першому стовпці
		for(int j=0;j<cells-1;j++)
			current=current->next;
		current->un=(un_ptr+i+1);//розмістити в останьому стовпці
		current=current->next;
	}		
}