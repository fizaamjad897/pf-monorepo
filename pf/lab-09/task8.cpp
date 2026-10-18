#include<iostream>
using namespace std;
void location(string userstring);
main()
 {
    string userstring;
    cout<< "Enter word: ";
    cin>>userstring;
    location(userstring);
 }
void location(string userstring)
 {
    for(int idx = 0 ; userstring[idx] != '\0' ; idx++)
     {
        cout<<userstring[idx] << " is at " <<idx <<" th position " <<endl;
     }
 }
