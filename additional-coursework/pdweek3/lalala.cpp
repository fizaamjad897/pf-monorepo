#include<stdio.h>
#include<conio.h>
void main()
{
    int size = 4;
    char alphabets[4] = {'A', 'B', 'C', 'D'};
    int idx = 0 ;
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j <= i ; j++)
        {
          if(idx < size)
          {
            printf("%c", alphabets[idx]);
            idx++; 
          }
          if(idx == size)
          {
            break;
          }
        }
        printf("\n");
    }
    getch();
}