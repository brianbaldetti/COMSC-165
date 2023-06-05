//
//  main.cpp
//  Assignment5
//
//  Created by brian on 7/2/22.
//  program gathers stastics on movies that people have watched then returns the mean, median, and mode
//
#include <iostream>
#include <iomanip>
using namespace std;

//decares function parameters
double median(int*, int);
int mode(int*, int);
int* makeArray(int);
void getMovieData(int*, int);
void selectionSort(int[], int);
double avg(int[], int);

int main()
{
    //declares vaiables
    int *arrPtr;
    int size;
    
    //gathers survey size
    cout << "How many students were surveyed: ";
    cin >> size;
    
    //makes an array using makeArray func and sets *arrPtr as its pointer
    arrPtr = makeArray(size);

    //uses getMovieData funciton to fill array with data
    getMovieData(arrPtr, size);
    
    //sorts array
    selectionSort(arrPtr, size);
    
    //displays statistics
    cout << fixed << setprecision(2);
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "The median numbers of movies watched is: " << median(arrPtr, size) << endl;
    cout << "The average numbers of movies watched is: " << avg(arrPtr, size) << endl;
    
    if (mode(arrPtr, size) == -1)
        cout << "There is no mode for the number of movies watched.\n";
    else
        cout << "The mode for the numbers of movies watched is: " << *(arrPtr + mode(arrPtr, size)) << endl;
    cout << "\n-----------------------------------------------------------------------\n";
    
    //cleans up memory
    delete [] arrPtr;
    return 0;
}

//function finds and returns the median of the input array
double median(int* inputArr, int size)
{
    double total;
    double median;
    
    if (size % 2 == 0)
    {
        
        total = *(inputArr + (size / 2)) + *(inputArr + ((size / 2) - 1));
        median = total / static_cast<double>(2);
    }
    else
    {
        median = *(inputArr + (size / 2));
    }
    
    return median;
}

//function finds the mode of the input array passed as a argument
int mode(int* inputArr, int size)
{
    int* frequency = makeArray(size);
    int index, highest;
    
    //sets all values of frequency pointer to 0;
    for (int i = 0; i < size; i++)
    {
        *(frequency + i) = 0;
    }
    
    //sorts the number of times each element appears in the array
    for (int i = 0; i < size; i++)
    {
        
        for (int j = 0; j < size; j++)
        {
            if (*(inputArr + i) == *(inputArr + j))
                (*(frequency + i))++;
        }
    }
    
    //finds what element in the array has the highest frequency
    index = 0;
    highest = *(frequency + index);
    
    for (int i = 1; i < size; i++)
    {
        if (*(frequency + i) > highest)
        {
            highest = *(frequency + i);
            index = i;
        }
    }
    
    //returns the most common value in the input arr
    if (highest == 1)
        return -1;
    else
        return *(frequency + index);
    
}

//function dynamically creates an array pointer using the size of the funciton parameter
int* makeArray(int size)
{
    int *arrayPtr = new int[size];
    
    return arrayPtr;
}

//function gathers movie data from the user input
void getMovieData(int* inputArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "How many movies did student " << i + 1 << " see: ";
        cin >> *(inputArr + i);
    }
}


//function uses selection sort to sort an array
void selectionSort(int* inputArr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        
        int min = *(inputArr + i);
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            
            if (*(inputArr + j) < min)
            {
                min = *(inputArr + j);
                minIndex = j;
            }
        }
        
        swap(*(inputArr + minIndex), *(inputArr + i));
    }
}

//calculates the finds the average of the input array
double avg(int* inputArr, int size)
{
    int total = 0;
    
    for (int i = 0; i < size; i++)
    {
        total += *(inputArr + i);
    }
    
    return total / static_cast<double>(size);
}
