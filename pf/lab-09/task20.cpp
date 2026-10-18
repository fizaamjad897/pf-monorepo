#include<iostream>
using namespace std;
void mergearray(int length1, int length2);
main()
 {
    int length1, length2;
    cout<< "Length of array1: ";
    cin>>length1;
    cout<< "Length of array2: ";
    cin>>length2;
    mergearray(length1, length2);
 }
void mergearray(int length1, int length2)
 {
    int array1[length1];
    int array2[length2];
    for(int idx = 0 ; idx < length1 ; idx++)
     {
        cin>>array1[idx];
     }
    for(int idx = 0 ; idx < length2 ; idx++)
     {
        cin>>array2[idx];
     }
    cout<<array1[0] <<",";
    for(int idx = 0 ; idx < length2 ; idx++)
     {
        cout<<array2[idx] <<",";
     }
    cout<<array1[length1 - 1];
 }
