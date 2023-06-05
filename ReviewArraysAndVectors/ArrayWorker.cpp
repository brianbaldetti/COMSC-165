//
//  main.cpp
//  Assignment3Part1
//
//  Created by brian on 6/22/22.
//  assignment 3 part 1
//  program creates, organizes, and returns arrays
//
#include <iostream>
#include <iomanip>
using namespace std;

//declares func prototypes
void inputTemp(int[], int);
void arrSort(int[], int);
double returnAvg(int[], int);

int main()
{
    const int SIZE = 10;
    int temps[SIZE];
    
    //calls function to fill array and sort arr
    inputTemp(temps, SIZE);
    arrSort(temps, SIZE);
    
    //displays the avg of the temperatures
    cout << endl << fixed << setprecision(2);
    cout << "The average tempertures during this time period was: " << returnAvg(temps, SIZE);
    cout << " degrees.\n";
    
    return 0;
}

//gathers user input for ten temps
void inputTemp(int inputArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the temperture for day " << (i + 1) << " : ";
        cin >> inputArr[i];
    }
}

//bubble sort algorithm
void arrSort(int inputArr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = inputArr[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (inputArr[j] < min)
            {
                min = inputArr[j];
                minIndex = j;
            }
        }
        //swaps values of sort index and low index
        swap(inputArr[i], inputArr[minIndex]);
    }
}
//returns average of sorted arr
double returnAvg(int inputArr[], int size)
{
    double total = 0;
    
    for (int i = 0; i < size; i++)
    {
        total += inputArr[i];
    }
    
    return total / size;
}
