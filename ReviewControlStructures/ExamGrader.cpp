//
//  main.cpp
//  Exercise2F
//
//  Created by brian on 6/19/22.
//
#include <iostream>
using namespace std;

int main()
{
    int exammark = 0;
    
    if (exammark >= 40)
    {
        cout << "A satisfactory result.\n";
        cout << "You may procede with your project.\n";
    }
    else
    {
        cout << "I'm afraid you have failed\n";
        cout << "You may re-enter next year\n";
    }
    
    return 0;
}
