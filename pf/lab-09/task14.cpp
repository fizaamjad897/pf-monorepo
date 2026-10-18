#include<iostream>
using namespace std;
void reversenumbers(int size);
 main()
  {
    int size;
    cout<< "How many elements you want to enter: ";
    cin>>size;
    reversenumbers(size);
  }
void reversenumbers(int size)
 {
    int usernum[size];
    for(int idx = 0 ; idx < size ; idx++)
     {
        cout<< "Enter number: ";
        cin>>usernum[idx];
     }
    for(int idx = size - 1 ; idx >= 0 ; idx--)
     {
        cout<<usernum[idx] <<endl;
     }
 }
