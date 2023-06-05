//
//  main.cpp
//  AssignmentOnePart2
//
//  Created by brian on 6/19/22.
//  program calculates the total number of sick days of a banks tellers
//
#include <iostream>
using namespace std;

int main()
{
    int numTellers = 0, count = 0, total = 0;
    cout << "How many tellers worked at the bank over the past three years: ";
    cin >> numTellers;
    
    for (int i = 1; i <= numTellers; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << "How many days was teller " << i << " out for during year " << j << " : ";
            cin >> count;
            total += count;
        }
    }
    
    cout << "\nThe " << numTellers << " tellers were out for a total of " << total << " days over the last three years.\n";
    
    return 0;
}
