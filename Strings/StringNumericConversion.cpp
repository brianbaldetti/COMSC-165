//
//  main.cpp
//  StringNumericConversion
//
//  Created by brian on 7/3/22.
//  program will test string numeric conversion functions using cstdlib header file
//
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int num1;
    long num2;
    double num3;
    char char1[20];
    
    num1 = atoi ("1234");
    num2 = atol ("567890");
    num3 = atof ("420.69");
    char * itoa(num1, char * char1, 10);
    
    cout << "\vPrinting out all the values\v";
    
    cout << char1 << endl;
    
    
    return 0;
}
