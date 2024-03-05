#include<iostream>
#include<vector>

using namespace std;

struct DoublyListNode{
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class LinkedListDeque
{
private:
    DoublyListNode* front, *rear;
    int deque_size;
public:
    LinkedListDeque(){
        front = nullptr;
        rear = nullptr;
        deque_size = 0;
    };
    ~LinkedListDeque(){
        DoublyListNode* pre, *cur = front;
        while(cur != nullptr){
            pre = cur;
            cur = cur -> next;
            delete pre;
        }
    }
    bool isEmpty() {
        return deque_size == 0;
    }
    int getSize(){
        return deque_size;
    }
    void push(int num, bool isFront){
        DoublyListNode* node = new DoublyListNode(num);
        if(isEmpty())
            front = rear = node;
        else if(isFront) {
            front -> prev = node;
            node -> next = rear;
        }
    }
};
