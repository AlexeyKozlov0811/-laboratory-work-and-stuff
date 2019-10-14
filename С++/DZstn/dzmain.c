#include<stdio.h>
#include"dz_head_field.h"
#include"dz_head_unit.h"
#include"dz_head_files.h"
#include"dz_head_units_and_field.h"
#define UNITS 5%10//������� ����
#define CELLS 9%10//������� � ������ �������� ����
struct Unit_u//��������� ����
{
	char mark;//���������� ���������
	unsigned int at;//�������� ����� ��������� 
	int hp;//�������� ������'� ���������
	unsigned int move;//�������� �������� ���������
};
typedef struct Unit_u unit;
struct Field_u//��������� ����
{
	unsigned int x;//���������� �
	unsigned int y;//���������� �
	struct Field_u *next;//�������� �������
	struct Field_u *prev;//��������� �������
	struct Field_u *up;//������ �������
	struct Field_u *down;//����� �������
	unit *un;//��� � �������
};
typedef struct Field_u field;
unit units[UNITS*2];//������ ����
unit *un_ptr=units;//�������� �� ������ ����
int main()
{
	#ifdef _WIN32//������������� ������ ����� ��� Windows �������
		system("cls");
	#endif
	unsigned int key_exit=0;//���� ������ �� ��������
	unsigned int key_do=0;//���� 䳿
	printf("\nEnter a key to do smth\n1st to create new unit\n2nd to view all units\n3rd to start game\nOr other to exit\n");
	for(;key_exit==0;)//���� ������ ��������
	{		
		printf("\tkey = ");
		scanf("%d",&key_do);//�������� ����� 䳿
		switch (key_do)
		{
			case 1://��������� ������ ����
			{
				Unit_Create();
				break;
			}
			case 2://��������� ��� ����
			{
				Print_all_units();
				break;
			}
			case 3://���
			{
				field *head=NULL;//������� ������ (�������� ����)
				field *last=NULL;//ʳ���� ������ (�������� ����)
				unsigned int key_end_game=0;//���� ������ � ���
				unsigned int turn_num=0;//����� ����
				Cr_field(&head,&last,CELLS);//��������� ����
				Print_all_units();//��������� ��� ����
				printf("Chose units player �1\n");
				Units(un_ptr,UNITS,1);//���� 1�� ������
				printf("Chose units player #2\n");
				Units(un_ptr,UNITS,2);//���� 2�� ������
				Place_un(un_ptr,&head,UNITS,CELLS);//��������� ���� �� ���
				for(;key_end_game==0&&turn_num<50;turn_num++)//���� ���
				{
					Show_field(&head,CELLS);//��������� �������� ����
					printf("Player #%d turn\n",(turn_num&1)+1);
					Army(un_ptr,UNITS,(turn_num&1)+1);//��������� ��쳿 ������
					Move_un(un_ptr,&head,CELLS,(turn_num&1)+1);//��� ������
					key_end_game=win_ch(un_ptr,UNITS);//�������� ��������� ���
				}
				printf("Number of moves = %d\n",turn_num);//������� ����
				#ifdef _WIN32
					free(head);//��������� ���'��
					free(last);//��������� ���'��
				#endif
				break;
			}
			default://����� � ��������
			{
				key_exit=1;
			}	
		}
	}
	getchar();
	getchar();
	return 0;
}