//
//  main.cpp
//  AssignmentOne
//
//  Created by brian on 6/19/22.
//
#include <iostream>
using namespace std;

int main()
{
    int sentinel = -1, input = 0, coffee = 0, tea = 0, coke = 0, oJ = 0;
    
    while (input != sentinel)
    {
        cout << "Please input the favorite beverage of person #1: Choose 1, 2, 3, or 4 from the above menu or type -1 to exit the program.\n";
        cin >> input;
        
        if (input == -1)
            cout << "Exiting the program.\n";
        else if (input == 1)
            coffee++;
        else if (input == 2)
            tea++;
        else if (input == 3)
            coke++;
        else if (input == 4)
            oJ++;
        else
            cout << "Please enter a valid input between 0-4, or -1 to exit the program.\n";
    }
    
    cout << "\nThe totals for the couts are:\n";
    cout << "Coffee: " << coffee << endl;
    cout << "Tea: " << tea << endl;
    cout << "Coke: " << coke << endl;
    cout << "Orange Juice: " << oJ << endl;
    
    return 0;
}
