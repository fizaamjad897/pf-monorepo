#include<iostream>
using namespace std;
main()
{
    int numbers[5] = {1,4,3,4,5};
    //int numbers = 5;
    *numbers++;
        //p = &numbers;
    cout <<*numbers;
}