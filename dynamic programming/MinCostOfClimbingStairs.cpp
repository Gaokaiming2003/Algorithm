#include<iostream>
#include<vector>

using namespace std;

/* 空间优化后的最小代价 */
/* 只求到达最高台阶的代价 */
int dp(vector<int> &cost){
    int n = cost.size() - 1;
    if(n == 1 || n == 2)
        return cost[n];
    int a = cost[1], b = cost[2];
    /* a为爬到i - 2阶台阶的代价
        b为爬到i - 1阶台阶的代价
        每一阶台阶的代价都必须记录 */
    for(int i = 3; i <= n; i++){
        int tmp = b;
        b = min(a, b) + cost[i];  //爬到第i阶台阶的代价为min(a, b) + 当前台阶的代价
        a = tmp;
    }
    return b;
}

int main(){
    vector<int> res{1, 2, 3, 2, 2, 1, 9};
    cout << dp(res);
}