//
//  main.cpp
//  PartiallyFilledArrays
//
//  Created by brian on 6/22/22.
//  practice using and making partially filled arrays
//
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    int index = -1;
    
    vector<int> vecarr(SIZE);
    vecarr[5] = 99;
    vecarr.push_back(10);

     
    index++;
    arr[index] = 10;
    index++;
    arr[index] = 13;
    index++;
    arr[index] = 9;
      
    
    if (index == -1)
        cout << "The list is empty.\n";
    else
    {
        for (int i = 0; i <= index; i++)
            cout << "The value of index " << (i + 1) << " is : " << arr[i] << endl;
        
    }
    
    for (int i = 0; i < vecarr.size(); i++)
        cout << vecarr[i] << endl;
        
    return 0;
}
