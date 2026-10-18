#include <iostream>
using namespace std;
void productnum(int size);
main()
{
    int size;
    cout << "How many elements you want to enter: ";
    cin >> size;
    productnum(size);
}
void productnum(int size)
{
    int anothernum, product;
    int usernum[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter number: ";
        cin >> usernum[idx];
    }
    cout << "Enter the number you want to multiply: ";
    cin >> anothernum;
    for (int idx = 0; idx < size; idx++)
    {
        product = usernum[idx] * anothernum;
        cout<<product <<endl;
    }

}
