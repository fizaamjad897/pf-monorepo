#include<iostream>
using namespace std;
int kakaprogress(int days);
main()
 {
    int days, result;
    cout<< "Enter number of days: ";
    cin>>days;
    result = kakaprogress(days);
    cout<<result;

 }
 int kakaprogress(int days)
  {
    int progressdays = 0;
    int miles[days];
    for(int idx= 0 ; idx < days; idx++)
     {
          cout<< "Enter miles on that day: ";
          cin>>miles[idx];
     }
     for(int idx = 0 ; idx < days-1 ; idx++)
      {
        if(miles[idx+1] > miles[idx])
         {
            progressdays++;
         }
      }
      return progressdays;
  }
