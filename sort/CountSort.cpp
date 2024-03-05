/* 计数排序 */
#include<iostream>
#include<vector>

using namespace std;

int maxInArray(vector<int> &res){
    int max = res[0];
    for(int i = 1; i < res.size(); i++){
        if(max < res[i]){
            max = res[i];
        }
    }
    return max;
}
void countingSort(vector<int> &nums){
    int m = maxInArray(nums);
    vector<int> counter(m + 1, 0);

    for(auto num : nums){
        counter[num]++;
    }

    for(int i = 0; i < m; i++){
        counter[i + 1] += counter[i];
    }

    int n = nums.size();
    vector<int> res(n);
    for(int i = n - 1; i >= 0; i--){
        int num = nums[i];
        res[counter[num] - 1] = num;
        counter[num] --;
    }
    nums = res;
}

int main(){
    std::vector<int> res{1,2,3,4,2,1,2,3,4,6,4};
    countingSort(res);
    for(auto c : res){
        std::cout << c << ' ';
    }
}