#include"payment.h"
#include"rating.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//Constructor for class
payment::payment(int paymentID, int orderID, double amount, string paymentStatus) : PaymentID(paymentID), OrderID(orderID), Amount(amount), PaymentStatus(paymentStatus) {}

//Default constructor for class
payment::payment()
{
    PaymentID = 0;
    OrderID = 0;
    Amount = 0.0;
    PaymentStatus = "";
}

//payment method and the code and storing of data in file
void payment::pp() 
{ 
    cout << "Enter your payment ID\n";
    cin >> PaymentID;
    OrderID = PaymentID;
    cout << "Enter your payment\n";
    cin >> Amount;
    PaymentStatus = "Paid";
    cout << "Payment processed successfully. Amount: " << Amount << " PKR\n";
    cout << "Your Order ID is " << OrderID << endl;
    cout << "Thank You SO Much!!! For Ordering from us\nYour order is on its way";

    //storing in file
    ofstream pay("payment.txt", ios::app);
    pay << PaymentID << endl << OrderID << endl << Amount << endl << PaymentStatus << endl;
    pay.close();
}