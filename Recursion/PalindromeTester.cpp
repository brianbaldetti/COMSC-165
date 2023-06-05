//
//  main.cpp
//  Assignment10Part1
//
//  Created by brian on 7/17/22.
//  function test if a string is a paladrome
//
#include <iostream>
#include <string>
using namespace std;

bool palindrome(string);

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter a string to test: ";
        string test;
        getline(cin, test);
        palindrome(test) ? cout << "The string is a palindrome.\n\n" : cout << "The string isn't a palindrome.\n\n";
    }
    
    return 0;
}

bool palindrome(string str)
{
    bool status = false;
    
    if (str.length() <= 1)
        status = true;
    else if (str.at(0) == str.at(str.length() - 1))
    {
        status = palindrome(str.substr(1, str.length() - 2));
    }
    
    return status;
}
