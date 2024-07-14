#include "menuit.h"
#include "admin.h"
#include <fstream>
#include<iomanip>
using namespace std;

//constructor for menu inventory
menuit::menuit(const string& in, const string& id, int ic, double pr, int av) :IN(in), ID(id), IC(ic), price(pr), avb(av){}

//default constructor
menuit::menuit()
{
    IN = "";
    ID = "";
    IC = 0;
    price = 0.0;
    avb = 0;
}

//updating the available stock to the new stock
void menuit::UpdateStock() 
{
    int SC;
    string SN;
    cout << "Enter name of the stock\n";
    cin >> SN;
    cout << "Enter new stock\n";
    cin >> SC;
    int c;
    cout << "[1]Faculty Menu\n[2]Student Menu\n[3]Non-Faculty Menu\n";
    cin >> c;
    string s;

    //taking the menu
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

    //updating the stock
    ifstream menu(s);
    ofstream update("newfile.txt");

    string IN, ID;
    int IC, avb;
    double price;

    //saving the new stock
    while (menu >> IN >> IC >> ID >> price >> avb)
    {

        if (IN == SN) {
            avb = SC;
        }
        update << IN << setw(20) << IC << setw(20) << ID << setw(20) << price << setw(20) << avb << endl;
    }

    menu.close();
    update.close();
    admin a;
    if (remove(s.c_str()) != 0)
    {
        perror("Error removing original menu file");
        a.choose();
    }
    if (rename("newfile.txt", s.c_str()) != 0) {
        perror("Error renaming temporary file");
        a.choose();
    }
    a.choose();

}