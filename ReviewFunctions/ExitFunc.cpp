//
//  main.cpp
//  ExitFunc
//
//  Created by brian on 6/20/22.
//  practice using exit function
//
#include <cstdlib>
#include <iostream>
using namespace std;

void isEven(int);

int main()
{
    isEven(3);
    
    exit(EXIT_FAILURE);
}

void isEven(int num)
{
    if (num % 2 == 0)
        exit(EXIT_SUCCESS);
    else
        cout << "Not even!\n";
}
