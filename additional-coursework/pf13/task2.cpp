#include <iostream>
using namespace std;
string matrix[5][5] = {{".", ".", ".", "*", "."}, {"*", "*", ".", "*", "."}, {"*", ".", "*", "*", "."}, {".", ".", "*", "*", "."}, {".", "*", ".", "*", "."}};
main()
{
    char row, col;
    int rowindex;
    string userstring;
    cout << "Enter string";
    cin >> userstring;
    row = userstring[0];
    col = userstring[1];
    int i = int(col) - '0';
    if (row == 'A')
    {
        rowindex = 1;
    }
    if (row == 'B')
    {
        rowindex = 2;
    }
    if (row == 'C')
    {
        rowindex = 3;
    }
    if (row == 'D')
    {
        rowindex = 4;
    }
    if (matrix[rowindex][i] == ".")
    {
        cout << "Splash";
    }
    if (matrix[rowindex][i] == "*")
    {
        cout << "Boom";
    }
}