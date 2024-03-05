/* 时间复杂度O(nlog n)
    空间复杂度O(n) */
#include<iostream>
#include<vector>

using namespace std;

//合并两数组
void merge(vector<int> &res, int left, int right){
    //左数组为[left, mid],右数组为[mid + 1, right]
    int mid = left + right >> 1;
    vector<int> tmp(right - left + 1);

    int i = left, j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){
        if(res[i] > res[j]){
            tmp[k++] = res[j++];
        }
        else {
            tmp[k++] = res[i++];
        }
    }

    while(i <= mid){
        tmp[k++] = res[i++];
    }
    while(j <= right){
        tmp[k++] = res[j++];
    }
    //res从left开始,tmp从0开始
    for(k = 0; k < tmp.size(); k++){
        res[left + k] = tmp[k];
    }
}

void mergeSort(vector<int> &res, int left, int right){
    if(left >= right) 
        return;
    int mid = left + right >> 1;
    
    mergeSort(res, left , mid); //左半数组排序
    mergeSort(res, mid + 1, right);//右半数组排序
    //合并
    merge(res, left, right);
}

int main(){
    std::vector<int> res{1,2,3,4,2,1,2,3,4,6,4};
    mergeSort(res, 0, res.size() - 1);
    for(auto c : res){
        std::cout << c << ' ';
    }
}