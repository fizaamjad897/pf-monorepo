#include<iostream>
using namespace std;
int colorsquare(int size);
main()
 {
    int size, output;
    cout<< "Enter no of inputs: ";
    cin>>size;
    output = colorsquare(size);
    cout<<output;
 }
 int colorsquare(int size)
  {
    int totaltime;
    int switchtime=-1;
    int squaretime = size * 2;
    string arr[size];
    for(int idx = 0 ; idx < size ; idx++)
     {
        cin>>arr[idx];
     }
     for(int idx = 0; idx < size ; idx++)
      {
        if(arr[idx] == arr[idx+1])
         {
           switchtime = 0;
         }
        else
         {
            switchtime = switchtime + 1;
         }
      }
      totaltime = squaretime + switchtime;
      return totaltime;
      
  }
