#include <iostream>
using namespace std;
void nextalphabet(string userstring);
main()
{
    string userstring;
    cout << "Enter string: ";
    getline(cin, userstring);
    nextalphabet(userstring);
}
void nextalphabet(string userstring)
{
    for (int idx = 0; userstring[idx] != '\0'; idx++)
    {
        int ascii = int(userstring[idx]);
        int asciinext = ascii + 1;
        cout<<char(asciinext);
    }
    
}
