//
//  main.cpp
//  RecursiveMultiplication
//
//  Created by brian on 7/17/22.
//  program uses recursion to multiply numbers together
//
#include <iostream>
using namespace std;

int mult(int, int);

int main()
{
    cout << mult(64, 64) << endl;
    
    return 0;
}

int mult(int x, int y)
{
    if (y == 0)
        return 0;
    else
        return x + mult(x, (y - 1));
}
