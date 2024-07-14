#pragma once
#include"cafes.h"
#include "order.h"
#include "rating.h"
#include <fstream>

class filemanager 
{
public:
    static void SaveMenuToFile(const cafes& item);
    static void SaveorderToFile(const order& orde);
    static void SaveratingToFile(const rating& ratin);
};

