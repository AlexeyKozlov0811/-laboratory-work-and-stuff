// dz_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int xMax;
int yMax;
int Width;
int Height;
int VirtualScreenSize;
char *VirtualScreen;
long long Time = 0;



typedef struct Animation
{
	int	Flags;
	int FrameDelayTime;
	int LastFrameTime;
	int FrameKey;
	int FrameKeyMax;
	int FrameWidth;
	int FrameHeight;
	char Offset;
	char *Data;
}Animation;


typedef struct PlayerShip
{
	int	x;
	int	y;
	Animation *HullAnimation;
	Animation *JetAnimation;
	Animation *WeaponAnimation;
}PlayerShip;


char BULLET_ANIMATION_DATA[] =
{
	'-',
	'+',
	'x',
	'+',
	'x',
	'*',
};

char WEAPON_ANIMATION_DATA[] =
{
	'=', ' ',
	'=', '+',
	'=', '*',
	'=', '+'
};

char HULL_PL_ANIMATION_DATA[] =
{
	' ', '|', '\\', ' ',
	'}', '|', '(', ')',
	' ', '|', '/', ' '
};

char HULL_DESTRUCTION_PL_ANIMATION_DATA[] =
{
	' ', '|', '\\', ' ',
	'}', '|', '(', ')',
	' ', '|', '/', ' ',

	' ', '*', '**', ' ',
	'*', '*', '*', '*',
	' ', '*', '*', ' ',

	' ', '.', '..', ' ',
	'.', '.', '.', '.',
	' ', '.', '.', ' ',

	' ', ' ', '  ', ' ',
	' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' '
};

char WEAPON_EN_ANIMATION_DATA[] =
{
	' ', '{',
	'+', '{',
	'*', '{',
	'+', '{'
};

char HULL_EN_ANIMATION_DATA[] =
{
	'H','}', '{'
};

char HULL_EN_DESTRUCT_ANIMATION_DATA[] =
{

	/*' ',' ', '<', 'X', '>', ' ',' ',
	' ','(', 'x', '#', 'x', ')',' ',
	'|','+', '*', 'x', '*', '+','|',
	'*',' ', '.', '+', '.', ' ','*',
	'-',' ', ' ', '*', ' ', ' ','-',
	':',' ', ' ', '.', ' ', ' ',':',
	' ',' ', ' ', ' ', ' ', ' ',' ',
	' ',' ', ' ', ' ', ' ', ' ',' ',*/
	' ',' ', ' ', ' ', ' ', ' ',' ',
	' ',' ', ' ', '*', ' ', ' ',' ',
	' ',' ', '(', '0', ')', ' ',' ',
	' ','(', ' ', '*', ' ', ')',' ',
	'(',' ', ' ', '0', ' ', '-',')',
	' ',' ', '-', '*', '-', ' ',' ',
	' ','-', '=', '0', '=', '-',' ',
	'-','=', '<', '*', '>', '=','-',
	' ','-', '=', '0', '=', '-',' ',
	' ',' ', '-', '*', '-', ' ',' ',
	' ',' ', ' ', '-', ' ', ' ',' ',

};

char JET_EN_ANIMATION_DATA[] =
{
	'-', ' ',
	'=', '-',
	'*', '=',
	'=', '-',
	'=', ' '
};

char JET_ANIMATION_DATA[] =
{
	' ', ' ', '-',
	' ', '-', '=',
	'-', '=', '=',
	'=', '=', '*',
	' ', '-', '=',
};


bool IsValidCoords(int x, int y)
{
	if (x < 0)
		return false;
	if (x > xMax)
		return false;
	if (y < 0)
		return false;
	if (y > yMax)
		return false;
	return true;
}

#define ANIM_ENABLED	0x0001
#define ANIM_ONE_SHOT	0x0002

void AnimationDraw(int x, int y, Animation *Anim)
{


	if (Anim->FrameKeyMax && Anim->Flags & ANIM_ENABLED && (Anim->LastFrameTime + Anim->FrameDelayTime) < Time)
	{
		Anim->LastFrameTime = Time;
		Anim->FrameKey++;

		if (Anim->FrameKey >= Anim->FrameKeyMax)
		{
			Anim->FrameKey = 0;

			if (Anim->Flags & ANIM_ONE_SHOT)
			{
				Anim->Flags &= ~ANIM_ENABLED;
			}
		}
		Anim->Offset = Anim->FrameKey * Anim->FrameWidth * Anim->FrameHeight;

	}

	int xxx, yyy;

	for (int yy = 0; yy < Anim->FrameHeight; yy++)//вывод на вирт экран текущий кадр анимации
	{
		for (int xx = 0; xx < Anim->FrameWidth; xx++)
		{
			xxx = xx + x;
			yyy = yy + y;

			if (IsValidCoords(xxx, yyy))
			{
				char Data = Anim->Data[Anim->Offset + yy * Anim->FrameWidth + xx];
				if (Data != ' ')
				{
					VirtualScreen[yyy * Width + xxx] = Data;
				}
			}
		}
	}
}


typedef struct Bullet
{
	Bullet	*Next;
	int		x;
	int		y;
	int		dx;
	int		LastTime;
	int		DelayTime;
	Animation *BulletAnimation;
}Bullet;


Bullet *BulletCreate(int x, int y, int dx)
{
	Bullet *Bl = new Bullet();
	Bl->Next = NULL;
	Bl->x = x;
	Bl->y = y;
	Bl->dx = dx;
	Bl->LastTime = 0;
	Bl->DelayTime = 2;

	Bl->BulletAnimation = new Animation();
	ZeroMemory(Bl->BulletAnimation, sizeof(Animation));
	Bl->BulletAnimation->Flags = 0;
	Bl->BulletAnimation->FrameKeyMax = 6;
	Bl->BulletAnimation->FrameDelayTime = 5;
	Bl->BulletAnimation->FrameWidth = 1;
	Bl->BulletAnimation->FrameHeight = 1;
	Bl->BulletAnimation->Data = BULLET_ANIMATION_DATA;

	return Bl;
}


Bullet* BulletRemoveFromList(Bullet *Bl, Bullet *&BulletList)
{
	Bullet *BulletPtr = BulletList;

	if (BulletList == Bl)
	{
		if (BulletList->Next)
			BulletList = BulletList->Next;
		else
			BulletList = NULL;
	}
	else
	{
		while (BulletPtr->Next != Bl)
			BulletPtr = BulletPtr->Next;
		BulletPtr->Next = Bl->Next;
	}
	BulletPtr = Bl->Next;
	delete Bl;
	return BulletPtr;
}

void BulletListUpdate(Bullet *&BulletList)
{

	Bullet *BulletPtr = BulletList;

	while (BulletPtr)
	{

		if ((BulletPtr->BulletAnimation->Flags & ANIM_ONE_SHOT) && !(BulletPtr->BulletAnimation->Flags & ANIM_ENABLED))
		{
			BulletPtr = BulletRemoveFromList(BulletPtr, BulletList);
			continue;
		}
		else
		{
			if (BulletPtr->LastTime + BulletPtr->DelayTime < Time)
			{
				if (!IsValidCoords(BulletPtr->x + BulletPtr->dx, BulletPtr->y))
				{
					BulletPtr->dx = 0;
					BulletPtr->BulletAnimation->Flags = ANIM_ONE_SHOT + ANIM_ENABLED;
				}


				BulletPtr->x += BulletPtr->dx;
				BulletPtr->LastTime = Time;
			}
		}

		BulletPtr = BulletPtr->Next;
	};
}

void BulletListDraw(Bullet *Bl)
{

	while (Bl)
	{
		AnimationDraw(Bl->x, Bl->y, Bl->BulletAnimation);
		Bl = Bl->Next;
	}
}


typedef struct EnemyShip
{
	int	x;
	int	y;
	int LastTime;
	int DelayTime;
	EnemyShip *Next;
	Animation *HullAnimation;
	Animation *HullDestructionAnimation;
	Animation *JetAnimation;
	Animation *WeaponAnimation;
}EnemyShip;

int EnemyShipCreate(int x, int y, EnemyShip *&EnemyShipsList)
{
	EnemyShip *EnShip = new EnemyShip();
	ZeroMemory(EnShip, sizeof(EnemyShip));
	EnShip->x = x;
	EnShip->y = y;
	EnShip->DelayTime = 30;

	EnShip->HullAnimation = new Animation();
	ZeroMemory(EnShip->HullAnimation, sizeof(Animation));

	EnShip->HullAnimation->FrameWidth = 3;
	EnShip->HullAnimation->FrameHeight = 1;
	EnShip->HullAnimation->Data = HULL_EN_ANIMATION_DATA;

	EnShip->HullDestructionAnimation = new Animation();
	ZeroMemory(EnShip->HullDestructionAnimation, sizeof(Animation));

	EnShip->HullDestructionAnimation->FrameKeyMax = 11;
	EnShip->HullDestructionAnimation->FrameWidth = 7;
	EnShip->HullDestructionAnimation->FrameHeight = 1;
	EnShip->HullDestructionAnimation->FrameDelayTime = 5;
	EnShip->HullDestructionAnimation->Data = HULL_EN_DESTRUCT_ANIMATION_DATA;

	EnShip->JetAnimation = new Animation();
	ZeroMemory(EnShip->JetAnimation, sizeof(Animation));
	EnShip->JetAnimation->Flags = ANIM_ENABLED;
	EnShip->JetAnimation->FrameKeyMax = 4;
	EnShip->JetAnimation->FrameDelayTime = 4;
	EnShip->JetAnimation->FrameWidth = 2;
	EnShip->JetAnimation->FrameHeight = 1;
	EnShip->JetAnimation->Data = JET_EN_ANIMATION_DATA;

	EnShip->WeaponAnimation = new Animation();
	ZeroMemory(EnShip->WeaponAnimation, sizeof(Animation));
	EnShip->WeaponAnimation->Flags = ANIM_ONE_SHOT;
	EnShip->WeaponAnimation->FrameKeyMax = 4;
	EnShip->WeaponAnimation->FrameDelayTime = 5;
	EnShip->WeaponAnimation->FrameWidth = 2;
	EnShip->WeaponAnimation->FrameHeight = 1;
	EnShip->WeaponAnimation->Data = WEAPON_EN_ANIMATION_DATA;

	EnemyShip *EnShipPtr = EnemyShipsList;
	if (EnShipPtr)
	{
		while (EnShipPtr->Next)
			EnShipPtr = EnShipPtr->Next;
		EnShipPtr->Next = EnShip;
	}
	else
	{
		EnemyShipsList = EnShip;
	}

	return 0;
}

void EnemyShipListDraw(EnemyShip *EnemyShipsList)
{
	EnemyShip *EnemyShipPtr = EnemyShipsList;
	while (EnemyShipPtr)
	{
		if (EnemyShipPtr->HullDestructionAnimation->Flags & ANIM_ENABLED)
		{
			AnimationDraw(EnemyShipPtr->x - 2, EnemyShipPtr->y, EnemyShipPtr->HullDestructionAnimation);

		}
		else
		{
			AnimationDraw(EnemyShipPtr->x, EnemyShipPtr->y, EnemyShipPtr->HullAnimation);
			AnimationDraw(EnemyShipPtr->x - EnemyShipPtr->WeaponAnimation->FrameWidth, EnemyShipPtr->y, EnemyShipPtr->WeaponAnimation);
			AnimationDraw(EnemyShipPtr->x + EnemyShipPtr->HullAnimation->FrameWidth, EnemyShipPtr->y, EnemyShipPtr->JetAnimation);
		}
		//AnimationDraw(PlShip->x + 3, PlShip->y, PlShip->WeaponAnimation);
		//AnimationDraw(PlShip->x + 3, PlShip->y + 2, PlShip->WeaponAnimation);
		EnemyShipPtr = EnemyShipPtr->Next;
	}
}


EnemyShip* RemoveEnemyShipFromList(EnemyShip *EnSHip, EnemyShip *&EnemyShipsList)
{
	EnemyShip *EnemyShipPtr = EnemyShipsList;

	if (EnemyShipsList == EnSHip)
	{
		if (EnemyShipsList->Next)
			EnemyShipsList = EnemyShipsList->Next;
		else
			EnemyShipsList = NULL;
	}
	else
	{
		while (EnemyShipPtr->Next != EnSHip)
			EnemyShipPtr = EnemyShipPtr->Next;
		EnemyShipPtr->Next = EnSHip->Next;
	}
	EnemyShipPtr = EnSHip->Next;
	delete EnSHip;
	return EnemyShipPtr;
}

void EnemyShipFire(EnemyShip *EnShip, Bullet *&BulletList)
{
	Bullet *NewBullet = BulletCreate(EnShip->x - 2, EnShip->y, -1);

	EnShip->WeaponAnimation->Flags += ANIM_ENABLED;

	if (BulletList)
	{
		NewBullet->Next = BulletList;
	}
	BulletList = NewBullet;
}

void EnemyShipListUpdate(EnemyShip *&EnemyShipsList, PlayerShip *PlShip, Bullet *&BulletList)
{
	EnemyShip *EnemyShipPtr = EnemyShipsList;

	while (EnemyShipPtr)
	{
		if (EnemyShipPtr->HullDestructionAnimation->Flags & ANIM_ONE_SHOT && !(EnemyShipPtr->HullDestructionAnimation->Flags & ANIM_ENABLED))
		{
			EnemyShipPtr = RemoveEnemyShipFromList(EnemyShipPtr, EnemyShipsList);
			continue;
		}

		if (EnemyShipPtr->LastTime + EnemyShipPtr->DelayTime < Time)
		{
			if (!IsValidCoords(EnemyShipPtr->x - 1, EnemyShipPtr->y))
			{
				EnemyShipPtr->HullDestructionAnimation->Flags = ANIM_ONE_SHOT + ANIM_ENABLED;
			}
			else
			{
				if (!(EnemyShipPtr->HullDestructionAnimation->Flags & ANIM_ENABLED))
				{
					EnemyShipPtr->x--;
					EnemyShipPtr->LastTime = Time;

					if (!(EnemyShipPtr->WeaponAnimation->Flags & ANIM_ENABLED))
					{
						if (EnemyShipPtr->y >= PlShip->y  && EnemyShipPtr->y <= PlShip->y + 2)
						{
							EnemyShipFire(EnemyShipPtr, BulletList);

						}
						else
						{
							if (EnemyShipPtr->y < PlShip->y)
								EnemyShipPtr->y++;
							if (EnemyShipPtr->y > PlShip->y + 2)
								EnemyShipPtr->y--;
						}
					}
				}
			}
		}
		EnemyShipPtr = EnemyShipPtr->Next;
	}
}


PlayerShip *PlayerShipCreate()
{
	PlayerShip *PlShip = new PlayerShip();

	PlShip->HullAnimation = new Animation();
	ZeroMemory(PlShip->HullAnimation, sizeof(Animation));

	PlShip->HullAnimation->FrameWidth = 4;
	PlShip->HullAnimation->FrameHeight = 3;
	PlShip->HullAnimation->Data = HULL_PL_ANIMATION_DATA;

	PlShip->JetAnimation = new Animation();
	ZeroMemory(PlShip->JetAnimation, sizeof(Animation));
	PlShip->JetAnimation->Flags = ANIM_ENABLED;
	PlShip->JetAnimation->FrameKeyMax = 5;
	PlShip->JetAnimation->FrameDelayTime = 4;
	PlShip->JetAnimation->FrameWidth = 3;
	PlShip->JetAnimation->FrameHeight = 1;
	PlShip->JetAnimation->Data = JET_ANIMATION_DATA;

	PlShip->WeaponAnimation = new Animation();
	ZeroMemory(PlShip->WeaponAnimation, sizeof(Animation));
	PlShip->WeaponAnimation->Flags = ANIM_ENABLED + ANIM_ONE_SHOT;
	PlShip->WeaponAnimation->FrameKeyMax = 4;
	PlShip->WeaponAnimation->FrameDelayTime = 5;
	PlShip->WeaponAnimation->FrameWidth = 2;
	PlShip->WeaponAnimation->FrameHeight = 1;
	PlShip->WeaponAnimation->Data = WEAPON_ANIMATION_DATA;
	return PlShip;
}

void PlayerShipDraw(PlayerShip *PlShip)
{
	AnimationDraw(PlShip->x, PlShip->y, PlShip->HullAnimation);
	AnimationDraw(PlShip->x - PlShip->JetAnimation->FrameWidth, PlShip->y + 1, PlShip->JetAnimation);
	AnimationDraw(PlShip->x + 3, PlShip->y, PlShip->WeaponAnimation);
	AnimationDraw(PlShip->x + 3, PlShip->y + 2, PlShip->WeaponAnimation);
}

enum
{
	MOVE_LT,
	MOVE_RT,
	MOVE_UP,
	MOVE_DN
};

void PlayerShipMove(char MoveType, PlayerShip *PlShip)
{
	switch (MoveType)
	{
	case MOVE_LT:
		if (PlShip->x - 1 > 0)
		{
			PlShip->x--;
		}
		break;
	case MOVE_RT:
		if (PlShip->x + PlShip->HullAnimation->FrameWidth + 1 < xMax)
		{
			PlShip->x++;
		}
		break;
	case MOVE_UP:
		if (PlShip->y - 1 > 0)
		{
			PlShip->y--;
		}
		break;
	case MOVE_DN:
		if (PlShip->y + PlShip->HullAnimation->FrameHeight + 1 < yMax)
		{
			PlShip->y++;
		}
		break;
	}
}


void PlayerShipFire(PlayerShip *PlShip, Bullet *&BulletList)
{
	Bullet *NewBullet = BulletCreate(PlShip->x + 3, PlShip->y, 1);
	NewBullet->Next = BulletCreate(PlShip->x + 3, PlShip->y + 2, 1);

	PlShip->WeaponAnimation->Flags += ANIM_ENABLED;

	if (BulletList)
	{
		NewBullet->Next->Next = BulletList;
	}
	BulletList = NewBullet;
}

void ConsoleResetCursorPosition()
{
	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { 0, 0 };
	SetConsoleCursorPosition(ConsoleOutput, Position);
}


void ConsoleMaximize()
{
	SetConsoleTitle(TEXT("Game"));

	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Size = GetLargestConsoleWindowSize(ConsoleOutput);
	Size.X = 80;
	Size.Y = 50;
	SetConsoleScreenBufferSize(ConsoleOutput, Size);
	SMALL_RECT DisplayArea = { 0, 0, Size.X, Size.Y };
	SetConsoleWindowInfo(ConsoleOutput, TRUE, &DisplayArea);
	SetConsoleScreenBufferSize(ConsoleOutput, Size);
	Sleep(500);
	ShowWindow(FindWindow(NULL, TEXT("Game")), SW_MAXIMIZE);
}



void ConsoleHideCursor()
{
	CONSOLE_CURSOR_INFO Cursor;
	Cursor.dwSize = 1;
	Cursor.bVisible = FALSE;
	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(ConsoleOutput, &Cursor);
}


char *VirtualScreenCreate()
{
	CONSOLE_SCREEN_BUFFER_INFO  BufferInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufferInfo);

	xMax = BufferInfo.srWindow.Right - BufferInfo.srWindow.Left;
	yMax = BufferInfo.srWindow.Bottom - BufferInfo.srWindow.Top - 1;
	Width = xMax + 1;
	Height = yMax + 1;
	VirtualScreenSize = Width * Height;

	char * VS = new char[VirtualScreenSize + 1];
	VS[VirtualScreenSize] = '\0';
	return VS;
}

void VirtualScreenClear()
{
	memset(VirtualScreen, ' ', VirtualScreenSize);
}


void VirtualScreenDraw()
{
	//	cout << VirtualScreen;
	printf("%s", VirtualScreen);
	fflush(stdout);
}


void ManageColissions(PlayerShip *PlShip, EnemyShip *EnemyShipsList, Bullet *&BulletsList)//обработка столкновений
{
	Bullet *BulletPtr = BulletsList;
	Bullet *BulletPtr2;
	EnemyShip *EnShipPtr = EnemyShipsList;

	if (BulletsList)
	{
		do
		{
			if (BulletPtr->x >= PlShip->x)
				continue;
			if (BulletPtr->y >= PlShip->y)
				continue;
			if (BulletPtr->x <= PlShip->x + PlShip->HullAnimation->FrameWidth)
				continue;
			if (BulletPtr->y <= PlShip->y + PlShip->HullAnimation->FrameHeight)
				continue;//после идет анимация разрушения


		} while (BulletPtr = BulletPtr->Next);
	}




	BulletPtr = BulletsList;
	if (BulletsList && EnemyShipsList)
		do
		{

			EnShipPtr = EnemyShipsList;
			do
			{
				if (BulletPtr->x < EnShipPtr->x)
					continue;
				if (BulletPtr->y < EnShipPtr->y)
					continue;
				if (BulletPtr->x >= EnShipPtr->x + EnShipPtr->HullAnimation->FrameWidth)
					continue;
				if (BulletPtr->y >= EnShipPtr->y + EnShipPtr->HullAnimation->FrameHeight)
					continue;

				EnShipPtr->HullDestructionAnimation->Flags = ANIM_ENABLED + ANIM_ONE_SHOT;
				BulletPtr->BulletAnimation->Flags = ANIM_ENABLED + ANIM_ONE_SHOT;
				//	BulletPtr= 	BulletRemoveFromList(BulletPtr, BulletsList);
				//	break;

			} while (EnShipPtr = EnShipPtr->Next);
			BulletPtr2 = BulletPtr->Next;
			if (BulletPtr2)
				do
				{
					if (BulletPtr->x != BulletPtr2->x)
						continue;
					if (BulletPtr->y != BulletPtr2->y)
						continue;

					//	BulletPtr->BulletAnimation->Flags = ANIM_ENABLED + ANIM_ONE_SHOT;
					BulletPtr2->BulletAnimation->Flags = ANIM_ENABLED + ANIM_ONE_SHOT;
				} while (BulletPtr2 = BulletPtr2->Next);


		} while (BulletPtr = BulletPtr->Next);




}

int main()
{
	//	
	ConsoleHideCursor();
	ConsoleMaximize();

	ConsoleResetCursorPosition();

	VirtualScreen = VirtualScreenCreate();


	Animation  Explosion;
	Bullet *BulletList = NULL, *B = BulletCreate(10, 10, 1);
	PlayerShip *PlShip = PlayerShipCreate();
	EnemyShip *EnShipList = NULL;


	ZeroMemory(&Explosion, sizeof(Animation));

	Explosion.Flags = ANIM_ENABLED + ANIM_ONE_SHOT;
	Explosion.FrameKeyMax = 4;
	Explosion.FrameWidth = 4;
	Explosion.FrameHeight = 3;
	Explosion.FrameDelayTime = 20;
	Explosion.Data = HULL_DESTRUCTION_PL_ANIMATION_DATA;

	char key = 0;
	while (true)
	{
		VirtualScreenClear();
		key = 0;
		if (_kbhit())
		{
			key = _getch();
		}

		switch (key)
		{
		case 'q':
		case 'Q':
			return 0;
			break;
		case 'a':
			PlayerShipMove(MOVE_LT, PlShip);
			break;
		case 'd':
			PlayerShipMove(MOVE_RT, PlShip);
			break;
		case 'w':
			PlayerShipMove(MOVE_UP, PlShip);
			break;
		case 's':
			PlayerShipMove(MOVE_DN, PlShip);
			break;
		case 'e':

			break;
		case ' ':
			if (!PlShip->WeaponAnimation->FrameKey)
				PlayerShipFire(PlShip, BulletList);
			Explosion.Flags += ANIM_ENABLED;
			break;
		}

		if (!EnShipList)
			EnemyShipCreate(80, 20, EnShipList);
		//	PlayerShipDraw(10, 10, PLAYER_SHIP);

		//AnimationDraw(7, 11, &Jet);
		//	AnimationDraw(10, 10, &Hull);
		//AnimationDraw(13, 10, &GunLeft);
		//AnimationDraw(13, 12, &GunRight);
		ManageColissions(PlShip, EnShipList, BulletList);
		EnemyShipListDraw(EnShipList);
		EnemyShipListUpdate(EnShipList, PlShip, BulletList);
		PlayerShipDraw(PlShip);
		BulletListUpdate(BulletList);
		//BulletListUpdate(B);
		BulletListDraw(BulletList);
		//BulletListDraw(B);


		AnimationDraw(10, 10, &Explosion);
		ConsoleResetCursorPosition();
		VirtualScreenDraw();
		Sleep(10);
		Time++;
	}

	//cout << Height;
	system("pause");
}