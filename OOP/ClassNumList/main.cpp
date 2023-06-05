//
//  main.cpp
//  Assignment11
//
//  Created by brian on 7/19/22.
//  program demonstrates the use of a basic class that stores and manipulates an array of ints
//
#include <iostream>
#include "ClassNumList.hpp"
using namespace std;


int main()
{
    int size;
    cout << "How big of a object would you like to create: ";
    cin >> size;
    numList test(size);
    
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    for (int i = 0; i < size; i++)
    {
        cin.ignore();
        double value;
        cout << "Enter value to fill in index " << i + 1 << " : ";
        cin >> value;
        
        test.setDouble(i, value);
    }

    
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    cout << "Displaying data from the numList class object: \n";
    for (int i = 0; i < size; i++)
    {
        cout << "The value for index " << i + 1 << " is: " << test.getDouble(i) << endl;
    }
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    cout << "Displaying high from the numList class object: " << test.getHigh() << endl;
    cout << "Displaying low from the numList class object: " << test.getLow() << endl;
    cout << "Displaying average from the numList class object: " << test.getAvg() << endl;
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";

    
    return 0;
}
