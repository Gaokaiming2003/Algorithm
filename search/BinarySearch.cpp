#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &res, int target){
    int left = 0, right = res.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(res[mid] < target)
            left = mid + 1;
        else if(res[mid] > target)
            right = mid - 1;
        else 
            return mid;
    }
    return -1;
}