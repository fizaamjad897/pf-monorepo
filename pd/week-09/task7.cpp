#include<iostream>
using namespace std;
int stringcount();
main()
 {
    int result;
    result = stringcount();
    cout<<result;
 }
 int stringcount()
  {
    int count = 0;
    string userstring1, userstring2;
    cout<< "Enter first string ";
    cin>>userstring1;
    cout<< "Enter second string ";
    cin>>userstring2;  
    for(int idx1 = 0 ; userstring1[idx1] != '\0'; idx1++)
     {
        for(int idx2 = 0 ; userstring2[idx2] != '\0' ; idx2++)
         {
            if(userstring1[idx1] == userstring2[idx2])
             {
                userstring2[idx2]='#';
                count++;
                break;
             }
         }
     }
     return count;
  }
