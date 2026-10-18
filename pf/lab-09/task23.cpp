#include <iostream>
using namespace std;
void vowelsremoved(string userstring);
main()
{
    string userstring;
    cout << "Enter string: ";
    getline(cin, userstring);
    vowelsremoved(userstring);
}
void vowelsremoved(string userstring)
{
    for (int idx = 0; userstring[idx] != '\0'; idx++)
    {
        if (userstring[idx] == 'a' || userstring[idx] == 'e' || userstring[idx] == 'i' || userstring[idx] == 'o' || userstring[idx] == 'u' || userstring[idx] == 'A' || userstring[idx] == 'O' || userstring[idx] == 'I' || userstring[idx] == 'U' || userstring[idx] == 'U')
        {
            continue;
        }
        cout << userstring[idx];
    }
}
