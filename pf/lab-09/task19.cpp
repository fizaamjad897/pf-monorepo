#include<iostream>
using namespace std;
float resistance(int numofvalues);
main()
 {
    int numofvalues;
    float result;
    cout<< "Enter number of resistances: ";
    cin>>numofvalues;
    result = resistance(numofvalues);
    cout<< result <<" ohms";
 }
 float resistance(int numofvalues)
  {
    float sum = 0;
    float resistances[numofvalues];
    for(int idx = 0 ; idx < numofvalues ; idx++)
     {
        cout<< "Enter value " <<idx+1 <<" : ";
        cin>>resistances[idx];
     }
     for(int idx = 0 ; idx < numofvalues ; idx++)
      {
         sum = sum + resistances[idx];
      }
    return sum;
  }
