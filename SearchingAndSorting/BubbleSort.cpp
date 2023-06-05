//
//  main.cpp
//  BubbleSort
//
//  Created by brian on 6/26/22.
//  practice creating and using bubble sort algorithm
//
#include <iostream>
using namespace std;

void bubbleSort(int[], int);

int main()
{
    const int SIZE = 6;
    int arr[SIZE] = {4, 5, 1, 31, -1, 29};
    
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    
    bubbleSort(arr, SIZE);
    cout << endl;
    
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    
    cout << endl;
    return 0;
}

void bubbleSort(int inputArr[], int size)
{
    bool change = true;
    int count = 0;
    
    while(change)
    {
        change = false;
        
        for (int i = 0; i < size - 1; i++)
        {
            
            if (inputArr[i] < inputArr[i + 1])
            {
                swap(inputArr[i], inputArr[i+1]);
                change = true;
            }
        }
        
        count++;
    }
    
    cout << endl << count << endl;
}
