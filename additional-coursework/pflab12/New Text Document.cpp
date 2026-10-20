#include<fstream>
#include<iostream>
using namespace std;
main()
 {
    string name = "Fiza";
    int marks = 124;
    float percentage = 93.56;
    char grade= 'A';
    fstream file;
    file.open("New.txt", ios::out);
    cout<<name;
    cout<<marks;
    cout<<percentage;
    cout<<grade;
 }