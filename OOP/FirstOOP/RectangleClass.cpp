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
    Rectangle(int h = 0, int w = 0)
    {
        height = h;
        width = w;
    }
    ~Rectangle()
    {}
    void setHeight(int h)
    {
        height = h;
    }
    void setWidth(int w)
    {
        width = w;
    }
    int getHeight() const
    {
        return height;
    }
    int getWidth() const
    {
        return width;
    }
    int getArea() const
    {
        return width * height;
    }
};

#endif /* RectangleClass_hpp */
