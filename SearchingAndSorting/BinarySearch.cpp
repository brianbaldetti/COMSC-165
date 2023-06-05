//
//  main.cpp
//  BinarySearch
//
//  Created by brian on 6/26/22.
//  practice using binary search algorithm
#include <iostream>
using namespace std;

int binarySearch(int[], int, int);

int main()
{
    int test[10] {0, 1, 2, 13, 14, 50, 69, 77, 81, 99};
    
    cout << binarySearch(test, 10, 99) << endl;
    
    
    return 0;
}

int binarySearch(int inputArr[], int size, int input)
{
    int middle, left = 0, right = size -1;
    
    do
    {
        middle = (left + right) / 2;
        
        if (inputArr[middle] == input)
            return middle;
        else if (inputArr[middle] > input)
            right = middle - 1;
        else if (inputArr[middle] < input)
            left = middle + 1;
        
    } while (left <= right);
    
    return -1;
}
