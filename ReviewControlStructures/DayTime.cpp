//
//  main.cpp
//  Exercise2H
//
//  Created by brian on 6/19/22.
//
#include <iostream>
using namespace std;

int main()
{
    int time = 0;
    cout << "Enter a time: ";
    cin >> time;
    
    if (time > 2400 || time < 0)
        cout << "Enter a valid number.\n";
    else if (time == 0)
        cout << "mindnight\n";
    else if (time < 1200)
        cout << "good mornin\n";
    else if (time < 1400)
        cout << "good arfternoon\n";
    else
        cout << "good evening\n";
    
    return 0;
    
}
