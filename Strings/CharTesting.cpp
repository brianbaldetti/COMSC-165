//
//  main.cpp
//  CharTesting
//
//  Created by brian on 7/3/22.
//  program test and uses char testing funcitons from cctype
//
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char test;
    
    cout << "Enter a char and the program will tell you the type of char it is: ";
    cin >> test;
    
    if (isprint(test))
    {
        cout << "The char is a printable character.\n";
        if (isalnum(test))
            cout << "The char is part of the alphabet or a number.\n";
        if (isalpha(test))
        {
            cout << "The char is part of the alphabet.\n";

            if (islower(test))
                cout << "The letter is lowercase.\n";
            else
                cout << "The lesser is uppercase.\n";
        }
        
        if (isdigit(test))
            cout << "The char is a number.\n";
        if (ispunct(test))
            cout << "The char is a punctuation type.\n";
        
    }
    if (isspace(test))
        cout << "The char is a space character.\n";
    
    
    return 0;
}
