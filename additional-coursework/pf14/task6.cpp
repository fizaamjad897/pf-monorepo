#include <iostream>
using namespace std;
void mergedarrays(int arr1[3][4], int arr2[3][4], int arr3[6][4]);
main()
{
    int arr1[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 5}, {3, 4, 5, 6}};
    int arr2[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 5}, {3, 4, 5, 9}};
    int arr3[6][4];
    mergedarrays(arr1, arr2, arr3);
}
void mergedarrays(int arr1[3][4], int arr2[3][4], int arr3[6][4])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr3[i][j] = arr1[i][j];
        }
        count++;
    }
    for (int r = 0; r < 3; r++)
    {
        for (int t = 0; t < 4; t++)
        {
            arr3[count][t] = arr2[r][t];
        }
        count++;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}
