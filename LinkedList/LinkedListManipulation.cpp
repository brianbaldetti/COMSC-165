//
//  main.cpp
//  Assignment9
//
//  Created by brian on 7/16/22.
//  allows a user to create and manipulate a linked list
//
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

bool search(Node*, int);
void insert(Node*&, int);
void remove(Node*&, int);
void display(Node*&);


int main()
{
    int input = 0;
    int inValue = 0;
    struct Node* head = nullptr;
    do
    {
        cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        cout << "Enter a number for the operation you would like to perform: \n";
        cout << "  1––insert\t2––remove\t3––search\t4––display\t5––exit\n";
        cin >> input;
        cin.ignore();
        cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        switch(input)
        {
            case 1:
            {
                cout << "Enter a int: ";
                cin >> inValue;
                cin.ignore();
                insert(head, inValue);
                break;
            }
            case 2:
            {
                cout << "Enter a int: ";
                cin >> inValue;
                cin.ignore();
                remove(head, inValue);
                break;
            }
            case 3:
            {
                cout << "Enter a int: ";
                cin >> inValue;
                cin.ignore();
                search(head, inValue) ? cout << "The number is in the list.\n" : cout << "The number is not in the list.\n";
                break;
            }
            case 4:
            {
                display(head);
                break;
            }
            case 5:
            {
                cout << "Exiting the program now........bye!\n";
                break;
            }
            default:
            {
                cout << "That is not a valid input. Try again.\n";
            }
        }
    } while (input != 5);
    return 0;
}

//returns bool if a number is in the list
bool search(Node* hPtr, int num)
{
    while (hPtr)
    {
        if (hPtr->value == num)
            return true;
        hPtr = hPtr->next;
    }
    
    return false;
}

void insert(Node*& hPtr, int num)
{
    Node* newNode = new Node;
    newNode->next = nullptr;
    newNode->value = num;
    
    if (!hPtr)
    {
        hPtr = newNode;
    }
    else if (hPtr->value > num)
    {
        Node* tmp = hPtr;
        hPtr = newNode;
        newNode->next = tmp;
    }
    else
    {
        if (search(hPtr, num))
            cout << "The number is already in the list.\n";
        else
        {
            Node* curr = hPtr;
            Node* prev = nullptr;;
            while (curr && curr->value < num)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void remove(Node*& hPtr, int num)
{
    if (search(hPtr, num))
    {
        Node* curr = hPtr;
        Node* prev = nullptr;
        while (curr && curr->value != num)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr)
        {
            prev->next = curr->next;
            delete curr;
        }
    }
    else
        cout << "The number is not in the list.\n";
}

void display(Node*& hPtr)
{
    cout << "Here is the list of numbers: ";
    while (hPtr)
    {
        cout << hPtr->value << " ";
        hPtr = hPtr->next;
    }
}
