#include<iostream>
#include "user.h"
using namespace std;
int main() 
{
    //object of user to start the program
    user u;
    int a;
    cout << "[1] Register \n[2] Login\n[3] Exit\n";
    cin >> a;
    switch(a)
    {
    case 1:
        u.registe();
        break;
    case 2:
        u.login();
        break;
    case 3:
        cout << "Exiting....\n";
        return 0;
    default:
        cerr << "Invalid choice. Exiting program...\n";
        return 0;
    }
   
    return 0;
}
