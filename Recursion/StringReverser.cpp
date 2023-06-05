//
//  main.cpp
//  StringReverser
//
//  Created by brian on 7/17/22.
//  function accepts a string as a argument and returns the string backwards using recursion
//
#include <iostream>
#include <string>
using namespace std;

string rev(string, int);

int main()
{
    string tst = "gnome";
    cout << rev(tst, (int) tst.length()) << endl;
    
    return 0;
}

string rev(string inStr, int len)
{
    string tmp;
    
    if (len == 1)
        return inStr.substr(0, 1);
    else
    {
        tmp += inStr.substr((len - 1), 1);
        return tmp += rev(inStr, (len - 1));
    }
}
