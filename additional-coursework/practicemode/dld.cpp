#include<iostream>
#include <stdlib.h>
using namespace std;
void decimaltobinary(int decimalnumber);
void binarytodecimal(int decimalnumber);
main()
{
    int decimalnumber, binarynumber;
    cout<< "Enter a decimal number ";
    cin>>decimalnumber;
    decimaltobinary(decimalnumber);
}
void decimaltobinary(int decimalnumber)
{
    int digit, i =0;
    int* arr = (int*) malloc(i * sizeof(int));
     while(decimalnumber != 0)
    {
        digit = decimalnumber%2;
        arr[i]=digit;
        decimalnumber = decimalnumber/2;
        i++;
    }
    for(int idx = i - 1 ; idx > -1 ; idx--)
    {
        cout<<arr[idx];
    }
    free(arr);
}
