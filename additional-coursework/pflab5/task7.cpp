#include<iostream>
using namespace std;
float volumeperc(float flowrate1, float flowrate2, float hours);
float pipe1perc(float volperc, float flowrate1, float hours);
float pipe2perc(float volperc, float flowrate2, float hours);
main()
 {
   float volume, flowrate1, flowrate2, volperc, pipe1percent, pipe2percent;
   float hours;
   cout<< "Enter the volume of pool ";
   cin>>volume;
   cout<< "Enter the flow rate of pipe 1 ";
   cin>>flowrate1;
   cout<< "Enter the flow rate of pipe 2 ";
   cin>>flowrate2;
   cout<< "Enter the number of hours the worker is absent.. ";
   cin>>hours;
   volperc= volumeperc(flowrate1, flowrate2, hours);
   pipe1percent = pipe1perc(volperc, flowrate1, hours);
   pipe2percent = pipe2perc(volperc, flowrate2, hours);
   if(volume < volperc)
	 {
		int overflown;
		overflown = volperc - volume;
		cout<< "The water has overflown " <<overflown <<" litres in " <<hours <<" hours";
     }
	 else 
	 {
      float vol;
	  vol = (volperc/volume) * 100;
      cout<< "The pool is " <<vol << " % filled pipe1; " <<pipe1percent << "% pipe2: " <<pipe2percent <<"%";
     }
	}	 
        
 float volumeperc(float flowrate1, float flowrate2, float hours)
  {
	float totalflowrate1, totalflowrate2, totalf1f2;
	totalflowrate1= hours * flowrate1;
	totalflowrate2 = hours * flowrate2;		
	totalf1f2 = totalflowrate1 + totalflowrate2;	
	return totalf1f2;
  }
  float pipe1perc(float volperc, float flowrate1, float hours)
   {
	 int totalflowrate1;
	 int pipe1filled;
	 totalflowrate1= flowrate1 * hours;
	 pipe1filled= (totalflowrate1/volperc) * 100;
	 return pipe1filled;
   }
 float pipe2perc(float volperc, float flowrate2, float hours)
	{
	 int totalflowrate2;
	 int pipe2filled;
	 totalflowrate2= flowrate2 * hours;
	 pipe2filled= (totalflowrate2/volperc) * 100;
	 return pipe2filled;
	}


