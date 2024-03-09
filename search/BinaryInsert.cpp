/* 给定一个长度为 
 的有序数组 nums 和一个元素 target ，数组不存在重复元素。现将 target 插入数组 nums
  中，并保持其有序性。若数组中已存在元素 target
  ，则插入到其左方。请返回插入后 target 在数组中的索引。 */
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

/* 二分查找插入点
    返回插入点的下标
    无重复元素 */
int binaryInsertIndex(vector<int> &nums, int target){
    /* 初始化区间[0, n - 1] */
    int i = 0, j = nums.size() - 1;
    while(i <= j){
        int mid = i + (j - i) / 2;
        /* 如果中间元素大于目标值 */
        if(nums[mid] > target)
            j = mid - 1;    //区间[i, mid - 1]
        else if(nums[mid] < target)
            i = mid + 1;   //区间[mid + 1, j]
        else 
            return mid;  //如果找到了目标元素，返回中间值
    }
    //当nums没有目标值时，循环结束，i指向大于target的第一个元素下标，
    //j指向小于target的一个元素下标
    //将target插入到i的位置
    return i;   
}
