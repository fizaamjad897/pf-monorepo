#include<iostream>
using namespace std;
void transformation(int size, int numoftrans);
main()
 {
    int size, numoftrans;
    cout<< "Enter size of an array: ";
    cin>>size;
    cout<< "Enter num of even-odd transformation: ";
    cin>>numoftrans;
    transformation(size, numoftrans);
 }
 void transformation(int size, int numoftrans)
  {
    int arr[size];
    for(int idx = 0 ; idx < size ; idx++)
     {
        cout<< "Enter number: ";
        cin>>arr[idx];
     }
    for(int idx = 0 ; idx < size ; idx++)
     {
        for(int n = 0 ; n < numoftrans ; n++)
         {
            if(arr[idx] % 2 == 0)
             {
                arr[idx] = arr[idx] - 2;
             }
            if(arr[idx] % 2 == 1)
             {
                arr[idx]= arr[idx] + 2;
             }
         }
        cout<<arr[idx] <<endl;
     }
  }
