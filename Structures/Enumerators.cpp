//
//  main.cpp
//  Enumerators
//
//  Created by brian on 7/10/22.
//  practice using enumerators
//
#include <iostream>
using namespace std;

//creates enumerated data type
enum Day {MON, TUE, WED, THUR, FRI, SAT, SUN};

int main()
{
    int x = 0;
    cout << "X is: " << x << endl;

    Day humpDay = WED;
    x = humpDay;
    
    cout << humpDay << endl;
    cout << "X is: " << x << endl;
    return 0;
}
