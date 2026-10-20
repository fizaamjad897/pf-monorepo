#include <iostream>
using namespace std;
float volume(int length,int width,int height,string unit);
main ()
{
int length;
int width;
int height; 
string unit; 
cout << "enter length :";
cin >> length;
cout << "enter width:";
cin >> width;
cout << "enter height:";
cin >> height;
cout << "enter unit :";
cin >> unit;  
float Volume;
Volume = volume(length, width, height, unit);
cout << "volume of pyramid is :"<< Volume   <<"cubic"<< unit << endl; 
}
  float volume(int length,int width,int height,string unit)
   {
    
    float Volume;
    Volume=(length * width * height)/3;
    return Volume;
       
       
   } 