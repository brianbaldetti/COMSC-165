//
//  main.cpp
//  Assignment4
//
//  Created by brian on 6/26/22.
//  program initializes a user defined array of integers then sort, searches, and analyses the data
//
#include <iostream>
using namespace std;

void selectionSort(int[], int);
int binarySearch(int[], int, int);
double mean(int[], int);

int main()
{
    //gathers user input to fill array
    int size = -1;
    while (size < 1 || size > 50)
    {
        cout << "Enter the size of the array you wish to create: ";
        cin >> size;
        
        if (size < 1 || size > 50)
            cout << "The size must be between 1-50.\n";
    }
    
    //creates array
    const int SIZE = size;
    int arr[SIZE];
    
    //fills array
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the value for element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    //outputs isze of array
    cout << "\n---------------------------------------------------------\n";
    cout << "The array created has a size of " << SIZE << ".\n";
    cout << "The array as entered is: \n";
    
    //outputs unsorted array
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    
    //outputs soted array
    cout << "\nThe array sorted is: \n";
    selectionSort(arr, SIZE);
    
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    
    //searches for number in array and returns result
    cout << "\nEnter a number to search for in the array: ";
    int searchInt;
    cin.ignore();
    cin >> searchInt;
    
    int searchResult = binarySearch(arr, SIZE, searchInt);
    
    searchResult >= 0 ? cout << "The location of the value is at index " << searchInt << ".\n" : cout << "That number is not in the array.\n";
    
    //returns mean of array
    cout << "The mean of the array is: " << mean(arr, SIZE) << ".\n";
    
    cout << "\n---------------------------------------------------------\n";

    
    return 0;
}

void selectionSort(int inputArr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        int minValue = inputArr[i];
        
        for (int j = i; j < size; j++)
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

int binarySearch(int inputArr[], int size, int search)
{
    int middle, right = size, left = 0;
    
    do
    {
        middle = (right + left) / 2;
        
        if (inputArr[middle] == search)
            return middle;
        else if (inputArr[middle] > search)
            right = middle - 1;
        else if (inputArr[middle] < search)
            left = middle + 1;
        
    } while (right <= left);
    
    return -1;
}

double mean(int inputArr[], int size)
{
    int total = 0;
    
    for (int i = 0; i < size; i++)
    {
        
        total += inputArr[i];
    }
    
    return total / size;
}

