#include<iostream>
using namespace std;
string isevenodd(string userstring);
main()
 {
    string userstring, output;
    cout<< "Enter string: ";
    cin>>userstring;
    output = isevenodd(userstring);
    cout<<output;
 }
 string isevenodd(string userstring)
  {
    int stringlength;
    string result;
    stringlength = userstring.length();
    if(stringlength % 2 == 0)
     {
        result = "even";
     }
    else
     {
        result = "odd";
     }
    return result;
  }
