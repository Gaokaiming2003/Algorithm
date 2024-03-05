/* 快速排序
    时间复杂度:O(nlog n) */
#include<iostream>
#include<vector>

using namespace std;

void insertSort(vector<int> &res, int size){
    for(int i = 1; i < size; i++){
        int j = i - 1;
        int num = res[i];
        while(j >= 0 && res[j] > num){
            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = num;
    }
}
int main(){
    std::vector<int> res{1,2,3,4,2,1,2,3,4,6,4};
    insertSort(res, res.size());
    for(auto c : res){
        std::cout << c << ' ';
    }
}