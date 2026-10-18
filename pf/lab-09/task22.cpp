#include<iostream>
using namespace std;
void printsomething(string userstring);
main()
 {
    string userstring;
    cout<< "Enter string: ";
    getline(cin, userstring);
    printsomething(userstring);
 }
void printsomething(string userstring)
 {
    cout<< "something ";
    for(int idx = 0 ; userstring[idx] != '\0' ; idx++)
     {
        cout<<userstring[idx];
     }
 }
