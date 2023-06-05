//
//  main.cpp
//  Assignment3Part3
//
//  Created by brian on 6/25/22.
//  program compares the contents of 3 vectors
//
#include <iostream>
#include <vector>
using namespace std;

//function prototypes
bool checkPins(vector<int>, vector<int>);

int main()
{
    //creates vectors
    vector<int> pin1 = {2, 4, 1, 8, 7, 9, 0};
    vector<int> pin2 = {2, 4, 6, 8, 7, 9, 0};
    vector<int> pin3 = {1, 2, 3, 4, 5, 6, 7};
    
    //test checkPins function
    if (checkPins(pin1, pin2))
        cout << "Error! Pins 1 and 2 are the same!\n";
    else
        cout << "Success! The pins 1 and 2 are different.\n";
        
    if (checkPins(pin1, pin3))
        cout << "Error! Pins 1 and 3 are the same!\n";
    else
        cout << "Success! The pins 1 and 3 are different.\n";
        
    if (checkPins(pin1, pin1))
        cout << "Success! Pins 1 and Pins 1 are the same.\n";
    else
        cout << "Error! Pins 1 and 1 are different.\n";
    
    cout << endl << endl << endl;
    
    return 0;
}

//if vectors are the same true is returned and false otherwise
bool checkPins(vector<int> vec1, vector<int> vec2)
{
    if (vec1 == vec2)
        return true;
    else
        return false;
}
