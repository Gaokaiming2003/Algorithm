#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> &res, int size){
    for(int i = size - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
           if(res[j] > res[j + 1]){
                swap(res[j], res[j + 1]);
           } 
        }
    }
}

int main(){
    std::vector<int> res{1,2,3,4,2,1,2,3,4,6,4};
    bubbleSort(res, res.size());
    for(auto c : res){
        std::cout << c << ' ';
    }
}