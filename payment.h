#pragma once
#include<string>
using namespace std;

//Given attributes
class payment
{
private:
    int PaymentID;
    int OrderID;
    double Amount;
    string PaymentStatus;

    //Given functions
public:
    payment(int paymentID, int orderID, double amount, string paymentStatus);
    payment();
    void pp();
};

