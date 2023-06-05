//
//  main.cpp
//  Assignment6PartA
//
//  Created by brian on 7/4/22.
//  assignments allows user to manipulate strings
//
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int searchStr(char[], char[]); //searches for and returns the index of a string
void insertStr(char[]);
void appendStr(char[]);
void deleteStr(char[]);
void replaceStr(char[]);


int main()
{
    //defines and initializes c-string to manipulate
    char cString[100], charInput;

    cout << "Enter a string that you would like to manipulate: ";
    cin.getline(cString, 100);
    
    do
    {
        cout << "__________________________________________________________\n";
        cout << "Your current string is: " << cString << endl;
        cout << "___________________________________________________________\n";
        cout << "Enter an option to manipulate the string: " << endl;
        cout << "s - search i - insert a - append d - delete r - replace e - exit\n";
        cin >> charInput;
        cin.ignore();
        cout << "___________________________________________________________\n";
        
        switch (tolower(charInput))
        {
            case 's':
            {
                char searchedStr[100];
                cout << "What string would you like to search for: ";
                cin.getline(searchedStr, 100);
                
                if(searchStr(cString, searchedStr) != -1)
                    cout << "The string was found at index " << searchStr(cString, searchedStr) << ".\n";
                else
                    cout << "The string was not found.\n";
                break;
            }
            case 'i':
            {
                insertStr(cString);
                break;
            }
            case 'a':
            {
                appendStr(cString);
                break;
            }
            case 'd':
            {
                deleteStr(cString);
                break;
            }
            case 'r':
            {
                replaceStr(cString);
                break;
            }
            case 'e':
            {
                cout << "Exiting program. Bye!\n";
                break;
            }
            default:
            {
                cout << "That input is not recognized. Try again.\n";
                break;
            }
        }
    } while (tolower(charInput) != 'e');
    
    return 0;
}

//searches for a specific string inside of the user string and returns the index if found and -1 otherwise
int searchStr(char inputCh[], char searchCh[])
{
    int inputLen = strlen(inputCh), searchLen = strlen(searchCh), index = -1;
    for (int i = 0; i < (inputLen - (searchLen - 1)); i++)
    {
        
        
        if (strncmp(&inputCh[i], searchCh, searchLen) == 0)
        {
            index = i;
            return index;
        }
    }
    
    return index;
}

//inserts chars into the users input c-string by passing it as reference
void insertStr(char inputCh[])
{
    char insertCh[100], tempCh[100];
    int index;
    cout << "What string would you like to insert: ";
    cin.getline(insertCh, 100);
    cout << "What index would you like to insert the string " << insertCh << " : ";
    cin >> index;
    
    strcpy(tempCh, &inputCh[index]);
    inputCh[index] = '\0';
    strcat(inputCh, " ");
    strcat(inputCh, insertCh);
    strcat(inputCh, tempCh);
    
}

//appends text on to c-string
void appendStr(char inputCh[])
{
    char insertCh[100];
    cout << "What string would you like to append to the current string: ";
    cin.getline(insertCh, 100);
    
    strcat(inputCh, insertCh);
}

void deleteStr(char inputCh[])
{
    char searchedStr[100];
    char temp[100];
    cout << "What string would you like to search for: ";
    cin.getline(searchedStr, 100);
    int index = searchStr(inputCh, searchedStr);
    
    if (index == -1)
        cout << "The string was not found.\n";
    else
    {
        strcpy(temp, &inputCh[index + strlen(searchedStr)]);
        inputCh[index] = '\0';
        strcat(inputCh, temp);
        cout << "The updated string is: " << inputCh << ".\n";
    }
}

void replaceStr(char inputCh[])
{
    char replacedCh[100];
    char toReplaceCh[100];
    char temp[100];
    int index;

    cout << "Enter the string to replace: ";
    cin.getline(replacedCh, 100);
    cout << "Enter a string to replace the old one: ";
    cin.getline(toReplaceCh, 100);
    index = searchStr(inputCh, replacedCh);
    
    if (index == -1)
        cout << "The string does not exist.\n";
    else
    {
        strcpy(temp, &inputCh[index + strlen(replacedCh)]);
        inputCh[index] = '\0';
        strcat(inputCh, " ");
        strcat(inputCh, toReplaceCh);
        strcat(inputCh, temp);
        
        cout << "The updated string is: " << inputCh << endl;
    }
}
