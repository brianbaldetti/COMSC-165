//
//  main.cpp
//  FactorialRecursion
//
//  Created by brian on 7/17/22.
//  practice creating and using recursion by creating factorial equation
//
#include <iostream>
using namespace std;

//function to perform factorial calculations
int factorial(int);

int main()
{
    int tst = 7;
    
    cout << "The number " << tst << " factored is: " << factorial(tst) << endl;
    
    return 0;
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial((num - 1));
}
