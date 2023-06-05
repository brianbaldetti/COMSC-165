//
//  main.cpp
//  C-StringFunctions
//
//  Created by brian on 7/3/22.
//  program interprets c-string using cstring header file
//
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int SIZE = 21;
    char cString1[SIZE] = "Hello ";
    char cString2[] = "World!";
    char cString3[] = "rld";
    
    cout << "Program will now output the inatilized c-strings.\n";
    cout << cString1 << endl;
    cout << cString2 << endl;
    
    cout << "\nProgram will now return the length of the c-strings.\n";
    cout << strlen(cString1) << endl;
    cout << strlen(cString2) << endl;
    
    cout << "\nProgram will now append c-string two to c-string one together.\n";
    cout << strcat(cString1, cString2) << endl;
    
    cout << "\nProgram will now copy the contents of c-string one to c-string two.\n";
    strcpy(cString1, cString2);
    cout << cString1 << endl;
    cout << cString2 << endl;
    
    cout << "\nProgram will now search for the chars \"rld\" in c-string one and will show all chars after them.\n";
    cout << strstr(cString1, cString3) << endl;
    cout << strstr(cString1, "o") << endl;
    
    
    return 0;
}
