#include <fstream>
#include <iostream>
using namespace std;
main()
{
    string name;
    int marks;
    float percentage;
    char grade;
    fstream file;
    file.open("New.txt", ios::in);
    getline(file, name);
    cout<<"Name is " <<name <<endl;
    file>>marks;
    cout << "Marks is: " << marks <<endl;
    file >> percentage;
    cout << "Percentage is: " <<percentage <<endl;
    file >> grade;
    cout << "Grade is: " <<grade <<endl;
    file.close();
}