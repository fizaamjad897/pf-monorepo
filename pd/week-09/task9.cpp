#include <iostream>
using namespace std;
string Moves[] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
void dancemoves(string userstring);
void printingdancemoves(int idx, int digit);
main()
{
    int size;
    string userstring;
    cout << "Enter string: ";
    cin >> userstring;
    size = userstring.length();
    if (size > 4)
    {
        cout << "Invalid input";
    }
    if (size <= 4)
    {
        dancemoves(userstring);
    }
}
void dancemoves(string userstring)
{
    bool isvalid = false;
    int asc, digit, value;
    for (int idx = 0; userstring[idx] != '\0'; idx++)
    {
        asc = int(userstring[idx]);
        if (asc <= 57)
        {
            isvalid = true;
        }
        else
        {
            isvalid = false;
            break;
        }
    }
    if (isvalid == true)
    {
        for (int idx = 0; userstring[idx] != '\0'; idx++)
        {
            asc = int(userstring[idx]);
            digit = asc - 48;
            value = digit + idx;
            if (value <= 9)
            {
                cout << Moves[value] <<" ";
            }
            if (value > 9)
            {
                value = (value - 1) - 9;
                cout << Moves[value] <<" ";
            }
        }
    }
    if (isvalid == false)
    {
        cout << "Invalid data";
    }
}
