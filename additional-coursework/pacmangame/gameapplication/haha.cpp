#include <iostream>
#include <windows.h>
using namespace std;
int tankx = 5;
int tanky = 5;
int enamyx = 30;
int enamyy = 10;
int bulletx[100];
int bullety[100];
bool isbulletactive[100];
int bulletcount = 0;
void generatebullet();
void erasebullet(int x, int y);
void printbullet(int x, int y);
void makebulletinactive(int i);
void movebullet();


main()
{
    if (GetAsyncKeyState(VK_SPACE))
    {
        generatebullet();
    }
    movebullet();
}

void printbullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void makebulletinactive(int i)
{
    isbulletactive[i] = false;
}
void erasebullet(int x, int y)
{
    gotoxy(x, y);
    cout<<" ";
}

