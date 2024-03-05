/* 问题描述：
   给定一个共有n阶的楼梯，你每步可以上1阶或者2阶，请问有多少种方案可以爬到楼顶？ */
#include<iostream>
#include<vector>

using namespace std;

int dpViolent(int n){
    if(n == 1 || n == 2){
        return n;
    }
    return dpViolent(n - 1) + dpViolent(n - 2);
}

int dpMemoryHelper(int n, vector<int> &res){
    if(n == 1 || n == 2)
        return n;
    if(res[n] != -1)
        return res[n];
    res[n] = dpMemoryHelper(n - 1, res) + dpMemoryHelper(n - 2, res);
    return res[n];
}

int dpMemory(int n){
    vector<int> res(n + 1, -1);
    int count = dpMemoryHelper(n, res);
    return count; 
}

int dpDynamic(int n){
    vector<int> res(n + 1);
    res[1] = 1;
    res[2] = 2;
    for(int i = 3; i < n + 1; i++){
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n];
}

int dpSpaceOptimization(int n){
    if(n == 1 || n == 2)
        return n;
    int a = 1, b = 2;
    for(int i = 3; i <= n; i++){
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}
int main(){
    cout << dpSpaceOptimization(10);
    return 0;
}