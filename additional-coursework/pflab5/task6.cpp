#include<iostream>
using namespace std;
void calculatetime(int hours, int minutes);
void calctime(int hours, int minutes);

main()
 {
   int hours;
   int minutes;
   cout<< "Enter hours ";
   cin>>hours;
   cout<< "Enter minutes ";
   cin>>minutes;
   if (hours < 23)
    {
      calculatetime(hours, minutes);
    }
    if (hours >= 23)
     { 
       calctime(hours, minutes);
     }


  }
  void calculatetime(int hours, int minutes)

  {
   int mins;
   int rem;
   int hrs;
   mins = minutes + 15;
   if (mins < 60)
    {
      cout<< "Time after 15 minutes is ";
      cout<<hours <<":" <<mins;
    }
   if (mins > 60)
    {
      rem= mins - 60;
      hrs= 1+ hours;
      cout<< "Time after 15 minutes is ";
      cout<<hrs <<":" <<rem;
     }
   }
void calctime(int hours, int minutes)

  {
   int mins;
   int rem;
   int hrs;
   mins = minutes + 15;
   if (mins < 60)
    {
      cout<< "Time after 15 minutes is ";
      cout<<hours <<":" <<mins;
    }
    if (mins > 60)
     {
       hrs = hours - 23;
       rem= mins - 60;
       cout<< "Time after 15 minutes is ";
       cout<<hrs <<":" <<rem;
     }
  }

 