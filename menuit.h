#pragma once
#include <iostream>
using namespace std;
class menuit
{
    //given attributes
protected:
    int IC;
    string IN;
    string ID;
    double price;
    int avb;

    //given functions
public:
    menuit(const string& in, const string& id, int ic, double pr, int av);
    menuit();
    void UpdateStock();
};

