#include"admin.h"
#include"customer.h"
#include"order.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

//Constructor of customer
customer::customer(int id, const string& un, const string& passw, const string& ut) : user(ID, UN, pass, UT) {}

//Default constructor of customer
customer::customer()
{
    ID = 0;
    UN = "";
    pass = "";
    UT = "";
}

//Help function to choose the various functions
void customer::choose()
{
    cout << "[1]View menu\n";
    cout << "[2]Place Order\n";
    cout << "[3]View Order History\n";;
    cout << "[4]LOGOUT\n";

    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        vm();
        break;
    case 2:
        po();
        break;
    case 3:
        voh();
        break;
    case 4:
        logout();
        break;
    default:
        cerr << "Invalid choice. Exiting program...\n";
        exit(1);
    }
}

//View menu the same as admin vm
void customer::vm()
{
    cout << "Viewing menu\n";
    cout << "Faculty can order from all\n";
    cout << "\nFor Faculty\n";
    ifstream me("amenu.txt", ios::app);
    if (me.is_open())
    {
        string line;
        while (getline(me, line))
        {
            cout << line << '\n';
        }
    }
    else
    {
        cerr << "File doesnt exist\n";
        choose();
    }
    me.close();
    cout << "\nFor Student\n";
    ifstream menu("smenu.txt", ios::app);
    if (menu.is_open())
    {
        string line;
        while (getline(menu, line))
        {
            cout << line << '\n';
        }
    }
    else
    {
        cerr << "File doesnt exist\n";
        choose();
    }
    menu.close();

    cout << "\nFor Non-Faculty\n";
    ifstream men("nmenu.txt", ios::app);
    if (men.is_open())
    {
        string line;
        while (getline(men, line))
        {
            cout << line << '\n';
        }
    }
    else
    {
        cerr << "File doesnt exist\n";
        choose();
    }
    men.close();
    
    choose();

}


//Order processing and passing it to the order function
void customer::po()
{
    string ut;
    order o;
    cout << "Enter you user type again for confirmation\n";
    cin >> ut;
    if (ut == "Student" || ut == "student")
    {
        o.AddItemStudent();
    }
    else if (ut == "Faculty" || ut == "faculty")
    {
        o.AddItemFaculty();
    }
    else if (ut == "Non" || ut == "non")
    {
        o.AddItemNon();
    }
    else
    {
        cout<<"Please enter again\n";
        po();
    }
}

//code to display the whole ordered history in order file
void customer::voh()
{
    cout << "View order history\n";
    ifstream oh("total.txt", ios::app);
    if (oh.is_open())
    {
        string line;
        while (getline(oh, line))
        {
            cout << line << '\n';
        }
    }
    oh.close();
    choose();
}

//logout code
void customer::logout()
{
    cout << "Customer Logging out...\n";
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
        exit(1);
    }
}