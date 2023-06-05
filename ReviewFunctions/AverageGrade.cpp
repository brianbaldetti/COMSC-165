//
//  main.cpp
//  Assignment2Part3
//
//  Created by brian on 6/19/22.
//
#include <iostream>
using namespace std;

void average(int, double, double&);

int main()
{
    int grades = 0, score = 0;
    double sum = 0, avg = 0;
    cout << "Enter the number of grades: ";
    cin >> grades;
    
    for (int i = 0; i < grades; i++)
    {
        cout << "Enter a numeric grade between 0-100: ";
        cin >> score;
        sum += score;
    }
        
    average(grades, sum, avg);
    
    cout << "The grade is a: ";
    
    if (avg >= 90)
        cout << "A";
    else if (avg >= 80)
        cout << "B";
    else if (avg >= 70)
        cout << "C";
    else if (avg >= 60)
        cout << "D";
    else
        cout << "F";
    
    cout << endl;
    
    return 0;
}

void average(int numGrades, double numSum, double& numAvg)
{
    numAvg = numSum / numGrades;
}
