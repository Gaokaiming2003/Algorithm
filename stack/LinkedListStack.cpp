#include <iostream>
#include "ListNode.h"
#include <vector>
using namespace std;

class LinkedListStack
{
private:
    ListNode* stackTop;
    int stkSize;
public:
    LinkedListStack(/* args */){
        stackTop = nullptr;
        stkSize = 0;
    };
    ~LinkedListStack() {
        //freeMemoryLinkedList(stackTop);
    };
    int size() {
        return stkSize;
    }
    bool isEmpty() {
        return size() == 0;
    }
    void push(int x) {
        ListNode* node = new ListNode(x);
        node -> next = stackTop;
        stackTop = node;
        stkSize++;
    }
    int pop() {
        int num = top();
        ListNode* tmp = stackTop;
        stackTop = tmp -> next;
        delete tmp;
        stkSize--;
        return num;
    }
    int top() {
        if (isEmpty()) 
            throw out_of_range("栈空");
        return stackTop -> val;
    }
    vector<int> toVector() {
        ListNode* node = stackTop;
        vector<int> tmp(size());
        for (int i = size() - 1; i >= 0; i--)
        {
            tmp[i] = node -> val;
            node = node -> next;
        }
        return tmp;
    }
};

int main() {
    LinkedListStack* stack = new LinkedListStack();
    std::cout << "stack_size = " << stack -> size() << std::endl;
    int i = 5;
    while (i >= 0) {
        stack -> push(i);
        i--;
    }
    vector<int> vec = stack -> toVector();
    for(auto c : vec) {
        std::cout << c << std::endl;
    }
    return 0;
}