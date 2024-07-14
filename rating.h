#pragma once
#include <string>
using namespace std;

class rating 
{

    //given attributes
public:
    int ratingID;
    string MenuID;
    string cidd;
    int Score;
    string Comment;

    //given functions
    rating(const string& c, int rid, const string& mid, const string& cid, int s);
    rating();
    void rate();
};


