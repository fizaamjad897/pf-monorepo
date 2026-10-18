#include <iostream>
using namespace std;
void islargest(int size);
main()
{
    int size;
    cout << "How many elements you want to enter: ";
    cin >> size;
    islargest(size);
}
void islargest(int size)
{
    bool isdiff = false;
    int largest;
    int usernum[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter number: ";
        cin >> usernum[idx];
    }
    largest = usernum[0];
    for (int idx = 0; idx < size; idx++)
    {
        if (usernum[idx] > largest)
        {
            largest = usernum[idx];
            isdiff = true; 
        }
    }
    if(isdiff == true)
     {
        cout<< "The largest value is: " <<largest;
     } 
    if(largest == usernum[0])
     {
        cout<< "All equal";
     }
}
