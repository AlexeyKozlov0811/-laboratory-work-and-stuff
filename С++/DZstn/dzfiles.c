#include<stdio.h>
struct Unit_u
{
	char mark[2];//позначення персонажа
	unsigned int at;//показник атаки персонажа 
	int hp;//показник здоров'я персонажа
	unsigned int move;//показник рухомості персонажа
};
typedef struct Unit_u unit;
void Unit_Create()//функція створення юнітів
{
	FILE *dt;
	dt=fopen("units.txt","a");//файл запису юнітів
	if(dt==NULL)//якщо нема доступу
		perror("no access to the file\n");
	else
	{//введення і запис характеристик
		unit new_unit;
		printf("Enter the character designation (1 character): ");
		scanf("%s",new_unit.mark);
		fprintf(dt,"\n");
		fputc(*new_unit.mark,dt);
		fprintf(dt,"|");
		printf("Enter the attack rate of the character: ");
		scanf("%d",&new_unit.at);
		fprintf(dt,"%d|",new_unit.at%10);
		printf("Enter the health rate of the character: ");
		scanf("%d",&new_unit.hp);
		fprintf(dt,"%d|",new_unit.hp%10);
		printf("Enter the mobility rate of the character: ");
		scanf("%d",&new_unit.move);
		fprintf(dt,"%d|",new_unit.move%10);
		fclose(dt);//закриття файлу
	}
}
void Print_all_units()//виведення віх юнітів з файлу
{
	FILE *dt;
	dt=fopen("units.txt","r");
	if(dt==NULL)//якщо нема доступу
		perror("no access to the file\n");
	else
	{//виведення юнітів
		printf("\tAll units\n");
		printf("\t _______________________________________________________________\n");
		printf("\t|\t#\t|   Mark    |  Attack   |  Health   | Mobility  |");
		int i=1;		
		for(char ch='\n';ch!=EOF;ch=getc(dt))//посимвольне считування
		{
			if(ch=='|')//наступна характеристика
			{
				for(int j=0;j<10;j++)
					printf(" ");
			}
			printf("%c",ch);
			if(ch=='\n')//новий юніт
			{
				printf("\t|\t%d\t|",i);
				i++;
			}			
		}
		printf("\n\t|_______________|___________|___________|___________|___________|\n");
		fclose(dt);//закриття файлу
	}
}