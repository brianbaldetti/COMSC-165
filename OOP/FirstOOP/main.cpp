//
//  main.cpp
//  FirstOOP
//
//  Created by brian on 7/19/22.
//
#include <iostream>
#include "RectangleClass.hpp"
using namespace std;

int main()
{
    Rectangle first;
    cout << "Displaying default constructor attributes: \n";
    cout << "Height: " << first.getHeight() << endl;
    cout << "WIdth: " << first.getWidth() << endl;
    cout << "Area: " << first.getArea() << endl;
    Rectangle second(10, 10);
    cout << "Displaying non-default constructor attributes: \n";
    cout << "Height: " << second.getHeight() << endl;
    cout << "WIdth: " << second.getWidth() << endl;
    cout << "Area: " << second.getArea() << endl;
    first.setWidth(7);
    first.setHeight(8);
    cout << "Displaying a changed default constructor attributes: \n";
    cout << "Height: " << first.getHeight() << endl;
    cout << "WIdth: " << first.getWidth() << endl;
    cout << "Area: " << first.getArea() << endl;
    
    
    
    return 0;
}
