/* 数组中可能存在重复元素 */
#include<iostream>
#include<vector>

using namespace std;

int binaryInsert(vector<int> &nums, int target){
    int i = 0, j = nums.size() - 1;

    while(i <= j){
        int mid = i + (j - i) / 2;
        if(nums[mid] > target)
            j = mid - 1;
        else if(nums[mid] < target)
            i = mid + 1;
        else 
            j = mid - 1; //如果nums中含有重复元素，插入到第一个重复元素，
                         //所以如果找到了target，应该缩小区间为[i, mid - 1]
    }
    return i;    //i是大于重复目标元素的第一个下标
}

/*  查找左边界问题
    给定一个长度为n的有序数组nums，其中可能包含重复元素。
    请返回数组中最左一个元素target的索引。若不包含该元素，则返回-1 */

int binarySearchLeftEdge(vector<int> &nums, int target){
    //如果有target，则i是target的索引
    //否则i是大于target的第一个元素
    int i = binaryInsert(nums, target);
    //if target不存在，返回-1
    if(i == nums.size() || nums[i] != target)
        return -1;
    //返回targe的索引
    return i;
}

/* 查找最右一个target */

//复用查找左边界

int binarySearchRightEdge(vector<int> &nums, int target){
    int i = binaryInsert(nums, target + 1);
    int j = i - 1;
    if(j == -1 || nums[j] != target)
        return -1;
    return j;
}