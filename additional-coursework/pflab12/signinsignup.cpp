#include <fstream>
#include <iostream>
using namespace std;
string names[100];
string passwords[100];
int usercount = 0;
int userchoice();
void usersignup(string signupname, string signuppassword);
bool isvalidusername(string username);
void usersignin(string loginusername, string loginpassword);
void storeinfile(string signupname, string signuppassword);
void viewuser();
void readdatafromfile();
main()
{
    bool isvalid, signupcheck;
    string signupname;
    string signuppassword;
    string loginname;
    string loginpassword;
    int choice;
    while (true)
    {
        readdatafromfile();
        choice = userchoice();
        while (choice != 0)
        {
            if (choice == 1)
            {
                cout << "Enter Name: " << endl;
                cin >> signupname;
                cout << "Enter password: " << endl;
                cin >> signuppassword;
                isvalid = isvalidusername(signupname);
                if (isvalid == true)
                {
                    usersignup(signupname, signuppassword);
                    storeinfile(signupname, signuppassword);
                    cout<< "Signuped successfully ";
                }
                else 
                {
                    break;
                }
            }
            if (choice == 2)
            {
                cout << "Enter Name: " << endl;
                cin >> loginname;
                cout << "Enter Password: " << endl;
                cin >> loginpassword;
                signupcheck = usersignin(loginname, loginpassword);
                if(signupcheck == true)
                 {
                    cout<<"Login successful";
                 }
                 else 
                  {
                    cout<< "Invalid credentials";
                  }
            }
            if (choice == 3)
            {
                viewuser();
            }
        }
    }
}
bool usersignin(string username, string password)
{
    bool isexist = false;
    for (int i = 0; i < usercount; i++)
    {
        if (username == names[i] && password == passwords[i])
        {
            isexist = true;
            usercount++;
        }
    }
    return isexist;
}
int userchoice()
{
    int choice;
    cout << "Type accordingly " << endl;
    cout << "1- Signup " << endl;
    cout << "2 - Sign in " << endl;
    cout << "3 - View users " << endl;
    cout << "0 - Exit " << endl;
    cin >> choice;
    return choice;
}
void usersignup(string username, string password)
{
    for (int i = 0; i < usercount; i++)
    {
        cin >> names[i];
    }
    for (int i = 0; i < usercount; i++)
    {
        cin >> passwords[i];
    }
}
void viewuser()
{
    cout << "Usernames \t\t Passwords";
    for (int i = 0; i < usercount; i++)
    {
        cout << names[i] << "\t\t" << passwords[i];
    }
}
void storeinfile(string username, string password)
{
    fstream file;
    file.open("storingfile.txt", ios ::app);
    file << username << endl;
    file << password;
    file.close();
}
bool isvalidusername(string username)
{
    bool isvalid = true;
    for (int i = 0; i < usercount; i++)
    {
        if (names[i] == username)
        {
            isvalid = false;
            return isvalid;
        }
    }
    return isvalid;
}
void readdatafromfile()
 {
    string username;
    string userpassword;
    fstream file;
    file.open("storingfile" , ios :: in);
    while(getline(file, username) && getline(file, userpassword))
     {
      names[usercount] = username;
      passwords[usercount] = userpassword;
      usercount++;
     }
     file.close();
 }

