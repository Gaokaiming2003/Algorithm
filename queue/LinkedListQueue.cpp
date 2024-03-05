#include<iostream>
#include"ListNode.h"
#include<vector>
class LinkedListQueue
{
private:
    ListNode* front, *rear;
    int queueSize;
public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queueSize = 0;
    }
    ~LinkedListQueue() {
        free(front);
    }
    int size(){
        return queueSize;
    }

    bool isEmpty(){
        return size() == 0;
    }

    void push(int num){
        ListNode* node = new ListNode(num);
        if(isEmpty()) {
            rear = node;
            front = node;
        }
        else {
            rear -> next = node;
            rear = node;
        }
            queueSize++;
    }

    int pop(){
        int num = front -> val;
        ListNode* tmp = front;
        front = tmp -> next;
        delete tmp;
        queueSize--;
        return num;
   }

    int peek(){
        if(isEmpty()) 
            throw out_of_range("队列为空");
        return front -> val;
    } 

    vector<int> toVector(){
        vector<int> res(size());
        ListNode* node = front;
        for(int i = 0; i < size(); i++){
            res[i] = node -> val;
            node = node -> next;
        }
        return res;
    }
};

int main() {
    LinkedListQueue* llq = new LinkedListQueue();
    for(int i = 0; i < 5; i++) {
        llq -> push(i);
    }
    for(auto num : llq -> toVector()) {
        cout << num << endl;
    }
    cout << llq -> peek() << endl;
    
}
