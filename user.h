#pragma once
#include<iostream>
using namespace std;
class user
{
    //Attributes of user
protected:
    int ID;
    string UN;
    string pass;
    string UT;

    //Functions of user
public:
    user(int id, const string& un, const string& passw, const string& ut);
    user();
    void choose();
    virtual void registe();
    virtual void login();
    virtual void logout();
};

