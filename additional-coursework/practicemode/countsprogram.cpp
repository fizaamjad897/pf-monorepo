#include<iostream>
using namespace std;
main()
{
int userNum;
int countsof50;
int remaining1;
int countsof20;
int remaining2;
int countsof10;
int remaining3;
int countsof5;
int remaining4;
int countsof2;
int remaining5;
int countsof1;
cout<< "Enter input in rupees";
cin>> userNum;
countsof50= userNum/50;
cout<< "Counts of 50 are "<<countsof50;
remaining1= userNum-(countsof50 * 50);
countsof20=remaining1 / 20;
cout<<endl;
cout<< "Counts of 20 are " <<countsof20;
remaining2=remaining1-(countsof20 * 20);
countsof10=remaining2 / 10;
cout<<endl;
cout<< "Counts of 10 are "<<countsof10;
remaining3=remaining2-(countsof10 * 10);
countsof5=remaining3 / 5;
cout<<endl;
cout<< "Counts of 5 are " <<countsof5;
remaining4=remaining3- (countsof5 * 5);
countsof2=remaining4 / 2;
cout<<endl;
cout<< "Counts of 2 are " <<countsof2;
remaining5= remaining4- (countsof2 * 2);
countsof1=remaining5 / 1;
cout<<endl;
cout<< "Counts of 1 are " <<countsof1;
}