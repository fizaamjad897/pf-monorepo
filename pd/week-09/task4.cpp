#include<iostream>
using namespace std;
bool sevenexists(int size);
main()
 {
    bool result;
    int size;
    cout<< "Enter size of the array: ";
    cin>>size;
    result = sevenexists(size);
    if(result == true)
     {
        cout<< "Boom!";
     }
    else
     {
        cout<< "There is no seven in this array";
     }
 }
 bool sevenexists(int size)
  { 
   bool isthere = false;
   int arr[size];
   for(int i = 0; i < size ; i++)
    {
     cin>>arr[i];
     if(arr[i]>=0)
      {
        if(arr[i] > 9)
         {
            int quotient= arr[i], rem;
            while(quotient > 0)
             {
                rem = quotient % 10;
                quotient = quotient / 10;
                if(rem == 7)
                 {
                    isthere = true;
                 }
             }
         }
        if(arr[i] < 9)
            {
            if(arr[i] == 7)
                {
                    isthere = true;
                }
            }
         }
    if(arr[i] < 0)
      {
        arr[i] = -(arr[i]);
        if(arr[i] > 9)
         {
            int quotient= arr[i], rem;
            while(quotient > 0)
             {
                rem = quotient % 10;
                quotient = quotient / 10;
                if(rem == 7)
                 {
                    isthere = true;
                 }
             }
            
         }
        if(arr[i] < 9)
            {
            if(arr[i] == 7)
                {
                    isthere = true;
                }
            }
        }
     }
    return isthere;
  }












     

