#include<iostream>
using namespace std;
main()
 {
    int number[5];
    for(int idx = 0 ; idx < 5 ; idx++)
     {
        cin>>number[idx];
     }
    cout<< "The first number is:" <<number[0] <<endl;
    cout << "The second number is: " <<number[4] <<endl;
 }