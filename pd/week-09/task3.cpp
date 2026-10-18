#include<iostream>
using namespace std;
string getlength(int lengthofstring);
main()
 {
    int lengthofstring;
    string username, result;
    cout<< "Enter string: ";
    cin>>username;
    lengthofstring = username.length();
    result = getlength(lengthofstring);
    cout<<result;

 }
 string getlength(int lengthofstring)
   {
    string output;
    if(lengthofstring % 2 == 0)
     {
        output = "true";
     }
    if(lengthofstring % 2 == 1)
     {
        output = "false";
     }
    return output;
   }


