#include<iostream>
using namespace std;
float factorial(float usernum);
main()
 {
    float usernum, result;
    cout<< "Enter a number: ";
    cin>>usernum;
    result = factorial(usernum);
    cout<<result;
 }
 float factorial(float usernum)
  {
    float sub, fact = 1;
    while(usernum >= 1)
     {
        sub = usernum --;
        fact = sub * fact;
     }
     return fact;
  }

