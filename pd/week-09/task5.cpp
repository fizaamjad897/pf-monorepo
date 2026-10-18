#include<iostream>
using namespace std;
bool issame(int size);
main()
 {
    bool result;
    int size;
    cout<< "Enter size of array: ";
    cin>>size;
    result = issame(size);
    if(result == true)
     {
        cout<< "true";
     }
    else
     {
        cout<< "false";
     }
      
 }
bool issame(int size)
 {
    string arr[size];
    bool isthere = false;
    for(int idx = 0 ; idx < size; idx++)
     {
        cin>>arr[idx];
     }
     for(int idx = 0 ; idx < size; idx++)
        {
          for(int n = 0 ; n < size ; n++)
           {
            if(arr[idx] == arr[n])
             {
               isthere = true;
             }
            if(arr[idx] != arr[n])
             {
               isthere = false;
             }
           }
            return isthere;
        }
   return 0;
 }
