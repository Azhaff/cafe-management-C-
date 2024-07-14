#include "order.h"
#include "admin.h"
#include "user.h"
#include "rating.h"
#include "customer.h"
#include <iostream>
using namespace std;

//taking order of a student
void order::AddItemStudent()
{
    int temp = 0;
    cout << "Enter your order name\n";
    string a;
    cin >> a;
    string s;
    s = "smenu.txt";
    for (int i = 0; i <= 9; i++)
    {
        cout << "Enter the names of the Items you want to order\n";
        cin >> ItemOrdered[i];
        ++temp;
        cout << "Do you want anything else?\n[0]No\n[1]Yes\n";
        int a = 1;
        cin >> a;
        if (a == 0)
        {
            break;
        }
    }
    TotalPrice = 0;
    for (int i = 0; i <= 9; i++)
    {
        
        //making the total
        ifstream od(s);
        string in, id;
        double pr;
        int ic, av;
        while (od >> in >> ic >> id >> pr >> av)
        {
            if (ItemOrdered[i] == in)
            {
                TotalPrice += pr;
            }
        }
        od.close();
    }

    //stroing the total price in file
    ofstream tot("total.txt", ios::app);
    for (int i = 0; i <= 9; i++)
    {
        tot << endl << a << endl << ItemOrdered[i] << endl << TotalPrice << endl << temp << endl;
    }
    tot.close();
    int ch;
    cout << "[1]Remove Items\n[2]Confirm Order\n[3]Cancel Order\n";
    cin >> ch;
    if (ch == 1)
    {
        RemoveItem();
    }
    else if (ch == 2)
    {
        ConfirmOrder();
    }
    if (ch == 3)
    {
        CancelOrder();
    }
}

//Same as add item for students
void order::AddItemFaculty()
{
    int temp = 0;
    cout << "Enter your order name\n";
    string a;
    cin >> a;
    string s;
    s = "amenu.txt";
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the names of the Items you want to order\n";
        cin >> ItemOrdered[i];
        ++temp;
        cout << "Do you want anything else?\n[0]No\n[1]Yes\n";
        int a = 1;
        cin >> a;
        if (a == 0)
        {
            break;
        }
    }
    TotalPrice = 0;
    for (int i = 0; i < 10; i++)
    {
        ifstream od(s);
        string in, id;
        double pr;
        int ic, av;
        while (od >> in >> ic >> id >> pr >> av)
        {
            if (ItemOrdered[i] == in)
            {
                TotalPrice += pr;
            }
        }
        od.close();
    }
    ofstream tot("total.txt", ios::app);
    for (int i = 0; i < 10; i++)
    {
        tot << endl << a << endl << ItemOrdered[i] << endl << TotalPrice << endl << temp << endl;
    }
    tot.close();
    int ch;
    cout << "[1]Remove Items\n[2]Confirm Order\n[3]Cancel Order\n";
    cin >> ch;
    if (ch == 1)
    {
        RemoveItem();
    }
    else if (ch == 2)
    {
        ConfirmOrder();
    }
    if (ch == 3)
    {
        CancelOrder();
    }
}

//same as add item for students
void order::AddItemNon()
{
    int temp = 0;
    cout << "Enter your order name\n";
    string a;
    cin >> a;
    string s;
    s = "nmenu.txt";
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the names of the Items you want to order\n";
        cin >> ItemOrdered[i];
        ++temp;
        cout << "Do you want anything else?\n[0]No\n[1]Yes\n";
        int a = 1;
        cin >> a;
        if (a == 0)
        {
            break;
        }
    }
    TotalPrice = 0;
    for (int i = 0; i < 10; i++)
    {
        ifstream od(s);
        string in, id;
        double pr;
        int ic, av;
        while (od >> in >> ic >> id >> pr >> av)
        {
            if (ItemOrdered[i] == in)
            {
                TotalPrice += pr;
            }
        }
        od.close();
    }
    ofstream tot("total.txt", ios::app);
    for (int i = 0; i < 10; i++)
    {
        tot << endl << a << endl << ItemOrdered[i] << endl << TotalPrice << endl << temp << endl;
    }
    tot.close();
    int ch;
    cout << "[1]Remove Items\n[2]Confirm Order\n[3]Cancel Order\n";
    cin >> ch;
    if (ch == 1)
    {
        RemoveItem();
    }
    else if (ch == 2)
    {
        ConfirmOrder();
    }
    if (ch == 3)
    {
        CancelOrder();
    }
}

//removing the items from the order 
void order::RemoveItem()
{
    string abc;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the names of the Items you want to remove\n";
        cin >> abc;
        cout << "Do you want to remove anything else?\n[0]No\n[1]Yes\n";
        int a = 1;
        cin >> a;
        if (a == 0)
        {
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        //taking the saved total of before and subtracting the removed item
        ifstream tot("total.txt");
        string a;
        string io;
        double tota;
        int count;
        while (tot >> a >> io >> tota >> count)
        {

            if (abc == io)
            {
                TotalPrice -= tota/count;
            }

        }
    }
    //confirming the order
        cout << "[1]Confirm Order\n[2]Cancel Order\n";
        int ab;
        cin >> ab;
        if (ab == 1)
        {
            ConfirmOrder();
        }
        else if(ab==2)
        {
            CancelOrder();
        }

}

//Calculating the total bill
double order::CalculateTotal()
{
    return TotalPrice;
}

//confirming the order and asking to rate the app
void order::ConfirmOrder()
{
    OrderStatus = "Confirmed";
    cout << "Order confirmed. Total price: " << TotalPrice << " PKR\n";
    rating ra;
    ra.rate();
}

//Cancelling order
void order::CancelOrder()
{
    OrderStatus = "Cancelled";
    cout << "Order cancelled. Total price refunded: " << TotalPrice << " PKR\n";
    customer cu;
    cu.choose();
}

