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
    cout<< "Enter the letter: ";
    cin>>letter;
    result = ispresent(userstring, letter);
    if(result == true)
     {
        cout<< "It is present ";
     }
    else
     {
        cout<< "Not present ";
     }
 }
 bool ispresent(string userstring, char letter)
  {
    for(int idx = 0 ; userstring[idx] != '\0' ; idx++)
     {
        if(userstring[idx] == letter)
         {
            return true;
         }
     }
     return false;
  }
