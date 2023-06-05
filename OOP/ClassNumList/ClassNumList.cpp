//
//  ClassNumList.cpp
//  Assignment11
//
//  Created by brian on 7/19/22.
//
#include "ClassNumList.hpp"

numList::numList(int len)
{
    length = len;
    list = new double[length];
}

void numList::setDouble(int index, double value)
{
    list[index] = value;
}

double numList::getDouble(int index) const
{
    return list[index];
}

double numList::getHigh() const
{
    double high = *list;
    for (int i = 1; i < length; i++)
    {
        if (list[i] > high)
            high = list[i];
    }
    
    return high;
}

double numList::getLow() const
{
    double low = *list;
    for (int i = 1; i < length; i++)
    {
        if (list[i] < low)
            low = list[i];
    }
    
    return low;
}

double numList::getAvg() const
{
    double total = *list;
    for (int i = 1; i < length; i++)
    {
        total += list[i];
    }
    
    return total / length;
}
