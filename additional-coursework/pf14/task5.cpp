#include<iostream>
using namespace std;
bool sparsematrix(int passingmatrix[][3]);
main()
 {
    int passingmatrix[3][3] = {{1,0,3} , {1,2,3}, {1,2,3}};
    bool issparse;
    issparse = sparsematrix(passingmatrix);
    if(issparse == false)
     {
        cout<< "False"
     }
    else
     {
        cout<< "True";
     }

 }
bool sparsematrix(int passingmatrix[][3])
 {
    bool isvalid;
    int comparison = (3 * 3)/2;
    int count = 0;
    for(int i = 0; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
         {
            if(passingmatrix[i][j] == 0)
             {
                count++;
             }
         }
    }
    if(comparison < count)
     {
         isvalid = true;
     }
    else
     {
        isvalid = false;
     }
     return isvalid;

 }
