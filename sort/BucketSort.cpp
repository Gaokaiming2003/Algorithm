/* 桶排序 */
#include<iostream>
#include<vector>
#include<algorithm>
#include"QuickSort.h"

using namespace std;

void bucketSort(vector<float> &nums){
    int k = nums.size() / 2;
    vector<vector<float> > buckets(k);
    for(float num : nums){
        int i = num * k;
        buckets[i].push_back(num);
    }
    for(vector<float> &bucket : buckets){
        sort(bucket.begin(), bucket.end());
    }

    int i = 0;
    for(vector<float> &bucket : buckets){
        for(auto num : bucket){
            nums[i++] = num;
        }
    }
}

int main(){
    vector<float> nums = {0.12, 0.99, 0.01,0.13, 0.23, 0.25, 0.28, 0.58, 0.89};
    bucketSort(nums);
    for(auto c : nums){
        cout << c << " " ;
    }
}