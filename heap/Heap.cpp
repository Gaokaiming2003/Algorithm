#include<iostream>
#include<queue>
#include<list>

using namespace std;

int main(){
    priority_queue<int, list<int>, greater<int> > heap;

    heap.empty();

    heap.push(1);

    heap.pop();

    heap.size();

    heap.top();

}