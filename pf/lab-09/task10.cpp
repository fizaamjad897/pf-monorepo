#include <iostream>
using namespace std;
void reverseorder(string userstring);
main()
{
    string userstring;
    cout << "Enter string: ";
    getline(cin, userstring);
    reverseorder(userstring);
}
void reverseorder(string userstring)
{
    int stringlength = userstring.length();
    string arr[stringlength];
    for (int idx = 0; userstring[idx] != '\0'; idx++)
    {
        arr[idx] = userstring[idx];
    }
    for(int idx = stringlength - 1 ; idx >= 0 ; idx--)
     {
        cout<<arr[idx];
     }
}
