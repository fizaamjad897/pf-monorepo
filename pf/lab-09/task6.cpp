#include<iostream>
using namespace std;
main()
 {
    int sum = 0, size;
    float average;
    cout<< "Enter no. of elements: ";
    cin>>size;
    int arr[size];
    for(int idx = 0 ; idx < size ; idx++)
     {
        cout<< "The number ";
        cin>>arr[idx];
     }
    for(int idx = 0 ; idx < size ; idx++)
     {
        sum = sum + arr[idx];
     }
     average = sum / size;
     cout<< "The sum is equal to: " <<sum <<endl;
     cout<< "The average is equal to: " <<average <<endl;
 }