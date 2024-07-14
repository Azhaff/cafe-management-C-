#pragma once
#include"user.h"
using namespace std;

//inheritance
class admin : public user
{

    //given functions
public:
    admin(int id, const string& un, const string& passw, const string& ut);
    admin();
    void choose();
    void vm();
    void ami();
    void rmi();
    void mi();
    void dff();
    void vuff();
    void vmiff();
    void vrff();
    void voff();
    void voh();
    void vpff();
  /*void cme();*/
    void logout();
};
