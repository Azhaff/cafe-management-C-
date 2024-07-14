#include "filemanager.h"
using namespace std;

//file managing the menu
void filemanager::SaveMenuToFile(const cafes& item) 
{
    //ofstream file("menu_items.txt", ios::app);
    //if (file.is_open()) {
    //    file << item.ItemID << ',' << item.ItemName << ',' << item.ItemDescription << ',' << item.Price << ',' << item.QuantityInStock << '\n';
    //    file.close();
    //}
}

//file managing the oder
void filemanager::SaveorderToFile(const order& orde) 
{
    ofstream file("ordes.txt", ios::app);
    if (file.is_open()) 
    {
        file << orde.orderID << ',' << orde.CustomerID << ',' << orde.TotalPrice << ',' << orde.OrderStatus << '\n';
        file.close();
    }
}

//file managing the rating
void filemanager::SaveratingToFile(const rating& ratin) 
{
    ofstream file("ratins.txt", ios::app);
    if (file.is_open()) {
        file << ratin.ratingID << ',' << ratin.MenuID << ',' << ratin.cidd << ',' << ratin.Score << ',' << ratin.Comment << '\n';
        file.close();
    }
}
