#include<iostream>
using namespace std;
float calculatedprice(string userfruit, int quantity);
 main()
  {
    string userfruit;
    int quantity;
    float bill;
    cout<< "Enter the fruit: ";
    cin>>userfruit;
    cout<< "Enter quantity: ";
    cin>>quantity;
    bill = calculatedprice(userfruit, quantity);
    cout<<bill;
  }
  float calculatedprice(string userfruit, int quantity)
  {
    float calculatedprice, afterprice;
    string fruit[4] = {"peach", "apple", "guava", "watermelon"};
    int price[4] = {60, 70, 40, 30};
    for(int idx=0 ; idx < 4 ; idx++)
     {
        if(fruit[idx] == userfruit)
         {
            calculatedprice = price[idx];
            afterprice= quantity * calculatedprice;
         }
     }
     return afterprice;
  }