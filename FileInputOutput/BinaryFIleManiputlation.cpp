//
//  main.cpp
//  Assignment8Part3
//
//  Created by brian on 7/12/22.
//  program manipulates a binary file allowing the user to view, manipulate, and change data on the file
//
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 101;
struct Inventory
{
    char name[SIZE];
    int quantity;
    double wholesale;
    double retail;
};

void display(const Inventory&);   //displays any record
void getItem(Inventory&);         //fills in structure passed as argument
void displayRecord();             //displays a record the the user is searching for
void addRecord();                 //adds record to file
void changeRecord();              //changes a record of the file
void displayAll();                //displays all records of the file
void report();                    //reports on the info of all inventory items


int main()
{
    int input = 0;
    do
    {
        cout << "\n––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        cout << "Enter the operation you would like to perform: ";
        cout << "\n1––add record  2––search record    3––change record\n4––display all    5––report   6––exit\n";
        cin >> input;
        cin.ignore();
        cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        
        switch (input)
        {
            case 1:
            {
                addRecord();
                break;
            }
            case 2:
            {
                displayRecord();
                break;
            }
            case 3:
            {
                changeRecord();
                break;
            }
            case 4:
            {
                displayAll();
                break;
            }
            case 5:
            {
                report();
                break;
            }
            case 6:
            {
                cout << "Exiting the program now....\nGoodbye!\n";
                break;
            }
            default:
                cout << "Enter a valid integer between 1-6.\nTry again.\n";
        }
        
    } while (input != 6);
    
    return 0;
}

//displays data on a structure
void display(const Inventory& output)
{
    cout << "Name: " << output.name << endl;
    cout << "Quantity: " << output.quantity << endl;
    cout << "Wholesale price: " << output.wholesale << endl;
    cout << "Retail price: " << output.retail << endl;
}

//fills in structure passed as argument
void getItem(Inventory& output)
{
    cout << "Enter a name: ";
    cin.get(output.name, SIZE);
    cout << "Enter the quantity: ";
    cin >> output.quantity;
    cin.ignore();
    cout << "Enter the wholesale price: ";
    cin >> output.wholesale;
    cin.ignore();
    cout << "Enter the retail price: ";
    cin >> output.retail;
    cin.ignore();
}

//displays all records of the file
void displayAll()
{
    ifstream iFile("/Users/messenger01/Desktop/inventory.dat", ios::binary);
    Inventory tmp;
    
    if (iFile)
    {
        while (!iFile.eof())
        {
            iFile.read((char*) &tmp, sizeof(tmp));
            display(tmp);
        }
    }
    else
        cout << "Error! The file failed to open\n";
    
    iFile.close();
}

//adds a record to the file
void addRecord()
{
    Inventory tmp;
    ofstream oFile("/Users/messenger01/Desktop/inventory.dat", ios::app | ios::binary);
    
    if (oFile)
    {
        getItem(tmp);
        oFile.write((char*)(&tmp), sizeof(tmp));
    }
    else
        cout << "Error! The file failed to open.\n";

    oFile.close();
}

//displays the record a user searches for if it exist other displays no record; runs untilled stop char is intered
void displayRecord()
{
    ifstream iFile("/Users/messenger01/Desktop/inventory.dat", ios::binary);
    Inventory tmp;
    char search[SIZE];
    int input = -1;
    bool found = false;
    
    if (iFile)
    {
        do
        {
            cout << "Enter a item that you would like to search for: ";
            cin.getline(search, SIZE);
            
            while (!iFile.eof())
            {
                iFile.read((char*) (&tmp), sizeof(tmp));
                
                if (strcmp(tmp.name, search) == 0)
                {
                    cout << "The item was found.\n";
                    display(tmp);
                    found = true;
                    break;
                }
            }
            
            if (!found)
                cout << "The item was not found.\n";
            
            //prompts user if they would like to search the file again and resets the faile stream object
            found = false;
            cout << "\nEnter 1 to search again or -1 to stop search: ";
            cin >> input;
            cin.ignore();
            iFile.clear();
            iFile.seekg(0L, ios::beg);
            
        } while (input != -1);
    }
    else
        cout << "Error! The file failed to open.\n";
    
    iFile.close();
}

//used to alter a record in the file
void changeRecord()
{
    fstream ioFile("/Users/messenger01/Desktop/inventory.dat", ios::in | ios::out | ios::binary);
    Inventory tmp;
    Inventory alter;
    char search[SIZE];
    
    if (ioFile)
    {
        cout << "Enter a item that you would like to search for: ";
        cin.getline(search, SIZE);
        
        while (!ioFile.eof())
        {
            ioFile.read((char*) (&tmp), sizeof(tmp));
            
            if (strcmp(tmp.name, search) == 0)
            {
                cout << "The item was found. Enter the information that you would like to replace it with.\n";
                getItem(alter);
                long loc = ioFile.tellg();
                ioFile.seekp((loc - sizeof(alter)), ios::beg);
                ioFile.write((char*) (&alter), sizeof(alter));
                break;
            }
        }
        if (strcmp(tmp.name, search) != 0)
            cout << "The item was not found.\n";
    }
    else
        cout << "Error! The file failed to open.\n";
    
    ioFile.close();
}

//outputs detailed information about the contents of the file
void report()
{
    ifstream iFile ("/Users/messenger01/Desktop/inventory.dat", ios::binary);
    Inventory tmp;
    int totQuantity = 0;
    double totRetail = 0, totWholesale = 0;
    
    if (iFile)
    {
        while (!iFile.eof())
        {
            iFile.read((char*) (&tmp), sizeof(tmp));
            totQuantity += tmp.quantity;
            totRetail += (tmp.quantity * tmp.retail);
            totWholesale += (tmp.quantity * tmp.wholesale);
        }
        
        cout << "\nHere is the report on the inventory:\n";
        cout << "There is a total of " << totQuantity << " items.\n";
        cout << "The total wholesale value is " << totWholesale << " dollars.\n";
        cout << "The total retail value is " << totRetail << " dollars.\n";
    }
    else
        cout << "Error! The file failed to open.\n";
    
    iFile.close();
}
