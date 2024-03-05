#include<iostream>
#include<vector>
using namespace std;
class ArrayStack
{
private:
    vector<int> stack;
    int val;
public:
    int size() {
        return stack.size();
    }
    bool isEmpty() {
        return size() == 0;
    }
    void push(int num) {
        stack.push_back(num);
    }
    int pop() {
        int num = top();
        stack.pop_back();
        return num;
    }
    int top() {
        if(isEmpty()) 
            throw out_of_range("栈空");
        return stack.back();
    }
    vector<int> toVector() {
        return stack;
    }
};

int main() {
    ArrayStack* array_stack = new ArrayStack();
    int i = 5;
    while (i >= 0) {
        array_stack -> push(i);
        i--;
    }
    
    for (auto c : array_stack -> toVector()) {
        cout << c << endl;
    }
    return 0;
}


