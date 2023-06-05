//
//  main.cpp
//  Assignment6PartB
//
//  Created by brian on 7/3/22.
//  reads a sentence as an input then converts each word in the sentence to pig latin
//
#include <iostream>
#include <string>
using namespace std;

string leftTrim(string);
string popWord(string&);
string toPigLatin(string);

int main()
{
    //defines strings and initalizes user input
    string userStr, word, pigLatinStr;
    cout << "Enter a string to translate into pig latin: ";
    getline(cin, userStr);
    
    //loop translates userStr string to piglatin
    while (userStr.length() > 0)
    {
        word = popWord(userStr);
        pigLatinStr += toPigLatin(word);
        pigLatinStr += ' ';
    }
    
    //returns user input
    cout << "The word translated to pig latin is: ";
    cout << pigLatinStr << endl;
    
    return 0;
}

//removes any leading whitespace from a string
string leftTrim(string inputStr)
{
    while (inputStr.at(0) == ' ')
    {
        
        inputStr.erase(0, 1);
    }
    
    return inputStr;
}

//returns a single word from a string and removes the returned word from the string
string popWord(string& inputStr)
{
    inputStr = leftTrim(inputStr);
    
    int j = 0;
    while (inputStr[j] != ' ' && inputStr[j] != '\0')
    {
        j++;
    }
    
    string returnWord = inputStr.substr(0, j);
    inputStr.erase(0, j);
    return returnWord;
}

//converts the argument to a piglatin word
string toPigLatin(string inputWord)
{
    
    char firstLtr = inputWord[0];
    inputWord.append(1, firstLtr);
    inputWord.append("ay");
    inputWord.erase(0, 1);
    
    return inputWord;
}



    
