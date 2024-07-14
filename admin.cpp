#include"admin.h"
#include"menuit.h"
#include"user.h"
#include"rating.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

//Constructor of admin
admin::admin(int id, const string& un, const string& passw, const string& ut) : user(ID, UN, pass, UT) {}

//Default constructor of admin
admin::admin()
{
    ID = 0;
    UN = "";
    pass = "";
    UT = "";
}

//Choose funtion to choose what the user wants to do
void admin::choose()
{
    cout << "[1] View menu\n";
    cout << "[2] Add items to menu\n";
    cout << "[3] Remove items from menu \n";
    cout << "[4] Manage Inventory\n";
    cout << "[5] Display from file\n";
    cout << "[6] View Users from file\n";
    cout << "[7] View menu from file\n";
    cout << "[8] View ratings from file\n";
    cout << "[9] View Order history\n";
    cout << "[10]View payment history\n";
    cout << "[11]LOGOUT\n";

    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        vm();
        break;
    case 2:
        ami();
        break;
    case 3:
        rmi();
        break;
    case 4:
        mi();
        break;
    case 5:
        dff();
        break;
    case 6:
        vuff();
        break;
    case 7:
        vmiff();
        break;
    case 8:
        vrff();
        break;
    case 9:
        voh();
        break;
    case 10:
        vpff();
        break;
    case 11:
        logout();
        break;
    default:
        cerr << "Invalid choice. Exiting program...\n";
        exit(1);
    }
}

//View menu code
void admin::vm()
{
    int c;
	cout << "Viewing menu\n";
    cout << "[1]Faculty Menu\n[2]Student Menu\n[3]Non-Faculty Menu\n";
    cin >> c;
    string s;
    switch (c)
    {
    case 1:
        s = "amenu.txt";
        break;
    case 2:
        s = "smenu.txt";
        break;
    case 3:
        s = "nmenu.txt";
        break;
    }

    //Using file handling to read the menus
    ifstream menu(s, ios::app);

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
    choose();
}

//Adding items to the menu
void admin::ami()
{
    cout << "Adding a new item\n";
    int c;
    cout << "[1]Faculty Menu\n[2]Student Menu\n[3]Non-Faculty Menu\n";
    cin >> c;
    string s;
    switch (c)
    {
    case 1:
        s = "amenu.txt";
        break;
    case 2:
        s = "smenu.txt";
        break;
    case 3:
        s = "nmenu.txt";
        break;
    }

    //using file handling to write menu on the file
    ofstream itemadd(s, ios::app);
    string IN,ID;
    int IC,avb;
    double price;
    cout << "Enter the new item name: ";
    cin >> IN;
    cout << "Enter the new item code: ";
    cin >> IC;
    cout << "Enter the new item discription: ";
    cin >> ID;
    cout << "Enter the new item price: ";
    cin >> price;
    cout << "Enter total stock available: ";
    cin >> avb;
    itemadd << IN << setw(20) << IC << setw(20) << ID << setw(20) << price << setw(20) << avb << endl;
    itemadd.close();
    cout << "Items added successfully\n";
    choose();
    
}

//Remving item for the file
void admin::rmi()
{
    cout << "Removing an item.\n";
    string itr;
    cout << "Enter the name of item: ";
    cin >> itr;
    int c;
    cout << "[1]Faculty Menu\n[2]Student Menu\n[3]Non-Faculty Menu\n";
    cin >> c;
    string s;
    //Taking the type of menu
    switch (c)
    {
    case 1:
        s = "amenu.txt";
        break;
    case 2:
        s = "smenu.txt";
        break;
    case 3:
        s = "nmenu.txt";
        break;
    }

    //using filehandling to take the item out of file
    ifstream menu(s);
    ofstream newfile("newfile.txt");
    string IN, ID;
    int IC,avb;
    double price;
    bool found = false;
    while (menu >> IN >> IC >> ID >> price >> avb) 
    {
        if (IN != itr) {
            newfile << IN << setw(20) << IC << setw(20) << ID << setw(20) << price << setw(20) << avb << endl;
        }
        else 
        {
            found = true;
        }
    }
    //closing menu
    menu.close();
    newfile.close();
    if (!found) {
        cout << "Item not found in the menu.\n";
        choose();
    }
    if (remove("amenu.txt") != 0) {
        perror("Error removing original menu file");
        choose();
    }
    if (rename("newfile.txt", "amenu.txt") != 0) {
        perror("Error renaming temporary file");
    }
    choose();

}

//Updating stock
void admin::mi()
{
    menuit m;
    m.UpdateStock();
}

//viewing the file of order history
void admin::voh()
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
    //closing file
    oh.close();
    choose();
}

//Using filename to display its content
void admin::dff()
{
    string fn;
    cout << "Enter the filename whose contents u want displayed\n";
    cin >> fn;
    ifstream file(fn);
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    choose();
}

//viewing the users file of passwords
void admin::vuff()
{
    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    choose();
}

//viewing menu info from file
void admin::vmiff()
{
    
    ifstream file("amenu.txt");
    ifstream fil("smenu.txt");
    ifstream fi("nmenu.txt");
    string line;
    cout << "FACULTY MENU\n";
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    cout << "STUDENT MENU\n";
    while (getline(fil, line))
    {
        cout << line << endl;
    }
    file.close();
    cout << "NON-FACULTY MENU\n";
    while (getline(fi, line))
    {
        cout << line << endl;
    }
    file.close();
    choose();
}

//viewing order history from file of order
void admin::voff()
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
}

//Viweing ratings from the files
void admin::vrff()
{
    ifstream rate("rate.txt");
    if (rate.is_open())
    {
        string line;
        while (getline(rate, line))
        {
            cout << line << '\n';
        }
    }
    else
    {
        cerr << "File doesnt exist\n";
        choose();
    }
    rate.close();
    choose();
}

//Viewing the total pays from the file
void admin::vpff()
{
    ifstream pay("payment.txt");
    if (pay.is_open())
    {
        string line;
        while (getline(pay, line))
        {
            cout << line << '\n';
        }
    }
    else
    {
        cerr << "File doesnt exist\n";
        choose();
    }
    pay.close();
    choose();
}

//logout function
void admin::logout()
{
    cout << "Admin Logging out...\n";
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
