//
//  main.cpp
//  Assignmnet10Part2
//
//  Created by brian on 7/17/22.
//  uses recursion to find a pair of numbers greatest common factor
//
#include <iostream>

int gcf(int, int);

int main()
{
    int num1, num2;
    do
    {
        std::cout << "Enter two numbers to compute their GCF (greatest common factor): ";
        std::cin >> num1 >> num2;
        
        if (num1 == -1)
        {
            std::cout << "Exiting program now.....bye!\n";
            break;
        }
        
        std::cout << "Their GCF (greatest common factor) is: " << gcf(num1, num2) << std::endl;
        
    } while (num1 != -1);
    
    return 0;
}

int gcf(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return gcf(y, (x % y));
}
