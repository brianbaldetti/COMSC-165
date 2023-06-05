//
//  main.cpp
//  AppendAlgorithm
//
//  Created by brian on 7/14/22.
//  practice using append algoritm on linked list
//
#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node* next;
};

void append(Node*&, int); //adds node to end of list
void traverse(Node*); //displays numbers stored in nodes of linked-list

int main()
{
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 9999);
    traverse(head);
    
    
    return 0;
}

//adds node with specified value to the end of the list
void append(Node*&nodePtr, int inNum)
{
    Node* newNode = new Node;
    newNode->num = inNum;
    newNode->next = nullptr;
    
    if (!nodePtr)
    {
        nodePtr = newNode;
    }
    else
    {
        Node* tmp = nodePtr;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void traverse(Node* nodePtr)
{
    cout << "Running traversal\n";
    Node* tmp = nodePtr;
    while (tmp != NULL)
    {
        cout << tmp->num << endl;
        tmp = tmp->next;
    }
}
