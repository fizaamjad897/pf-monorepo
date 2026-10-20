#include <iostream>
using namespace std;
int totalvolume(int size);
main()
{
    int size, result;
    cout << "Enter size: ";
    cin >> size;
    result = totalvolume(size);
    cout << result;
}
int totalvolume(int size)
{
    int i = 0;
    int n = 1;
    int sum = 0;
    int product = 1;
    int parameters[size];
    for (int idx = 0; idx < size; idx++)
    {
        cout << "Enter parameters(length, width, height): ";
        cin >> parameters[idx];
    }
    for(int idx = 0 ; idx < 3 * n ; idx++)
      {
        while(i * idx < 3 * n)
         {
            product = product * parameters[idx];
            i++;
         }
         sum = sum + product;
         n++;

      }
   return sum;
}
