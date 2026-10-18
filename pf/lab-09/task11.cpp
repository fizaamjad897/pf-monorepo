#include<iostream>
using namespace std;
bool ispresent(string userstring, char letter);
main()
 {
    string userstring;
    char letter;
    bool result;
    cout<< "Enter string: ";
    getline(cin, userstring);
    cout<< "Enter letter: ";
    cin>>letter;
    result = ispresent(userstring, letter);
    if(result == true)
     {
        cout<< "true";
     }
    else
     {
        cout<< "false";
     }
 }
 bool ispresent(string userstring, char letter)
  {
    int length, idx;
    length = userstring.length();
    idx = length - 1;
    if(userstring[idx] == letter)
     {
        return true;
     }
    else 
     {
        return false;
     }
  }

