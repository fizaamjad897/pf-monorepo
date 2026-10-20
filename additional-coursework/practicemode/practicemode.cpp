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
    for(int c = 0 ; usernum - c >= 1 ; c++)
     {
        sub = usernum - c;
        fact = sub * fact;
     }
     return fact;
  }

