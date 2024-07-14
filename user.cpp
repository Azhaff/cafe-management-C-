#include "user.h"
#include"admin.h"
#include"customer.h"
#include"cafes.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Constructor for user
user::user(int id, const string& un, const string& passw, const string& ut): ID(id), UN(un), pass(passw), UT(ut) {}

//Default Constructor for user
user::user()
{
    ID = 0;
    UN = "";
    pass = "";
    UT = "";
}

//help function to choose the functions
void user::choose()
{
    cout << "[1] Register \n[2] Login\n[3] Exit\n";
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        registe();
        break;
    case 2:
        login();
        break;
    case 3:
        cout << "Exiting program...\n";
        exit(0);
    default:
        cerr << "Invalid choice. Exiting program...\n";
        choose();
    }
}
//Registering user
void user::registe() 
{
    cout << "Registration:\n";
    cout << "Enter ID: ";
    cin >> ID;
    cout << "\nEnter Usernameame: ";
    cin >> UN;
    cout << "\nEnter Password: ";
    cin >> pass;
    cout << "\nEnter Usertype: ";
    cin >> UT;
    //Using file handling to store user info
    ofstream file_1("users.txt", ios::app);
    file_1 << ID << " " << UN << " " << pass << " " << UT << endl;
    file_1.close();
    cout << "Registration successful!\n";
    choose();
}

//Login code
void user::login()
{
    cout << "User Login:\n";
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter Password: ";
    cin >> pass;

    //Using filehandling to read from file aif user info is true
    ifstream file_1("users.txt");
    bool is = false;
    int id;
    string name, password, type;
    while (file_1 >> id >> name >> password >> type)
    {
        if (id == ID && password == pass)
        {
            UN = name;
            UT = type;
            is = true;
            break;
        }
    }
    file_1.close();
    if (is)
    {
        cout << "Login successful!\n";
        admin ad;
        customer cs;
        cafes cf;

        //checking the type of user
        if (UT == "Admin" || UT == "admin")
        {
            cout << "Welcome Dearest Admin "<<UN<<endl;
            ad.choose();  
        }
        else if (UT == "Student" || UT == "student")
        {
            cout << "Welcome Dearest Student "<<UN<<endl;
            cs.choose();
        }
        else if (UT == "Faculty" || UT == "faculty")
        {
            cout << "Welcome Dearest Faculty Member "<<UN<<endl;
            cs.choose();
        }
        else if (UT == "Non" || UT == "non")
        {
            cout << "Welcome Dearest Non-Faculty Member "<<UN<<endl;
            cs.choose();
        }
        else if (UT == "cafestaff" || UT == "Cafestaff" || UT == "CafeStaff")
        {
            cout << "Welcome Dearest Cafe Staff "<<UN<<endl;
            cf.choose();
        }
    }
    else
    {
        cout << "Invalid credentials. Login failed.\n";
        choose();
    }
}

//logout code
void user::logout() 
{
    cout << "Logging out...\n";
    choose();
}
