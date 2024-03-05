#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pri_queue;

int main(){
    pri_queue.push(1);
    pri_queue.push(2);
    pri_queue.push(3);
    pri_queue.push(4);
    pri_queue.push(5);

    int i = 5;
    while(i--){
        cout << pri_queue.top() << endl;
        pri_queue.pop();
    }

}