#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<int> &res, int target, int l, int r){
    if(l > r)
        return -1;
    int mid = (l + r) >> 1;
    if(res[mid] > target)
        return dfs(res, target, l, mid - 1);
    else if(res[mid] < target)
        return dfs(res, target, mid + 1, r);
    else
        return mid;
}