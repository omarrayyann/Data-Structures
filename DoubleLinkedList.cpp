#include<iostream>
using namespace std;

class Node{
    private:
        int element;
        Node* next;
        Node* prev;
    public:
        Node(int element){
            next = NULL;
            prev = NULL;
            this->element = element;
        }
    friend class DoubleLinkedList;        
};

class DoubleLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoubleLinkedList(){
            head = new Node(0);
            tail = new Node(0);
            head->next = tail;
            tail->prev = head;
        }
        int size(){
            int count = 0;
            Node* temp = head;
            while(temp->next != tail){
                count++;
                temp = temp->next;
            }
            return count;
        }
        bool empty(){
            return size()==0;
        }
        void addFront(int element){
            Node* newNode = new Node(element);
            newNode->next = head->next;
            newNode->prev = head;
            newNode->next->prev = newNode;
            head->next = newNode;
        }
        void addBack(int element){
            Node* newNode = new Node(element);
            newNode->next = tail;
            newNode->prev = tail->prev;
            newNode->prev->next = newNode;
            tail->prev = newNode;
        }
        void removeFront(){
            if(!empty()){
                head->next = head->next->next;
                head->next->prev = head;
            }   
        }
        void removeBack(){
            if(!empty()){
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;
            }   
        }
        void display(){
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
                cout << temp->element << " ";
            }
        }
    
};