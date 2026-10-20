#include <iostream>
#include <windows.h>
#include <conio.h>
#include<fstream>
#include <string>
using namespace std;
int foodtimer=0;
int tankX = 10;
int tankY = 20;
int enemyX = 65;
int enemyY = 15;
int timer = 0;
int score = 0;
int powertank = 100;
int bulletX[1000000];
int bulletY[1000000];
int enemybulletX[1000000];
int enemybulletY[1000000];
bool isbulletactive[1000000];
bool isenemybulletactive[1000000];
int bulletcount = 0;
int enemybulletcount = 0;
string enemydirection = "Up";
char tank[4][7] = {{' ', '_', '_', '_', '_', ' ', ' '},
                   {'|', ' ', ' ', ' ', ' ', '}', '>'},
                   {'|', '_', '_', '_', '_', '}', '>'},
                   {'0', '0', '0', '0', '0', '0', ' '}};
char enemy1[4][7] = {{' ', ' ', ' ', '_', '_', '_', ' '},
                     {'<', '=', '|', '=', '=', '=', '|'},
                     {'<', '=', '|', '_', '_', '_', '|'},
                     {' ', '8', '8', '8', '8', '8', '8'}};
char maze[26][120];                     
void printtank();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printenemy();
void printmaze();
void movetankup();
void movetankdown();
void movetankleft();
void movetankright();
void erasetank();
void eraseenemy();
void moveenemy();
void generatebullet();
void movebullet();
void printbullet(int x, int y);
void erasebullet(int x, int y);
void makebulletinactive(int i);
void generateenemybullet();
void printenemybullet(int x, int y);
void eraseenemybullet(int x, int y);
void makeenemybulletinactive(int i);
void moveenemybullet();
void addscore();
void printscore();
void tankpower();
void printtankpower();
void powerend();
void readmaze();
void lvl2();
main()
{
    system("cls");
    readmaze();
    printmaze();
    printenemy();
    printtank();
    while (true)
    {
        if (GetAsyncKeyState(VK_UP))
        {

            movetankup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {

            movetankdown();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {

            movetankleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {

            movetankright();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generatebullet();
        }
        printscore();
        movebullet();
        if (timer == 3)
        {
            moveenemy();
            generateenemybullet();
            moveenemybullet();
            timer = 0;
        }
        printtankpower();
        if (powertank == 0)
        {
            powerend();
            break;
        }
        timer++;
        Sleep(20);
        if(foodtimer==60)
        {
            int x=rand()%60 +1;
            int y=rand()% 13+1;
            char nextloc=getCharAtxy(x,y);
            if(nextloc==' ')
            {
                gotoxy(x,y);
                cout<<"o";
             
            }
            foodtimer=0;

        }
        foodtimer++;
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
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

void printtank()
{

    for (int i = 0; i < 4; i++)
    {
        gotoxy(tankX, tankY + i);
        for (int c = 0; c < 7; c++)
        {
            cout << tank[i][c];
        }
        cout << endl;
    }
}
void printenemy()
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(enemyX, enemyY + i);
        for (int c = 0; c < 7; c++)
        {
            cout << enemy1[i][c];
        }
        cout << endl;
    }
}
void printmaze()
{
    for (int i = 0; i < 36; i++)
    {
        for (int c = 0; c < 97 ; c++)
        {
            cout << maze[i][c];
        }
        cout << endl;
    }
}
void erasetank()
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(tankX, tankY + i);
        for (int c = 0; c < 7; c++)
        {
            cout << " ";
        }
    }
}
void movetankup()
{
    char next1 = getCharAtxy(tankX, tankY - 1);
    char next2 = getCharAtxy(tankX + 1, tankY - 1);
    char next3 = getCharAtxy(tankX + 2, tankY - 1);
    char next4 = getCharAtxy(tankX + 3, tankY - 1);
    char next5 = getCharAtxy(tankX + 4, tankY - 1);
    char next6 = getCharAtxy(tankX + 5, tankY - 1);
    char next7 = getCharAtxy(tankX + 6, tankY - 1);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ')
    {
        erasetank();
        tankY = tankY - 1;
        printtank();
    }
}
void movetankdown()
{
    char next1 = getCharAtxy(tankX, tankY + 4);
    char next2 = getCharAtxy(tankX + 1, tankY + 4);
    char next3 = getCharAtxy(tankX + 2, tankY + 4);
    char next4 = getCharAtxy(tankX + 3, tankY + 4);
    char next5 = getCharAtxy(tankX + 4, tankY + 4);
    char next6 = getCharAtxy(tankX + 5, tankY + 4);
    char next7 = getCharAtxy(tankX + 6, tankY + 4);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ')
    {
        erasetank();
        tankY++;
        printtank();
    }
}
void movetankleft()
{
    char next1 = getCharAtxy(tankX - 1, tankY);
    char next2 = getCharAtxy(tankX - 1, tankY + 1);
    char next3 = getCharAtxy(tankX - 1, tankY + 2);
    char next4 = getCharAtxy(tankX - 1, tankY + 3);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
    {
        erasetank();
        tankX = tankX - 1;
        printtank();
    }
}
void movetankright()
{
    char next1 = getCharAtxy(tankX + 7, tankY);
    char next2 = getCharAtxy(tankX + 7, tankY + 1);
    char next3 = getCharAtxy(tankX + 7, tankY + 2);
    char next4 = getCharAtxy(tankX + 7, tankY + 3);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
    {
        erasetank();
        tankX++;
        printtank();
    }
}
void eraseenemy()
{
    for (int i = 0; i < 4; i++)
    {
        gotoxy(enemyX, enemyY + i);
        for (int c = 0; c < 7; c++)
        {
            cout << " ";
        }
    }
}
void moveenemy()
{
    if (enemydirection == "Up")
    {
        char next1 = getCharAtxy(enemyX, enemyY - 1);
        char next2 = getCharAtxy(enemyX + 1, enemyY - 1);
        char next3 = getCharAtxy(enemyX + 2, enemyY - 1);
        char next4 = getCharAtxy(enemyX + 3, enemyY - 1);
        char next5 = getCharAtxy(enemyX + 4, enemyY - 1);
        char next6 = getCharAtxy(enemyX + 5, enemyY - 1);
        char next7 = getCharAtxy(enemyX + 6, enemyY - 1);
        if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ')
        {
            eraseenemy();
            enemyY--;
            printenemy();
        }
        if (next1 == '#' || next2 == '#' || next3 == '#' || next4 == '#' || next5 == '#' || next6 == '#' || next7 == '#')
        {
            enemydirection = "Down";
        }
    }
    if (enemydirection == "Down")
    {
        char next1 = getCharAtxy(enemyX, enemyY + 4);
        char next2 = getCharAtxy(enemyX + 1, enemyY + 4);
        char next3 = getCharAtxy(enemyX + 2, enemyY + 4);
        char next4 = getCharAtxy(enemyX + 3, enemyY + 4);
        char next5 = getCharAtxy(enemyX + 4, enemyY + 4);
        char next6 = getCharAtxy(enemyX + 5, enemyY + 4);
        char next7 = getCharAtxy(enemyX + 6, enemyY + 4);
        if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ')
        {
            eraseenemy();
            enemyY++;
            printenemy();
        }
        if (next1 == '#' || next2 == '#' || next3 == '#' || next4 == '#' || next5 == '#' || next6 == '#' || next7 == '#')
        {
            enemydirection = "Up";
        }
    }
}
void generatebullet()
{
    bulletX[bulletcount] = tankX + 7;
    bulletY[bulletcount] = tankY + 1;
    isbulletactive[bulletcount] = true;
    char next = getCharAtxy(tankX + 7, tankY + 1);
    if(next == ' ')
    {
    gotoxy(tankX + 7, tankY + 1);
    cout << ".";
    bulletcount++;
    }
}
void movebullet()
{
    for (int x = 0; x < bulletcount; x++)
    {
        if (isbulletactive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if(next == ' ')
            {
                erasebullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printbullet(bulletX[x], bulletY[x]);
            }
            else if (next == '-' || next == enemy1[1][1] || next == enemy1[2][1] || next == enemy1[3][1] || next == enemy1[4][1])
            {
                addscore();
                erasebullet(bulletX[x], bulletY[x]);
                makebulletinactive(x);
            }
            else
            {
                erasebullet(bulletX[x], bulletY[x]);
                 makebulletinactive(x);
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
void generateenemybullet()
{
    enemybulletX[enemybulletcount] = enemyX - 1;
    enemybulletY[enemybulletcount] = enemyY + 1;
    isenemybulletactive[enemybulletcount] = true;
    gotoxy(enemyX - 1, enemyY + 1);
    cout << "-";
    enemybulletcount++;
}
void moveenemybullet()
{
    for (int x = 0; x < enemybulletcount; x++)
    {
        if (isenemybulletactive[x] == true)
        {
            char next = getCharAtxy(enemybulletX[x] - 1, enemybulletY[x]);
            if(next == ' ')
            {
                eraseenemybullet(enemybulletX[x], enemybulletY[x]);
                enemybulletX[x] = enemybulletX[x] - 1;
                printenemybullet(enemybulletX[x], enemybulletY[x]);
            }
            else if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
            {
                eraseenemybullet(enemybulletX[x], enemybulletY[x]);
                makeenemybulletinactive(x);
                tankpower();
            }
            else
             {
                eraseenemybullet(enemybulletX[x], enemybulletY[x]);
                makeenemybulletinactive(x);
             }
        }
    }
}
void printenemybullet(int x, int y)
{
    gotoxy(x, y);
    cout << "-";
}
void eraseenemybullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeenemybulletinactive(int i)
{
    isenemybulletactive[i] = false;
}
void addscore()
{
    score++;
}
void printscore()
{
    gotoxy(99, 19);
    cout << "Score: " << score;
}
void tankpower()
{
    powertank = powertank - 1;
}
void printtankpower()
{
    gotoxy(99, 21);
    cout << "Power: " << powertank << " ";
}
void powerend()
{
    system("cls");
    cout << "Your power ended";
}
void readmaze()
 {
    fstream file;
    string line;
    int i = 0;
    file.open("maze.txt",ios::in);
    while(!file.eof())
    {
        getline(file,line);
        for(int j = 0 ; j < 120 ; j++)
         {
            maze[i][j]= line[j];
         }
         i++;
    }
    file.close();
    i = 0;
 }
