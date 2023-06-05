//
//  main.cpp
//  Assignment7
//
//  Created by brian on 7/10/22.
//  program creates a structure that contains data on soccer players and allows user to ––
//  manipulate and test the data
//
#include <iostream>
#include <string>
using namespace std;

//defines Player structure
struct Player
{
    string lastName;
    string firstName;
    int bMonth;
    int bDay;
    int bYear;
};

//function prototypes
void inputData(Player[]);
void makeCopy(const Player[], Player[]);
void display(const Player[]);
void sort(Player[]);
string searchName(const Player[], string);

const int SIZE = 10;

int main()
{
    //initializes variables
    Player playerData[SIZE], copyPlayerData[SIZE];
    int input = 0;

    //fills playerData array
    inputData(playerData);
    //copies playerData array to copyPlayerData array
    makeCopy(playerData, copyPlayerData);
    

    do
    {
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "Choose an option for the program to run:\n";
        cout << "1––input data   2––display original data   3––sort data    4––display sorted data  5––search by last name   6–exit the program\n";
        cout << "-------------------------------------------------------------------------\n";
        cin >> input;
        cin.ignore();
        
        switch (input)
        {
            case 1:
            {
                inputData(playerData);
                makeCopy(playerData, copyPlayerData);
                break;
            }
            case 2:
            {
                display(playerData);
                break;
            }
            case 3:
            {
                sort(copyPlayerData);
                break;
            }
            case 4:
            {
                display(copyPlayerData);
                break;
            }
            case 5:
            {
                string inputStr;
                
                do
                {
                    cout << "Enter a last name that would would like to search for.\n" << "Enter '//' to escape program.\n";
                    getline(cin, inputStr);
                    
                    if (inputStr == "//")
                        cout << "Exiting program.\n";
                    else
                        cout << "The result of your search is: " << searchName(playerData, inputStr) << endl;
                    

                } while (inputStr != "//");
                break;
            }
            case 6:
            {
                cout << "Bye\n" << "Exiting the program now.....\n";
                break;
            }
            default:
                cout << "Enter a valid input between 1–6.\n" << "Try again!\n";
        }
        
    } while(input != 6);
    
    
    return 0;
}

//function fills Player structure with data
void inputData(Player inputPlayerData[])
{
    cout << "Enter the names of 10 soccer players and their birth days below: \n";
    cout << "Last Name  First Name  Birthmoth   Birthday    BirthYear\n";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> inputPlayerData[i].lastName >> inputPlayerData[i].firstName >> inputPlayerData[i].bMonth >> inputPlayerData[i].bDay >> inputPlayerData[i].bYear;
        cin.ignore();
    }
}

//copies data from one array to another
void makeCopy(const Player inputPlayerData[], Player outputPlayerData[])
{
    for (int i = 0; i < SIZE; i++)
    {
        outputPlayerData[i].lastName = inputPlayerData[i].lastName;
        outputPlayerData[i].firstName = inputPlayerData[i].firstName;
        outputPlayerData[i].bMonth = inputPlayerData[i].bMonth;
        outputPlayerData[i].bDay = inputPlayerData[i].bDay;
        outputPlayerData[i].bYear = inputPlayerData[i].bYear;
    }
}

//displays the playerData from the unaltered playerData array
void display(const Player inputPlayerData[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Displaying data for player number " << i + 1 << ":\n";
        cout << "Last name: " << inputPlayerData[i].lastName << endl;
        cout << "First name: " << inputPlayerData[i].firstName << endl;
        cout << "Birth month: " << inputPlayerData[i].bMonth << endl;
        cout << "Birth day: " << inputPlayerData[i].bDay << endl;
        cout << "Birth year: " << inputPlayerData[i].bYear << endl;
    }
}

//sorts the data from the copiedPlayerData array by last name using iteration sort
void sort (Player inputPlayerData[])
{
    for (int i = 0; i < SIZE; i++)
    {
        int minIndex = i;
        string minValue = inputPlayerData[i].lastName;
        
        for (int j = 0; j < SIZE; j++)
        {
            if (minValue < inputPlayerData[j].lastName)
            {
                minIndex = j;
                minValue = inputPlayerData[j].lastName;
            }
        }
        swap(inputPlayerData[i].lastName, inputPlayerData[minIndex].lastName);
        swap(inputPlayerData[i].firstName, inputPlayerData[minIndex].firstName);
        swap(inputPlayerData[i].bMonth, inputPlayerData[minIndex].bMonth);
        swap(inputPlayerData[i].bDay, inputPlayerData[minIndex].bDay);
        swap(inputPlayerData[i].bYear, inputPlayerData[minIndex].bYear);
    }
}


//searches through playerData for specific last names
string searchName(const Player inputPlayerData[], string inputStr)
{
    string rtrnStr;
    for (int i = 0; i < SIZE; i++)
    {
        if (inputPlayerData[i].lastName.find(inputStr) != -1)
        {
            rtrnStr = inputPlayerData[i].lastName;
            return rtrnStr;
        }
    }
    
    return "Not found\n";
}


