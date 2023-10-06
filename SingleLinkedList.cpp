#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
using namespace std;

class Node
{
private:
    int elem;   // data element
    Node *next; // Link (pointer) to the next Node

public:
    Node(int elem) : elem(elem), next(NULL)
    {
    }
    friend class MyLinkedList;
};

class MyLinkedList
{
private:
    Node *head; // pointer to the head of list
    int length = 0;

public:
    MyLinkedList();           // empty list constructor
    ~MyLinkedList();          // destructor to clean up all nodes
    bool empty() const;       // is list empty?
    void addFront(int elem);  // add a new Node at the front of the list
    void removeFront();       // remove front Node from the list
    int getIndexOf(int elem); // returns first index of an element in the list, -1 if the element is not present
    void display() const;
    void loadData(string);       // read a file and load it into the linked list
    void dumpData(string) const; // write the linked list to a file
    void sort();                 // sort the elements of the list
};

// constructor
MyLinkedList::MyLinkedList()
{
    this->head = NULL;
}
//====================================
// destructor to clean up all nodes
MyLinkedList::~MyLinkedList()
{
    while (!empty())
    {
        this->removeFront();
    }
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const
{
    if (this->head == NULL)
    {
        return true;
    }
    return false;
}
//====================================
// add a node at the front of the list
void MyLinkedList::addFront(int elem)
{
    Node *newNode = new Node(elem);
    newNode->next = head;
    head = newNode;
    length++;
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()

{
    if (!empty())
    {
        Node *temp = head;
        head = head->next;
        length--;
        delete temp;
    }
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem)
{
    Node *tempHead = head;
    int index = 0;
    if (tempHead != NULL)
    {
        if (tempHead->elem == elem)
        {
            return index;
        }
        index++;
        while (tempHead->next != NULL)
        {
            tempHead = tempHead->next;
            if (tempHead->elem == elem)
            {
                return index;
            }
            index++;
        }
    }
    return -1;
}
//==============================================
// display all nodes of the linked list
void MyLinkedList::display() const
{
    Node *temp = head;
    cout << "Head";
    if (temp != NULL)
    {
        cout << "->" << temp->elem;
    }
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
        cout << "->" << temp->elem;
    }

    cout << "->"
         << "Null" << endl;
}
//====================================
// sort the elments of the list using bubble_sort
void MyLinkedList::sort()
{
    for (int i = 0; i < length - 1; i++)
    {
        Node *temp = head;
        for (int j = length; j > 1; j--)
        {
            if (temp->elem > temp->next->elem)
            {
                int tempElement = temp->elem;
                temp->elem = temp->next->elem;
                temp->next->elem = tempElement;
            }
            temp = temp->next;
        }
    }
}