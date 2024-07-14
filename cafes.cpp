#include "cafes.h"
#include"admin.h"
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//making an object for admin
admin a;

//Constructor for cafe staff
cafes::cafes(int id, const string& un, const string& passw, const string& ut) : user(ID, UN, pass, UT) {}

//Default constructor for the staff
cafes::cafes()
{
    ID = 0;
    UN = "";
    pass = "";
    UT = "";
}

//Making the choice easy
void cafes::choose()
{
    cout << "[1]View menu\n";
    cout << "[2]Process Order\n";
    cout << "[3]Add items to menu\n";
    cout << "[4]Remove items from menu \n";
    cout << "[5]LOGOUT\n";

    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        vm();
        break;
    case 2:
        plo();
        break;
    case 3:
        ami();
        break;
    case 4:
        rmi();
        break;
    case 5:
        logout();
        break;
    default:
        cerr << "Invalid choice. Exiting program...\n";
        exit(1);
    }
}

//viewing menu for all there menus
void cafes::vm()
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

//order processing
void cafes::plo()
{
    cout << "Processing Order\n";
}

//Adding new items to menu like admin
void cafes::ami()
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
    ofstream itemadd(s, ios::app);

    string IN, ID;
    int IC, avb;
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

//removing items from the menu like admin
void cafes::rmi()
{
    cout << "Removing an item.\n";
    string itr;
    cout << "Enter the name of item: ";
    cin >> itr;
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
    ifstream menu(s);
    ofstream newfile("newfile.txt");
    string IN, ID;
    int IC, avb;
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

//Loging out
void cafes::logout() {
    cout << "Cafe-Staff logging out...\n";
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
