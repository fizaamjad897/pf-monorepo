#include <iostream>
using namespace std;
void adjacentgreater(int size);
main()
{
    int size, result;
    cout << "How many elements you want to enter: ";
    cin >> size;
    adjacentgreater(size);
}
void adjacentgreater(int size)
{
    int count = 0;
    int element[size];
    int greaterelement[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter element  ";
        cin >> element[idx];
    }
    for (int idx = 0; idx < size - 1; idx++)
    {
        if (count >= 0)
        {
            if (element[idx] > element[idx - 1] && element[idx] > element[idx + 1])
            {
                greaterelement[count] = element[idx];
                cout << greaterelement[count] << ",";
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "No peaks ";
    }
}
