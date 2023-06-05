//
//  main.cpp
//  Assignment2Part2
//
//  Created by brian on 6/19/22.
//
#include <iostream>
#include <iomanip>
using namespace std;

void speed(double, double, double&);

int main()
{
    double miles, time, mph;
    
    cout << "Enter the miles traveled: ";
    cin >> miles;
    cout << "Enter the time it took: ";
    cin >> time;
    
    speed(miles, time, mph);
    
    cout << fixed << setprecision(2);
    cout << "The speed at which you traveled was " << mph << " MPH.\n";
    
    return 0;
}

void speed(double distance, double time, double& mph)
{
    mph = distance / time;
}
