#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
int foodtimer = 0;
int tankX = 10;
int tankY = 20;
int enemyX = 65;
int enemyY = 15;
int enemy2X = 80;
int enemy2Y = 12;
int chenemyX = 5;
int chenemyY = 5;
int timer = 0;
int timer2 = 0;
int score = 0;
int powertank = 100;
int bulletX[1000000];
int bulletY[1000000];
int enemybulletX[1000000];
int enemybulletY[1000000];
bool isbulletactive[1000000];
bool isenemybulletactive[1000000];
int bulletcount = 0;
int foodcounter = 0 ;
int enemybulletcount = 0;
int enemy2bulletcount = 0;
int enemy2bulletX[1000000];
int enemy2bulletY[1000000];
bool isenemy2bulletactive[1000000];
string enemydirection = "Up";
string enemy2direction = "Left";
char tank[4][7] = {{'-', '_', '_', '_', '_', '-', '*'},
                   {'|', ' ', ' ', ' ', ' ', '}', '>'},
                   {'|', '_', '_', '_', '_', '}', '>'},
                   {'0', '0', '0', '0', '0', '0', ' '}};
char enemy1[4][7] = {{' ', ' ', ' ', '_', '_', '_', ' '},
                     {'<', '=', '|', '=', '=', '=', '|'},
                     {'<', '=', '|', '_', '_', '_', '|'},
                     {' ', '8', '8', '8', '8', '8', '8'}};
char enemy2[4][7] = {{' ', '_', '_', '_', '_', '_', '_'},
                     {'E', ' ', ' ', '=', '=', '=', '|'},
                     {'E', '0', '0', '0', '0', '0', '|'},
                     {' ', 'X', 'X', 'X', 'X', 'X', 'X'}};
char box = 219;
char chasingenemy[1][2] = {{box,box}};
char maze[26][120];
void printtank();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void lvl1Game();
void gameGuidance();
void instructions();
void keys();
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
void printenemy2();
void moveenemy2();
void generateenemy2bullet();
void moveenemy2bullet();
void printenemy2bullet(int x, int y);
void eraseenemy2bullet(int x, int y);
void makeenemy2bulletinactive(int i);
void addscore();
void printscore();
void tankpower();
void printtankpower();
void powerend();
void readmaze();
void printchasingenemy();
void erasechasingenemy();
void movechasingenemy();
string option;

main()
{
    system("cls");
   lvl1Game();
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
void gameGuidance()
{
    string key;
    while(key!="3")
    {
    cout<<"1-Keys"<<endl;
    cout<<"2-Instructions"<<endl;
    cout<<"3-Exit"<<endl;
    cout<<"Enter your Option:";
    cin>>key;

    if(key =="1")
    {
        system("cls");
        keys();
        cout<<"Press any key to continue";
        getch();
        system("cls");
        gameGuidance();
    }
    else if(key =="2")
    {
        system("cls");
        instructions();
        cout<<"Press any key to continue";
        getch();
        system("cls");
        gameGuidance();
    }
    if(key =="3")
    {
        system("cls");
        lvl1Game();
    }
    }

}
void keys()
{
    cout<<"keys"<<endl;
}
void instructions()
{
    cout<<"instr"<<endl;
}
void lvl1Game()
{
    cout<<"1-Game"<<endl;
    cout<<"2-Game Instructions"<<endl;
    cout<<"3-Exit"<<endl;
    cout<<"Enter your Option:"<<endl;
    cin>>option;

    if(option=="1")
    {
    bool game=true;
    system("cls");
    readmaze();
    printmaze();
    printenemy();
    printtank();
    printenemy2();
    while (game)
    {
    printchasingenemy();
    movechasingenemy();
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
        moveenemy();
        if (timer == 88)
        {
            generateenemybullet();
            moveenemybullet();
            timer = 0;
        }
        printtankpower();
        moveenemy2();
        if (timer2 == 20)
        {
            generateenemy2bullet();
            moveenemy2bullet();
            timer2 = 0;
        }
        timer++;
        timer2++;
        if (powertank == 0)
        {
            powerend();
            break;
        }
        Sleep(10);
        if (foodtimer == 200)
        {
            int x = rand() % 60 + 1;
            int y = rand() % 13 + 1;
            char nextloc = getCharAtxy(x, y);
            if (nextloc == ' ')
            {
                gotoxy(x, y);
                cout << "o";
            }
            foodtimer = 0;
        }
        foodtimer++;
    }
    }
    else if(option=="2")
    {
        system("cls");
        gameGuidance();
    }
    else if(option=="3")
    {
        system("cls");
        
    }

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
    for (int i = 0; i < 26; i++)
    {
        for (int c = 0; c < 120; c++)
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
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ' && next6 == ' ' && next7 == ' ')
    {
        erasetank();
        tankY--;
        printtank();
    }
    if (next1 == 'o' || next2 == 'o' || next3 == 'o' || next4 == 'o' || next5 == 'o' || next6 == 'o' || next7 == 'o')
    {
        powertank = powertank + 5;
        erasetank();
        tankY++;
        printtank();
        foodcounter++;
        if (foodcounter % 4 == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (tank[i][c] == ' ')
                    {
                        tank[i][c] = 'o';
                        erasetank();
                        tankY++;
                        printtank();
                        break;
                    }
                }
            }
        }
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
    if (next1 == 'o' || next2 == 'o' || next3 == 'o' || next4 == 'o' || next5 == 'o' || next6 == 'o' || next7 == 'o')
    {
        powertank = powertank + 5;
        erasetank();
        tankY++;
        printtank();
        foodcounter++;
        if (foodcounter % 4 == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (tank[i][c] == ' ')
                    {
                        tank[i][c] = 'o';
                        erasetank();
                        tankY++;
                        printtank();
                        break;
                    }
                }
            }
        }
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
    else if (next1 == 'o' || next2 == 'o' || next3 == 'o' || next4 == 'o')
    {
        powertank = powertank + 5;
        erasetank();
        tankX--;
        printtank();
        foodcounter++;
        if (foodcounter % 4 == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (tank[i][c] == ' ')
                    {
                        tank[i][c] = 'o';
                        erasetank();
                        tankX--;
                        printtank();
                        break;
                    }
                }
            }
        }
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
    else if (next1 == 'o' || next2 == 'o' || next3 == 'o' || next4 == 'o')
    {
        powertank = powertank + 5;
        erasetank();
        tankX++;
        printtank();
        foodcounter++;
        if (foodcounter % 4 == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int c = 0; c < 8; c++)
                {
                    if (tank[i][c] == ' ')
                    {
                        tank[i][c] = 'o';
                        erasetank();
                        tankX++;
                        printtank();
                        break;
                    }
                }
            }
        }
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
        else
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
        else
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
    if (next == ' ')
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
            if (next == ' ')
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
            if (next == ' ')
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
void printenemy2()
{
        for (int i = 0; i < 4; i++)
    {
        gotoxy(enemy2X, enemy2Y + i);
        for (int c = 0; c < 7; c++)
        {
            cout << enemy2[i][c];
        }
        cout << endl;
    }
}
void eraseenemy2()
 {
     for (int i = 0; i < 4; i++)
    {
        gotoxy(enemy2X, enemy2Y + i);
        for (int c = 0; c < 7; c++)
        {
            cout << " ";
        }
    }
 }
 void moveenemy2()
 {
    if (enemy2direction == "Left")
    {
        char next1 = getCharAtxy(enemy2X - 1, enemy2Y);
        char next2 = getCharAtxy(enemy2X - 1, enemy2Y + 1);
        char next3 = getCharAtxy(enemy2X - 1, enemy2Y + 2);
        char next4 = getCharAtxy(enemy2X- 1, enemy2Y + 3);
        if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
        {
            eraseenemy2();
            enemy2X--;
            printenemy2();
        }
        else if (next1 == '#' || next2 == '#' || next3 == '#' || next4 == '#')
        {
            enemy2direction = "Right";
        }
        else
         {
            enemy2direction = "Right";
         }
    }
    if (enemy2direction == "Right")
    {
        char next1 = getCharAtxy(enemy2X + 7, enemy2Y);
        char next2 = getCharAtxy(enemy2X + 7, enemy2Y + 1);
        char next3 = getCharAtxy(enemy2X + 7, enemy2Y + 2);
        char next4 = getCharAtxy(enemy2X + 7, enemy2Y + 3);
        if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ')
        {
            eraseenemy2();
            enemy2X++;
            printenemy2();
        }
        else if(next1 == '#' || next2 == '#' || next3 == '#' || next4 == '#' )
        {
            enemy2direction = "Left";
        }
        else
        {
            enemy2direction = "Left";
        }
    }

 }
 void generateenemy2bullet()
 {
    enemy2bulletX[enemy2bulletcount] = enemy2X - 1;
    enemy2bulletY[enemy2bulletcount] = enemy2Y;
    isenemy2bulletactive[enemy2bulletcount] = true;
    gotoxy(enemy2X - 1, enemy2Y);
    cout << "x";
    enemy2bulletcount++;

 }
void moveenemy2bullet()
{
    for (int x = 0; x < enemy2bulletcount; x++)
    {
        if (isenemy2bulletactive[x] == true)
        {
            char next = getCharAtxy(enemy2bulletX[x] - 1, enemy2bulletY[x]);
            if (next == ' ')
            {
                eraseenemy2bullet(enemy2bulletX[x], enemy2bulletY[x]);
                enemy2bulletX[x] = enemy2bulletX[x] - 1;
                printenemy2bullet(enemy2bulletX[x], enemy2bulletY[x]);
            }
            else if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
            {
                eraseenemy2bullet(enemy2bulletX[x], enemy2bulletY[x]);
                makeenemy2bulletinactive(x);
                tankpower();
            }
            else
            {
                eraseenemy2bullet(enemy2bulletX[x], enemy2bulletY[x]);
                makeenemy2bulletinactive(x);
            }
        }
    }
}
void printenemy2bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "x";
}
void eraseenemy2bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeenemy2bulletinactive(int i)
{
    isenemy2bulletactive[i] = false;
}
void printchasingenemy()
 {
    for(int i = 0 ; i < 1 ; i++)
     {
        gotoxy(chenemyX,chenemyY + i);
        for(int j = 0 ; j < 2 ; j++)
         {
            cout<<chasingenemy[i][j];
         }
     }
 }
void erasechasingenemy()
 {
    for(int i = 0 ; i < 1 ; i++)
     {
        gotoxy(chenemyX,chenemyY + i);
        for(int j = 0 ; j < 2 ; j++)
         {
            cout<<" ";
         }
     }
 }
void movechasingenemy()
 {
    SetConsoleTextAttribute(color,12);
    if(tankX >chenemyX)
     {
        char next = getCharAtxy(chenemyX + 2, chenemyY);
        if(next == ' ')
         {
            erasechasingenemy();
            chenemyX++;
            printchasingenemy();
         }
         else if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
          {
            powertank = powertank - 2;
          }
     }
    if(tankX < chenemyX)
     {
        char next = getCharAtxy(chenemyX - 1, chenemyY);
        if(next == ' ')
         {
            erasechasingenemy();
            chenemyX--;
            printchasingenemy();
         }
         else if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
          {
            powertank = powertank - 2;
          }

     }
     if(tankY < chenemyY)
     {
        char next = getCharAtxy(chenemyX, chenemyY - 1);
        if(next == ' ')
         {
            erasechasingenemy();
            chenemyY--;
            printchasingenemy();
         }
         else if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
          {
            powertank = powertank - 2;
          }

     }
    if(tankY > chenemyY)
     {
        char next = getCharAtxy(chenemyX, chenemyY + 1);
        if(next == ' ')
         {
            erasechasingenemy();
            chenemyY++;
            printchasingenemy();
         }
         else if (next == tank[1][1] || next == tank[2][1] || next == tank[3][1] || next == tank[4][1])
          {
            powertank = powertank - 2;
          }

     }
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
    file.open("maze.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        for (int j = 0; j < 120; j++)
        {
            maze[i][j] = line[j];
        }
        i++;
    }
    file.close();
    i = 0;
}
