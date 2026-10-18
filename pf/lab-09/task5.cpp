#include<iostream>
using namespace std;
main()
 {
    int size;
    cout<< "Enter size of the array: ";
    cin>>size;
    int number[size];
    for(int idx = 0 ; idx < size; idx++)
     {
        cin>>number[idx];
     }
    for(int idx = 0 ; idx < size ; idx ++)
     {
        cout<<number[idx] <<endl;
     }
 }