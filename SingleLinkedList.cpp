#include<iostream>
using namespace std;

class Node{
    private:
        int element;
        Node* next;
    public:
        Node(int element){
            next = NULL;
            this->element = element;
        }
    friend class SingleLinkedList;        
};

class SingleLinkedList{
    private:
        Node* head;
    public:
        SingleLinkedList(){
            head = NULL;
        }
        int size(){
            int count = 0;
            Node* temp = head;
            while(temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }
        bool empty(){
            return head==NULL;
        }
        void addFront(int element){
            Node* newNode = new Node(element);
            if(empty()){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }
        void removeFront(){
            if(!empty()){
                head = head->next;
            }   
        }
       
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->element << " ";
                temp = temp->next;
            }
        }
};