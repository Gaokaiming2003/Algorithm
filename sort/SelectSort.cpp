#include<iostream>
#include<vector>
/* 冒泡排序 */
/* 时间复杂度：O(n^2)
   空间复杂度：O(1) */
void selectSort(std::vector<int> &res, int size){
    for(int i = 0; i < size - 1; i++){
        int min = res[i];
        for(int j = i + 1; j < size; j++){
            if(min > res[j]){
                min = res[j];
            }
        }
        int tmp = min;
        min = res[i];
        res[i] = tmp; 
    }
}

int main(){
    std::vector<int> res{1,2,3,4,2,1,2,3,4,6,4};
    selectSort(res, res.size());
    for(auto c : res){
        std::cout << c << ' ';
    }
}