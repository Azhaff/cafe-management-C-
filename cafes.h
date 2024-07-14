#pragma once
#include"user.h"

//Inheritance
class cafes : public user 
{

//Given functions and attributes
public:
    cafes(int id, const string& un, const string& passw, const string& ut);
    cafes();
    void choose();
    void vm();
    void plo();
    void ami();
    void rmi();
    void logout();
};

