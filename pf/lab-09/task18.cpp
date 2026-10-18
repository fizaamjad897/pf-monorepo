#include <iostream>
using namespace std;
void issmallest(int size);
main()
{
    int size;
    cout << "How many elements you want to enter: ";
    cin >> size;
    issmallest(size);
}
void issmallest(int size)
{
    bool isgreater = true;
    int smallest;
    int usernum[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter number: ";
        cin >> usernum[idx];
    }
    smallest = usernum[0];
    for (int idx = 0; idx < size; idx++)
    {
        if (usernum[idx] < smallest)
        {
            smallest = usernum[idx];
            if(usernum[idx] == smallest)
               {
                isgreater == false;
               }
        }
        
    }
    if(isgreater == true)
     {
        cout<< "The smallest value is: " <<smallest;
     }
    if(isgreater == false)
     {
        cout<< "All equal";
     }
    
}
