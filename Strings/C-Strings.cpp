//
//  main.cpp
//  C-Strings
//
//  Created by brian on 7/3/22.
//  program creates, works with, and outputs c-string
//
#include <iostream>
using namespace std;

int main()
{
    char cString1[] = "Hello!"; //creates c-string variable
    char cString2[20], cString3[20];
    cout << cString1 << endl;

    
    cout << "Enter a c-string without spaces and the program will print it out: ";
    cin >> cString2;
    cout << cString2 << endl;
    cin.ignore();
    
    cout << "Enter a c-string with a space and the program will print it out: ";
    cin.getline(cString3, 20);
    cout << cString3 << endl;
    
    
}
