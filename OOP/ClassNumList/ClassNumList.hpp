//
//  ClassNumList.hpp
//  Assignment11
//
//  Created by brian on 7/19/22.
//
#ifndef ClassNumList_hpp
#define ClassNumList_hpp

#include <stdio.h>
class numList
{
private:
    int length = 0;
    double *list = nullptr;
public:
    numList(int);
    
    void setDouble(int, double);
    double getDouble(int) const;
    double getHigh() const;
    double getLow() const;
    double getAvg() const;
    
    ~numList()
    {   delete [] list; }
};
#endif /* ClassNumList_hpp */
