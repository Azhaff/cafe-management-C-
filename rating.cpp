#include "rating.h"
#include "payment.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructor of rating
rating::rating(const string& c, int rid, const string& mid, const string& cid, int s) : Comment(c), ratingID(rid), MenuID(mid), cidd(cid), Score(s) {}

//Default constructor of rating
rating::rating()
{
    ratingID = 0;
    MenuID = "";
    cidd = "";
    Score = 0;
    Comment = "";
}

//rating code and saving deatils in file
void rating::rate() 
{  
    cout << "\nThank you for ordering! ";
    cout << "\nEnter your id: ";
    cin >> ratingID;
    cout << "\nEnter the menu item: ";
    cin >> MenuID;
    cout << "\nEnter your name: ";
    cin >> cidd;
    cout << "\nEnter your rating (1-5): ";
    cin >> Score;
    cin.ignore();
    cout << "\nEnter your comment: : ";

    //Storing in file
    getline(cin, Comment);
    ofstream rati("rate.txt", ios::app);
    rati << cidd << endl << ratingID << endl << MenuID << endl << Score << endl << Comment << endl;
    rati.close();
    payment py;
    py.pp();
}