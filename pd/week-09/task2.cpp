#include<iostream>
using namespace std;
float movieprice(string moviename);
main()
 {
    string moviename;
    float calculatedprice;
    cout<< "enter movie name: ";
    cin>>moviename;
    calculatedprice = movieprice(moviename);
    cout<<calculatedprice;
 }
 float movieprice(string moviename)
  {
    bool ismovie = false;
    float discountedprice;
    string movie[5] = {"Gladiator", "Star Wars", "Terminator", "TakingLives", "TombRider"};
    for(int idx = 0 ; idx < 4 ; idx++)
     {  
         if(idx % 2 == 1)
          {
             discountedprice = 500 - (500 * 0.05);
          }
         else 
          {
             discountedprice = 500 - (500 * 0.1);
          }
      }
        return discountedprice;
  }

