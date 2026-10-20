#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
char pipe = 201;
char tank1[5] = {'.', '_', pipe, '_', '.'};
char tank2[5] = {'|', ' ', ' ', ' ', '|'};
char tank3[5] = {'|', '_', '_', '_', '|'};

char enemy1[6] = {' ', ' ', ' ', '-', '-', '-'};
char enemy2[6] = {'<', '=', '=', '(', ' ', ')'};
char enemy3[6] = {' ', ' ', ' ', '\\', '@', '/'};
char enemy4[6] = {' ', ' ', ' ', '*', '*', '*'};
int score = 0;
int tankX = 5;
int tankY = 5;
int enemyX = 30;
int enemyY = 10;
int bx, by;
int bulletX[100];
int bulletY[100];
bool isbulletactive[100];
int bulletcount = 0;
string enemydirection = "Up";
int timer = 0;
void printmaze();
void printtank();
void printenemy();
void movetankleft();
void movetankright();
void movetankup();
void movetankdown();
void erasetank();
void moveenemy();
void eraseenemy();
void generatebullet();
void movebullet();
void printbullet(int x, int y);
void erasebullet(int x, int y);
void makebulletinactive(int index);
void printenemybullet(int bx, int by);
void bulletcollisionwithenemy();
void addscore();
void printscore();

main()
{
    system("cls");
    printmaze();
    printtank();
    printenemy();
    while (true)
    {
        printscore();
        printenemybullet(bx, by);
        moveenemy();
        if (GetAsyncKeyState(VK_LEFT))
        {
            movetankleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movetankright();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movetankup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movetankdown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generatebullet();
        }
        if (timer == 3)
        {
            moveenemy();

            timer = 0;
        }
        movebullet();
        bulletcollisionwithenemy();
        timer++;
        Sleep(90);
    }
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printtank()
{
    gotoxy(tankX, tankY);
    for (int idx = 0; idx < 5; idx++)
    {
        cout << tank1[idx];
    }
    gotoxy(tankX, tankY + 1);
    for (int idx = 0; idx < 5; idx++)
    {
        cout << tank2[idx];
    }
    gotoxy(tankX, tankY + 2);
    for (int idx = 0; idx < 5; idx++)
    {
        cout << tank3[idx];
    }
}
void printenemy()
{
    gotoxy(enemyX, enemyY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << enemy1[idx];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << enemy2[idx];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << enemy3[idx];
    }
    gotoxy(enemyX, enemyY + 3);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << enemy4[idx];
    }
    bx = enemyX;
    by = enemyY;
}
void printmaze()
{
    cout << "#########################################################################" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#                                                                       #" << endl;
    cout << "#########################################################################" << endl;
}
void movetankleft()
{
    char next = getCharAtxy(tankX - 1, tankY);
    if (next == ' ')
    {
        erasetank();
        tankX = tankX - 1;
        printtank();
    }
}
void movetankright()
{
    char next = getCharAtxy(tankX + 7, tankY);
    if (next == ' ')
    {
        erasetank();
        tankX = tankX + 1;
        printtank();
    }
}
void movetankdown()
{
    char next = getCharAtxy(tankX, tankY + 3);
    if (next == ' ')
    {
        erasetank();
        tankY = tankY + 1;
        printtank();
    }
}
void movetankup()
{
    char next = getCharAtxy(tankX, tankY - 1);
    if (next == ' ')
    {
        erasetank();
        tankY = tankY - 1;
        printtank();
    }
}
void erasetank()
{
    gotoxy(tankX, tankY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 1);
    for (int idx = 0; idx < 5; idx++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 2);
    for (int idx = 0; idx < 5; idx++)
    {
        cout << " ";
    }
}
void moveenemy()
{
    if (enemydirection == "Up")
    {
        char next = getCharAtxy(enemyX, enemyY - 1);
        if (next == ' ')
        {
            eraseenemy();
            enemyY--;
            printenemy();
        }
        if (next == '#')
        {
            enemydirection = "Down";
        }
    }
    if (enemydirection == "Down")
    {
        char next = getCharAtxy(enemyX, enemyY + 4);
        if (next == ' ')
        {
            eraseenemy();
            enemyY++;
            printenemy();
        }
        if (next == '#')
        {
            enemydirection = "Up";
        }
    }
}
void eraseenemy()
{
    gotoxy(enemyX, enemyY);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 3);
    for (int idx = 0; idx < 6; idx++)
    {
        cout << " ";
    }
}
void generatebullet()
{
    bulletX[bulletcount] = tankX + 7;
    bulletY[bulletcount] = tankY;
    isbulletactive[bulletcount] = true;
    gotoxy(tankX + 7, tankY);
    cout << ".";
    bulletcount++;
}
void movebullet()
{
    for (int x = 0; x < bulletcount; x++)
    {
        if (isbulletactive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                erasebullet(bulletX[x], bulletY[x]);
                makebulletinactive(x);
            }
            else
            {
                erasebullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printbullet(bulletX[x], bulletY[x]);
            }
        }
    }
}
void printbullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void erasebullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makebulletinactive(int i)
{
    isbulletactive[i] = false;
}
void printenemybullet(int bx , int by)
{
    char next = getCharAtxy(bx - 1, by);
    if (next == ' ')
    {
        erasebullet(bx, by);
        bx--;
        printbullet(bx, by);
    }
    else
    {
        erasebullet(bx, by);
    }
}
void bulletcollisionwithenemy()
{
   for(int x = 0 ; x < bulletcount ; x++)
    {
        for(int idx = 0 ; idx < 6 ; idx++)
         {
            if(bulletX[x] == enemy1[idx] || bulletX[x] == enemy2[idx] || bulletX[x] == enemy3[idx] || bulletX[x] == bx)
             {
                addscore();
             }
         }
    }
}
void addscore()
{
    score++;
}
void printscore()
{
    gotoxy(45, 8);
    cout << "score:" << score;
}
    gotoxy(tankX, tankY);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 1);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 2);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 3);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }
    gotoxy(tankX, tankY + 4);
    for (int i = 0; i < 7; i++)
    {
        cout << " ";
    }

    char next = getCharAtxy(enemybulletX[enemybulletcount] - 1, enemybulletY[enemybulletcount]);
    if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
    {
        tankpower();
    }
