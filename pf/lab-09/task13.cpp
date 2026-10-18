#include<iostream>
using namespace std;
int vowelwords(string userstring);
main()
 {
    string userstring;
    int result;
    cout<< "Enter data: ";
    getline(cin, userstring);
    result = vowelwords(userstring);
    cout<<result;
 }
 int vowelwords(string userstring)
  {
    int count = 0;
    for(int idx = 0 ; userstring[idx] != '\0' ; idx++)
     {
        if(userstring[idx] == 'a' || userstring[idx] == 'e' || userstring[idx] == 'i' || userstring[idx] == 'o' || userstring[idx] == 'u'||userstring[idx] == 'A' ||userstring[idx] == 'O' ||userstring[idx] == 'I' || userstring[idx] == 'U' || userstring[idx] == 'U')
         {
            count++;
         }
     }
    return count;
  }
