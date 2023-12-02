#include<iostream>
using namespace std;

class MyQueue{
    private:
        int* array;
        int size;
        int capacity;
        int rear;
        int front;
    public:
        MyQueue(int capacity){
            array = new int[capacity];
            size = 0;
            this->capacity = capacity;
            front = 0;
            rear = 0;
        }
        int getSize(){
            return size;
        }
        void enqueue(int element){
            if(size+1>capacity){
                cout << "Queue is full" << endl;
                return;
            } 
            array[front] = element;
            front++;
            size++;
        }
        void dequeue(){
            if(size>0){
            rear++;
            rear = rear%capacity;
            size--;}
        }
        int top(){
            if(size>0){
                return array[rear];
            }
            return -1;
        }
        void display(){
            if(size>0){
                int count = 0;
                for(int i = rear; i<capacity; i++){
                    cout << array[i] << " ";
                    count++;
                    if(count==size){
                        cout << endl;
                        return;
                    }
                }
                for(int i = 0; i<rear; i++){
                    cout << array[i] << " ";
                    count++;
                    if(count==size){
                        cout << endl;
                        return;
                    }
                }
            }
            cout << endl;
        }
};