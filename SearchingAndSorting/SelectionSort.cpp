//
//  main.cpp
//  SelectionSort
//
//  Created by brian on 6/26/22.
//  program test and uses ascending selection sort algorithm
//
#include <iostream>
using namespace std;

void selectionSort(int[], int);

int main()
{
    const int SIZE = 7;
    int testArr[SIZE] = {4, 51, 49, -31, 4, 77, 22};
    
    for (int i = 0; i < SIZE; i++)
        cout << testArr[i] << " ";
    
    cout << endl;
    selectionSort(testArr, SIZE);
    
    for (int i = 0; i < SIZE; i++)
        cout << testArr[i] << " ";
    cout << endl;
    
    return 0;
}

void selectionSort(int inputArr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        int minValue = inputArr[i];
        
        for (int j = i + 1; j < size; j++)
        {
            if (inputArr[j] < minValue)
            {
                minValue = inputArr[j];
                minIndex = j;
            }
        }
        
        swap(inputArr[i], inputArr[minIndex]);
    }
}
