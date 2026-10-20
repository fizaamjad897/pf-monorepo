#include<iostream>
using namespace std;
int count = 0;
int matrics[3][3] = {{1, 1 , 1},{0, 0, 1}, {0, 0, 1}};
main()
{
    bool isvalid1 = false, isvalid2 = false;
    // for(int r = 0 ; r < 3 ; r++)
    //  {
    //     for(int c = r ; r == c ; c++)
    //     {
    //       if(matrics[r][c] == 1)
    //        {
    //          isvalid == true;
    //        }
    //     }
    //  }
for(int r = 0 ; r < 3 ; r++)
 {
    for(int c = 0 ; c < 3 ; c++)
     {
        if(r == c)
         {
            if(matrics[r][c] == 1)
             {
                isvalid1 = true;
             }

         }
        if(matrics[r][c] == 0)
         {
            isvalid2 = true;
         }
     }
 }
 if(isvalid1 == true && isvalid2 == true)
  {
    cout<< "identity";
  }
  else 
   {
    cout<< "not identity";
   }
}