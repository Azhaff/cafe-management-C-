#pragma once
#include"admin.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Inherutance
class customer : public user
{

    //given functions
public:
    customer(int id, const string& un, const string& passw, const string& ut);
    customer();
    void choose();
    void vm();
    void po();
    void voh();
    void logout();
};
