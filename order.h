#pragma once
#include "menuit.h"
#include <string>
class order 
{
    //given attributes
public:
    int orderID;
    int CustomerID;
    string ItemOrdered[10];
    double TotalPrice;
    string OrderStatus;

    //given functions
public:
    void AddItemStudent();
    void AddItemFaculty();
    void AddItemNon();
    void RemoveItem();
    double CalculateTotal();
    void ConfirmOrder();
    void CancelOrder();
};
