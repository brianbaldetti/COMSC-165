//
//  main.cpp
//  CharCaseConversion
//
//  Created by brian on 7/3/22.
//  program test case conversion functions
//
#include <cctype>
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a letter and the program will show the uppercase or lowercase version of it: ";
    char ltr;
    cin >> ltr;
    
    cout << "\nThe letter " << ltr << " in uppercase and lowercase format is: \n";
    cout << (char) toupper(ltr) << endl;
    cout << (char) tolower(ltr) << endl;
    
    
    return 0;
}
