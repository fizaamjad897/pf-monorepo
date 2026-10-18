#include <iostream>
using namespace std;
bool existingnumbers(int size);
main()
{
    int size;
    bool result;
    cout << "How many elements you want to enter: ";
    cin >> size;
    result = existingnumbers(size);
    if (result == true)
    {
        cout << "Already existed";
    }
    else
    {
        cout << "Do not exist ";
    }
}
bool existingnumbers(int size)
{
    int anothernum;
    int usernum[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter number: ";
        cin >> usernum[idx];
    }
    cout << "Enter the number you want to search: ";
    cin >> anothernum;
    for (int idx = 0; idx < size; idx++)
    {
        if (anothernum == usernum[idx])
        {
            return true;
        }
    }
    return false;
}
