#include<iostream>
using namespace std;

class MyHeap{
    private:
        int* array;
        int size;
        int capacity;
    public:
        MyHeap(int capacity){
            array = new int[capacity];
            size = 0;
            this->capacity = capacity;
        }
        int getSize(){
            return size;
        }
        bool empty(){
            return size==0;
        }
        int parent(int i){
            return (i-1)/2;
        }
        bool hasLeft(int i){
            return 2*i+1<=size;
        }
        int left(int i){
            return 2*i+1;
        }
        bool hasRight(int i){
            return 2*i+2<=size;
        }
        int right(int i){
            return 2*i+2;
        }
        void double_capacity(){
            int* newArray = new int[capacity*2];
            for(int i = 0; i<capacity; i++){
                newArray[i] = array[i];
            }
            delete[] array;
            capacity *= 2;
            array = newArray;
        }
        void insert(int element){
            if(size+1<=capacity){
                double_capacity();
            }
            array[size]=element;
            up_heap(size);
            size++;
        }
        void up_heap(int i){
            while(parent(i)!=i){
                if(array[parent(i)]>array[i]){
                    int temp = array[i];
                    array[i] = array[parent(i)];
                    array[parent(i)] = temp;
                } else {
                    break;
                }
                i = parent(i);
            }
        }
        int min(){
            if(!empty()){
                return array[0];
            }
            return -1;
        }
        void downHeap(int i){
            if(!hasLeft(i) && !hasRight(i)){
                return;
            } else if (hasLeft(i) && hasRight(i)){
                if(array[left(i)]<array[right(i)]){
                    if(array[left(i)]<array[i]){
                        int temp = array[left(i)];
                        array[left(i)] = array[i];
                        array[i] = temp;
                        downHeap(left(i));
                    }
                } else {
                    if(array[right(i)]<array[i]){
                        int temp = array[right(i)];
                        array[right(i)] = array[i];
                        array[i] = temp;
                        downHeap(right(i));
                    }
                }
            }
        }
        void pop(){
            if(empty()){
                return;
            }
            size--;
            if(empty()){
                return;
            }
            array[0] = array[size];
            downHeap(0);
        }

};