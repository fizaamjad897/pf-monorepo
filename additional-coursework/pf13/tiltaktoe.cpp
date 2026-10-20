#include<iostream>
using namespace std;
int red=0, black=0, blue=0, yellow=0, green=0;
int cardata[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
main()
 {
for(int r = 0 ; r < 5 ; r++)
 {
    for(int c = 0 ; c < 5 ; c++)
     {
        if(c == 0)
         {
            red = red + cardata[r][c];
         }
        if(c == 1)
         {
            blue = blue + cardata[r][c];
         }
        if(c == 2)
         {
            black = black + cardata[r][c];
         }
        if(c == 3)
         {
            yellow = yellow + cardata[r][c];
         }
                 if(c == 4)
         {
            green = green + cardata[r][c];
         }
     }
     cout<<endl;
 }
 cout<<red <<black <<yellow <<blue <<green;
 }