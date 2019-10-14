#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define ZEROX 0
#define ZEROY 0
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
	//int	Flags;
	//int FrameDelayTime;
	//int LastFrameTime;
	//int FrameKey;
	//int FrameKeyMax;
	int FrameWidth;
	int FrameHeight;
	char Offset;
	char *Data;
}Animation;

typedef struct screen
{
	int	x;
	int	y;
	Animation *screen_animation;
}screen;

typedef struct block
{
	block *Next;
	int x;
	int y;
	int dx;
	int LastTime;
	int DelayTime;
	Animation *bl;
}block;

char SREEN_ANIMATION_DATA[] =
{
	'|','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','3',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','4',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','6',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','7',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','8',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','9',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','3',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','4',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','6',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','7',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','8',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','1','9',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2','0',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2','2',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2','3',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2','4',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','2','5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
	'|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|'
};

char BLOCK_ANIMATION_DATA[] =
{
	'=', '=',
	'=', '='
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


	//if (Anim->FrameKeyMax && Anim->Flags & ANIM_ENABLED && (Anim->LastFrameTime + Anim->FrameDelayTime) < Time)
	//{
	//	Anim->LastFrameTime = Time;
	//	Anim->FrameKey++;

	//	if (Anim->FrameKey >= Anim->FrameKeyMax)
	//	{
	//		Anim->FrameKey = 0;

	//		if (Anim->Flags & ANIM_ONE_SHOT)
	//		{
	//			Anim->Flags &= ~ANIM_ENABLED;
	//		}
	//	}
	//	Anim->Offset = Anim->FrameKey * Anim->FrameWidth * Anim->FrameHeight;

	//}

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
				/*if (Data != ' ')
				{*/
					VirtualScreen[yyy * Width + xxx] = Data;
				//}
				/*if (Data == '=')
					VirtualScreen[yyy * Width + xxx] = ' ';*/
			}
		}
	}
}

void ScreenDraw(screen *screen_an)
{
	AnimationDraw(ZEROX, ZEROY, screen_an->screen_animation);
}

screen *ScreenCreate()
{
	screen *new_screen = new screen();
	new_screen->screen_animation = new Animation();
	ZeroMemory(new_screen->screen_animation, sizeof(Animation));
	new_screen->screen_animation->FrameWidth = 42;
	new_screen->screen_animation->FrameHeight = 26;
	new_screen->screen_animation->Data = SREEN_ANIMATION_DATA;

	return new_screen;
}

void BlockType(block *block_an,int no, int rl,int type)
{
	//srand(time(NULL));
	//int type = rand() % 4;
	switch (type)
	{
		case 0:
		{
			AnimationDraw(ZEROX + 20 + rl * 2, -6 + no, block_an->bl);//=
			AnimationDraw(ZEROX + 20 + rl * 2, -4 + no, block_an->bl);//=
			AnimationDraw(ZEROX + 20 + rl * 2, -2 + no, block_an->bl);//=
			AnimationDraw(ZEROX + 20 + rl * 2, 0 + no, block_an->bl); //=
			break;
		}
		case 1:
		{
			AnimationDraw(ZEROX + 20 + rl * 2, -2 + no, block_an->bl);//
			AnimationDraw(ZEROX + 22 + rl * 2, -2 + no, block_an->bl);//==
			AnimationDraw(ZEROX + 20 + rl * 2, 0 + no, block_an->bl); //==
			AnimationDraw(ZEROX + 22 + rl * 2, 0 + no, block_an->bl); //
			break;
		}
		case 2:
		{
			AnimationDraw(ZEROX + 20 + rl * 2, -4 + no, block_an->bl); //=
			AnimationDraw(ZEROX + 20 + rl * 2, -2 + no, block_an->bl); //==
			AnimationDraw(ZEROX + 22 + rl * 2, -2 + no, block_an->bl); //=
			AnimationDraw(ZEROX + 20 + rl * 2, 0 + no, block_an->bl);  //
			break;
		}
		case 3:
		{
			AnimationDraw(ZEROX + 20 + rl * 2, -4 + no, block_an->bl);//
			AnimationDraw(ZEROX + 20 + rl * 2, -2 + no, block_an->bl);//=
			AnimationDraw(ZEROX + 20 + rl * 2, 0 + no, block_an->bl); //=
			AnimationDraw(ZEROX + 22 + rl * 2, 0 + no, block_an->bl); //==
			break;
		}
		case 4:
		{
			AnimationDraw(ZEROX + 22 + rl * 2, -4 + no, block_an->bl);//
			AnimationDraw(ZEROX + 20 + rl * 2, -2 + no, block_an->bl);// =
			AnimationDraw(ZEROX + 22 + rl * 2, -2 + no, block_an->bl);//==
			AnimationDraw(ZEROX + 20 + rl * 2, 0 + no, block_an->bl); //=
			break;
		}
	}
}

block *BlockCreate()
{
	block *new_block = new block();
	new_block->bl = new Animation();
	ZeroMemory(new_block->bl, sizeof(Animation));
	new_block->bl->FrameWidth = 2;
	new_block->bl->FrameHeight = 2;
	new_block->bl->Data = BLOCK_ANIMATION_DATA;
	return new_block;
}

//void ConsoleResetCursorPosition()
//{
//	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD Position = { 0, 0 };
//	SetConsoleCursorPosition(ConsoleOutput, Position);
//}
//
//void ConsoleMaximize()
//{
//	SetConsoleTitle(TEXT("Game"));
//
//	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD Size = GetLargestConsoleWindowSize(ConsoleOutput);
//	Size.X = 80;
//	Size.Y = 50;
//	SetConsoleScreenBufferSize(ConsoleOutput, Size);
//	SMALL_RECT DisplayArea = { 0, 0, Size.X, Size.Y };
//	SetConsoleWindowInfo(ConsoleOutput, TRUE, &DisplayArea);
//	SetConsoleScreenBufferSize(ConsoleOutput, Size);
//	Sleep(500);
//	ShowWindow(FindWindow(NULL, TEXT("Game")), SW_MAXIMIZE);
//}
//
//void ConsoleHideCursor()
//{
//	CONSOLE_CURSOR_INFO Cursor;
//	Cursor.dwSize = 1;
//	Cursor.bVisible = FALSE;
//	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorInfo(ConsoleOutput, &Cursor);
//}

char *VirtualScreenCreate()
{
	CONSOLE_SCREEN_BUFFER_INFO  BufferInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufferInfo);

	xMax = BufferInfo.srWindow.Right - BufferInfo.srWindow.Left;
	yMax = BufferInfo.srWindow.Bottom - BufferInfo.srWindow.Top - 4;
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

int CheckGr(char *VirtualScreen, int no, int shift, int type)
{
	if(type==0)
	{
		if (VirtualScreen[(no + 1) * Width + shift * 2 + 20] == '=')
			return 1;
		else
			return 0;
	}
	else if (type == 1 || type == 3)
	{
		if (VirtualScreen[(no + 1) * Width + shift * 2 + 20] == '=' || VirtualScreen[(no + 1) * Width + shift * 2 + 22] == '=')
			return 1;
		else
			return 0;
	}
	else if	(type == 2 || type == 4)
	{
		if (VirtualScreen[(no + 1) * Width + shift * 2 + 20] == '=' || VirtualScreen[(no - 1) * Width + shift * 2 + 22] == '=')
			return 1;
		else
			return 0;	
	}
}

int CheckSh(char *VirtualScreen, int no, int shift, int type)
{
	if (type == 0)
	{
		if (VirtualScreen[(no + 1) * Width + shift * 2 + 20] == '=')
			return 1;
		else
			return 0;
	}
	else if (type == 1 || type == 3)
	{
		if (VirtualScreen[(no + 1) * Width + shift * 2 + 20] == '=' || VirtualScreen[(no + 1) * Width + shift * 2 + 22] == '=')
			return 1;
		else
			return 0;
	}
	else if (type == 2 || type == 4)
	{
		if (VirtualScreen[(no + 1) * Width + shift * 2 + 20] == '=' || VirtualScreen[(no - 1) * Width + shift * 2 + 22] == '=')
			return 1;
		else
			return 0;
	}
}

int main()
{
	srand(time(NULL));
	ConsoleHideCursor();
	//ConsoleMaximize();
	ConsoleResetCursorPosition();
	char key;
	VirtualScreen = VirtualScreenCreate();
	VirtualScreenClear();
	screen *Scr = ScreenCreate();
	ScreenDraw(Scr);
	block *Blc = BlockCreate();
	//BlockType(Blc,0);
	VirtualScreenDraw();
	bool loose = false;
	int no = 0;
	int shift = 0;
	int type = rand() % 5;
	while (loose != true)
	{
		//cout << VirtualScreen[(no + 1) * Width + 1]<< VirtualScreen[(no + 1) * Width + 2]<< VirtualScreen[(no+1) * Width + shift*2+20];
		if (no==25 || CheckGr(VirtualScreen, no, shift, type))
		{
			no = 0;
			shift = 0;
			type = rand() % 5;
		}
		time_t start_time = time(NULL);
		while (time(NULL) <= start_time)
		{
			//cout << CheckGr(VirtualScreen, no, shift, type);
			VirtualScreenClear();
			key = 0;
			ScreenDraw(Scr);
			//BlockType(Blc,no,0);
			if (_kbhit())
			{
				key = _getch();
			}
			switch (key)
			{
			case 'e':
			{
				return 0;
				break;
			}
			case 'a':
			{
				if (shift - 1 >= -9)
					shift -= 1;
				break;
			}
			case 'd':
			{
				if (type == 0)
				{
					if (shift + 1 <= 9)
						shift += 1;
				}
				else
					if (shift + 1 <= 8)
						shift += 1;
				break;
			}
			default:
			{
				break;
			}
			}
			BlockType(Blc, no, shift, type);
			ConsoleResetCursorPosition();
			//cout << endl << no;
			VirtualScreenDraw();
		}
		no++;		
		//Sleep(500);
	}
	//cout << "\tA - move left\n\tD - move right\n";
	//system("pause");
}