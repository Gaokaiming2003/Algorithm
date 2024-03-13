#include<iostream>
#include<vector>

using namespace std;

int maxValue(vector<int> &wgt, vector<int> &val, int cap, int n){
    //初始化dp表
    vector<vector<int> > dp(n + 1, vector<int>(cap + 1, 0));

    //状态转移

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= cap; j++){
            if(cap - wgt[i] < 0){
                //如果超过背包容量，必然不选
                dp[i][j] = dp[i - 1][j];
            } else{
                //不选和选择的最大值
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][cap];
}

