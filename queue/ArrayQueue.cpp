#include<iostream>
#include<vector>
using namespace std;
class ArrayQueue
{
private:
    int front;
    int* nums;
    int queue_size;
    int queue_capacity;
public:
    ArrayQueue(int capacity){
        nums = new int[capacity];
        queue_capacity = capacity;
        front = queue_size = 0;
    }
    ~ArrayQueue(){
        delete []nums;
    }
    int getSize(){
        return queue_size;
    }
    bool isEmpty(){
        return queue_size == 0;
    }
    int getCapacity(){
        return queue_capacity;
    }
    int peek(){
        if(isEmpty())
            throw out_of_range("队列为空");
        return nums[front];
    }
    int pop(){
        int temp_front = peek();
        front = (front + 1) % queue_capacity;
        queue_size--;
        return temp_front;
    }
    void push(int num){
        if(queue_capacity == queue_size){
            cout << "队列已满" << endl;
            return;
        }
        int rear = (front + queue_size) % queue_capacity;
        nums[rear] = num;
        queue_size++;
    }
    vector<int> toVector(){
        vector<int> tmp(queue_size);
        for(int i = 0, j = front; i < queue_size; i++, j++) {
            tmp[i] = nums[j % queue_capacity];
        }
        return tmp;
    }
};
main(){
    ArrayQueue* queue = new ArrayQueue(10);
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    cout << "queue的容量为" << queue->getCapacity() <<endl;
    cout << "queue的大小为" << queue->getSize() << endl;
    cout << "队首为" << queue->peek() << endl;
    cout << queue->pop() << endl;
}
