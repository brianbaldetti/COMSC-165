//
//  main.cpp
//  Exercise2G
//
//  Created by brian on 6/19/22.
//
#include <iostream>
using namespace std;

int main()
{
    int num1 = 10, num2 = 11;
    
    if (num2 == 0)
        cout << "Cannoy divide by zero.\n";
    else if (num1 % num2 == 0)
        cout << "yes\n";
    else
        cout << "no\n";
    
    return 0;
}
