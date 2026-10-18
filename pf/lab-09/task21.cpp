#include <iostream>
using namespace std;
bool changeavailable(float due);
    main()
{
    float due;
    bool result;
    cout << "Enter total due: ";
    cin >> due;
    result = changeavailable(due);
    if(result == true)
     {
        cout<< "true";
     }
    else
     {
        cout<< "false";
     }
}
bool changeavailable(float due)
{
    float change = 0;
    float orderchange[4];
    for (int idx = 0; idx < 4; idx++)
    {
        cout << "Enter change: ";
        cin >> orderchange[idx];
        change = change + (orderchange[idx]/100);
    }
    if (change > due)
    {
        return true;
    }
    else
    {
        return false;
    }
}