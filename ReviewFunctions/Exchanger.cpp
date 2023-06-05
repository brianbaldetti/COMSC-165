//
//  main.cpp
//  Assignment2Part1
//
//  Created by brian on 6/19/22.
//
#include <iostream>
using namespace std;

void exchange(float&, float&);

int main()
{
    float first, second;
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;
    
    cout << "The value of the first number is " << first << " while the value of the second number is " << second << endl;
    exchange(first, second);
    cout << "The numbers have now been swaped.\n";
    cout << "The value of the first number is " << first << " now and the value of the second number is now " << second << endl;
    
    return 0;
}

void exchange(float& number1, float& number2)
{
    float temp = number1;
    number1 = number2;
    number2 = temp;
}
