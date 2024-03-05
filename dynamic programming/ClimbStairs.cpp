#include<iostream>
#include<vector>

using namespace std;

int dfsViolent(int n){
    if(n == 1 || n == 2){
        return n;
    }
    return dfsViolent(n - 1) + dfsViolent(n - 2);
}

int dfsMemoryHelper(int n, vector<int> &res){
    if(n == 1 || n == 2)
        return n;
    if(res[n] != -1)
        return res[n];
    res[n] = dfsMemoryHelper(n - 1, res) + dfsMemoryHelper(n - 2, res);
    return res[n];
}

int dfsMemory(int n){
    vector<int> res(n + 1, -1);
    dfsMemoryHelper(n, res);
}