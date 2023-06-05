//
//  main.cpp
//  LinkedListExercises
//
//  Created by brian on 7/16/22.
//  practice creating, manipulating, and testing linked list
//
#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node *next;
};

//function prototypes
void display(Node*);
void search(Node*, int);
void append(Node*&, int);
void insert(Node*&, int);
void remove(Node*&, int);
void destroy(Node*&);


int main()
{
    Node* head = nullptr;
    append(head, 10);
    
    search(head, 11);
    
    append(head, 15);
    append(head, 20);
    append(head, 25);
    insert(head, 3);
    insert(head, 31);
    insert(head, 11);
    
    search(head, 11);
    
    display(head);
    
    remove(head, 7);
    
    display(head);
    
    remove(head, 11);
    remove(head, 3);
    remove(head, 31);
    
    display(head);
    
    destroy(head);
    
    display(head);
    
    return 0;
}

//displays the numbers in a linked-list
void display(Node *hPtr)
{
    cout << "\n––––––––––––––––––––––––––––––––––\n";
    while(hPtr)
    {
        cout << hPtr->num << " ";
        hPtr = hPtr->next;
    }
    cout << "\n––––––––––––––––––––––––––––––––––\n";
}


//searchs for an int in the linked list
void search(Node* hPtr, int num)
{
    if (!hPtr)
        cout << "Not found.\n";
    else
    {
        while (hPtr && hPtr->num != num)
        {
            hPtr = hPtr->next;
        }
        if (hPtr)
            cout << "Found.\n";
        else
            cout << "Not found.\n";
    }
}

//adds a node to the end of a list
void append(Node* &hPtr, int num)
{
    Node *newNode = new Node;
    newNode->num = num;
    newNode->next = nullptr;;
    
    if (!hPtr)
    {
        hPtr = newNode;
    }
    else
    {
        Node* tmp = hPtr;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

//inserts a node to the end of a list
void insert(Node* &hPtr, int num)
{
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->num = num;
    
    if (!hPtr)
        hPtr = newNode;
    else if (hPtr->num > num)
    {
        Node* tmp = hPtr;
        hPtr = newNode;
        newNode->next = tmp;
    }
    else
    {
        Node* curr = hPtr;
        Node* prev = hPtr;
        while ((curr) && (curr->num < num))
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

//if a specific value is in a linked list the func will delete the node
void remove(Node* &hPtr, int num)
{
    if (!hPtr)
        return;
    else if (hPtr->num == num)
    {
        Node* tmp = hPtr;
        hPtr = tmp->next;
        delete tmp;
    }
    else
    {
        Node* curr = hPtr;
        Node* prev = hPtr;
        while ((curr != nullptr) && (curr->num != num))
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr)
        {
            prev->next = curr->next;
            delete curr;
        }
    }
}

//destorys a linked-list
void destroy(Node* &hPtr)
{
    Node* tmp = nullptr;;
    while (hPtr)
    {
        tmp = hPtr;
        hPtr = hPtr->next;
        delete tmp;
    }
}



