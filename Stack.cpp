#include<iostream>
using namespace std;

class MyStack{
    private:
        int* array;
        int size;
        int capacity;
    public:
        MyStack(){
            array = new int[1];
            size = 0;
            capacity = 1;
        }
        int getSize(){
            return size;
        }
        int getCapacity(){
            return capacity;
        }
        void push(int element){
            if(size+1>capacity){
                int new_capacity = capacity*2;
                int* newArray = new int[new_capacity];
                for(int i = 0; i<size; i++){
                    newArray[i] = array[i];
                }
                newArray[size] = element;
                size++;
                array = newArray;
                capacity = new_capacity;
            } else {
                array[size] = element;
                size++;
            }
        }
        void pop(){
            size = max(size-1,0);
        }
        int top(){
            if(size>0){
                return array[size-1];
            }
            return -1;
        }
        void display(){
            for(int i = 0; i<size; i++){
                cout << array[i] << " ";
            }
        }
};
