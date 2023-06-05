//
//  main.cpp
//  Assignment8Part2
//
//  Created by brian on 7/10/22.
//  file stores binary data of structures
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Inventory
{
    string name;
    int quantity;
    double wholeSale;
    double retail;
};

void add(fstream&);
void display(fstream&);
void change(fstream&);
void displayAll(fstream&);
void report(fstream&);
long location(int);

int main()
{
    //defines variables
    int input;
    fstream ioFile("/Users/messenger01/Desktop/test.dat", ios::in | ios::out | ios::binary);
    
    if(!ioFile)
    {
        cout << "Error1";
        return 9;
    }
    do
    {
        //gathers user input and displays switch options
        cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        cout << "What action would you like to perform.\n" << "1––add new data  2––display record 3––change record 4––display all records 5––display report 6––exit\n";
        cin >> input;
        cin.ignore();
        cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––-––––––\n";
        
        switch(input)
        {
            case 1:
            {
                add(ioFile);
                break;
            }
            case 2:
            {
                display(ioFile);
                break;
            }
            case 3:
            {
                change(ioFile);
                break;
            }
            case 4:
            {
                displayAll(ioFile);
                break;
            }
            case 5:
            {
                
                break;
            }
            case 6:
            {
                cout << "Closing the program now.....Bye!\n";
                break;
            }
            default:
                cout << "Please enter a valid value. Try again.\n";
        }
    } while (input != 6);
        
    
    return 0;
}

//adds a stucture to the end of file
void add(fstream& file)
{
    file.seekp(0L, ios::end);
    file.seekg(0L, ios::end);

    Inventory toAdd;
    
    cout << "Enter the data for the inventory item you would like to add.\n";
    cout << "Name: ";
    getline(cin, toAdd.name);
    cout << "Quantity: ";
    cin >> toAdd.quantity;
    cout << "Whole sale price: ";
    cin >> toAdd.wholeSale;
    cout << "Retail price: ";
    cin >> toAdd.retail;
    
    file.write(reinterpret_cast<char*>(&toAdd), sizeof(toAdd));
}

//displays data for a single struct
void display(fstream& file)
{
    file.seekp(0L, ios::beg);
    file.seekg(0L, ios::beg);

    Inventory tmp;
    string str;
    cout << "Enter a item to search for: ";
    getline(cin, str);
    
    while (!file.eof())
    {
        file.read(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        
        if (str.compare(tmp.name))
        {
            cout << "The record info is.\n";
            cout << "Name: " << tmp.name << endl;
            cout << "Quantity: " << tmp.quantity << endl;
            cout << "Whole sale: " << tmp.wholeSale << endl;
            cout << "Retail: " << tmp.retail << endl;
            return;
        }
    }
    
    cout << "The item does not exist.\n";
}

//alters the data in a file structure
void change(fstream& file)
{
    file.seekp(0L, ios::beg);
    file.seekg(0L, ios::beg);

    Inventory tmp;
    string str;
    long loc;
    cout << "Enter the item you would like to alter: ";
    getline(cin, str);
    
    while (!file.eof())
    {
        file.read(reinterpret_cast<char*>(&tmp), sizeof(tmp));
        if (str.compare(tmp.name))
        {
            loc = file.tellg();
            
            cout << "Item found.\n";
            cout << "Enter the changes to the data.\n";
            cout << "Enter the data for the inventory item you would like to add.\n";
            cout << "Name: ";
            getline(cin, tmp.name);
            cout << "Quantity: ";
            cin >> tmp.quantity;
            cout << "Whole sale price: ";
            cin >> tmp.wholeSale;
            cout << "Retail price: ";
            cin >> tmp.retail;
            
            file.seekp(loc, ios::beg);
            file.write(reinterpret_cast<char*>(&tmp), sizeof(tmp));
            return;
        }
    }
    
    cout << "The item searched for does not exist.\n";
}

//displays the data on all the recors
void displayAll(fstream& file)
{
    file.seekg(0L, ios::beg);
    Inventory tmp;
    int count = 0;
    
    while (!file.eof())
    {
        file.read(reinterpret_cast<char*>(&tmp), sizeof(tmp));

        cout << "---------------------------------------n";
        cout << "Name: " << tmp.name << endl;
        cout << "Quantity: " << tmp.quantity << endl;
        cout << "Whole sale: " << tmp.wholeSale << endl;
        cout << "Retail: " << tmp.retail << endl;
        cout << "---------------------------------------n";
        
        count++;
        file.seekg(location(count), ios::beg);

    }
}

long location(int length)
{
    long rtrnLong;
    Inventory tmp;
    rtrnLong = sizeof(tmp) * length;
    return rtrnLong;
}
