//
//  RectangleClass.hpp
//  FirstOOP
//
//  Created by brian on 7/19/22.
//

#ifndef RectangleClass_hpp
#define RectangleClass_hpp

#include <stdio.h>

class Rectangle
{
private:
    int height;
    int width;
public:
    Rectangle(int, int);
    ~Rectangle();
    void setHeight(int);
    void setWidth(int);
    int getHeight() const;
    int getWidth() const;
    int getArea() const;
};

#endif /* RectangleClass_hpp */
