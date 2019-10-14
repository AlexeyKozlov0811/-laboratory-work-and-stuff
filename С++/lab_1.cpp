//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>

using namespace std;

void admin();

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char name[20] = "";
	char password[10] = "";
	char line[250] = "";
	int dot = 0;
	int dot_2 = 0;
	int counter_2(0);

	cout << "Для входу в систему введіть логін та пароль" << endl;
	do {
		FILE *file;
		file = fopen("D:\\database.txt", "r");
		if (file == NULL)//перевірка доступу до файлу
		{
			perror("Помилка доступу до файлу");
		}
		cout << "Логін: ";
		cin >> name;
		bool check = false;
		while (!feof(file) && !check)
		{
			fgets(line, 250, file);
			dot = strlen(name);
			if (strncmp(name, line, strlen(name)) == 0)
			{
				if (line[dot] == '.')
				{
					check = true;
					int counter(0);
					do
					{

						cout << "Пароль: ";
						cin >> password;
						dot_2 = strlen(password);
						char password_copy[10] = "";
						strncpy(password_copy, line + strlen(name) + 1, strlen(password));
						if ((line[dot + dot_2 + 1] == '.') && (strcmp(password, password_copy) == 0))
						{
							int i = 0;
							if (name == "Administrator")
							{
								system("cls");
								cout << "Вітаемо у системі, " << name << "!\nЯкі Ваші дії?\n1. Вивести всі паролі та логіни користувачів\n2. Змінити паролі користувачів" << endl;
								int choise = 0;
								cin >> choise;
								switch (choise)
								{
								case 1:
								{
									admin();
									break;
								}
								case 2:
								{

									break;
								}
								}
								getchar();
								getchar();
								exit(0);

							}
							else
							{
								system("cls");
								cout << "Вітаемо у системі, " << name << "!\nЗмініть, будь ласка, пароль" << endl;

							}
							
							break;
						}
						else {
							cout << "Невірний пароль!" << endl;
							counter++;
						}
					} while (counter < 3);
					if (counter == 3) {
						cout << "Сеанс буде завершено." << endl;
						getchar();
						getchar();
						exit(0);
					}
				}
			}
		}
		if (!check)
			cout << "Невірний логін!" << endl;
		counter_2++;
		fclose(file);
	} while (counter_2 < 3);
	if (counter_2 == 3)
		cout << "Спроба несанкціонованого доступу. Сеанс буде завершено." << endl;
FILE *file;
file = fopen("D:\\database.txt", "r");
if (file == NULL)//перевірка доступу до файлу
{
	perror("Помилка доступу до файлу");
}
char lines[100] = "";
while (!feof(file))
{
	fgets(lines, 250, file);
	cout << lines << endl;
	printf("%s", lines);

	fclose(file);
}


	getchar();
	getchar();
}

//void edit_admin(char* name)
//{
//	cout<<"Вітаемо у системі, "<< name <<"!\nЯкі Ваші дії?\n1. Вивести всі паролі та логіни користувачів\n2. Змінити паролі користувачів"<<endl;
//}



void admin() {
	FILE *file;
	file = fopen("D:\\database.txt", "r");
	if (file == NULL)//перевірка доступу до файлу
	{
		perror("Помилка доступу до файлу");
	}


	char lines[100] = "";
	while (!feof(file))
	{
		fgets(lines, 100, file);
		cout << lines << endl;

	} 
	fclose(file);
	system("pause");
}