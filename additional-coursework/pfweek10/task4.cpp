#include <iostream>
using namespace std;
int userarr[20];
bool isrepeatingcycle(int length, int repeatingnum);
main()
{
    int length, repeatingnum;
    bool result;
    cout << "Enter length of array: ";
    cin >> length;
    cout << "Enter length of each cycle: ";
    cin >> repeatingnum;
    result = isrepeatingcycle(length, repeatingnum);
    if(result == true)
     {
        cout<< "true";
     }
    else
     {
        cout<< "false";
     }
}
bool isrepeatingcycle(int length, int repeatingnum)
{
    int idx = 0;
    int userarr[length];
    bool isrepeating = false;
    if (repeatingnum < length)
    {
        for (int idx = 0; idx < length; idx++)
        {
            cout << "Enter value: " << idx + 1 << " ";
            cin >> userarr[idx];
        }
        if (repeatingnum > 1)
        {
            while (repeatingnum <= (length - 1))
            {
                if (userarr[repeatingnum] == userarr[idx])
                {
                    isrepeating = true;
                }
                else
                {
                    isrepeating = false;
                }
                repeatingnum++;
                idx++;
            }
        }
        if (repeatingnum == 1)
        {
            while (repeatingnum <= (length - 1))
            {
                if (userarr[repeatingnum] == userarr[idx])
                {
                    isrepeating = true;
                }
                else
                {
                    isrepeating = false;
                }
                repeatingnum++;
            }
        }
    }
    else
    {
        isrepeating = true;
    }
    return isrepeating;
}
