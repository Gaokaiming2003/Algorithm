#include<iostream>
#include<vector>
using namespace std;

const int MAX_SIZE = 100;
class ArrayHeap
{
private:
    vector<int> heap;
    int size;
public:
    ArrayHeap(int root){
        size = 1;
        heap[0] = root;
    }
 
    int left(int i){
        return 2 * i + 1;
    }
    
    int right(int i){
        return 2 * i + 2; 
    }

    int parent(int i){
        return (i - 1) / 2;
    }

    int getSize(){
        return size;
    }

    int peek(){
        if(size == 0)
            throw out_of_range("堆空");
        return heap[0];
    }
    
    void push(int val){
        heap.push_back(val);
        int index = size;
        size++;
        while(index >= 0){
            int parent_val = heap[parent(index)];
            if(parent_val > val){
                return;
            }else if(parent_val < val){
                swap(heap[index], heap[parent(index)]);
                index = parent(index);
            } else{
                cout << "插入的值不合法" << endl;
            }
        }
    }

    int pop(){
        if(getSize() == 0)
            throw out_of_range("堆空");
        swap(heap[0], heap[getSize() - 1]);
        int res = heap[getSize() - 1];
        size--;
        int index = 0;
        while(true){
            int l = heap[left(index)], r = heap[right(index)];
            int cur = heap[index];
            int ma = max(l, cur, right);
            if(ma == l){
                swap(heap[left(index)], heap[index]);
                index = left(index);
            }else if(ma == r){
                swap(heap[right(index)], heap[index]);
                index = right(index);
            }
            else
                break;
        }
    }
};
