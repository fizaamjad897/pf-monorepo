#include <iostream>
using namespace std;
void ispresent(int size);
main()
{
    int size;
    cout << "Enter size of an array: ";
    cin >> size;
    ispresent(size);
}
void ispresent(int size)
{
    int count = 0;
    char letter;
    string comparisonstring;
    string userstring[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter string: ";
        cin >> userstring[idx];
    }
    cout << "Enter letter: ";
    cin >> letter;
    for (int idx = 0; idx < size; idx++)
    {
        comparisonstring = userstring[idx];
        int i = 0;
        while (comparisonstring[i] != '\0')
        {
            if (comparisonstring[i] == letter)
            {
                count++;
            }
         i++;
        }
    }
    cout << count;
}
