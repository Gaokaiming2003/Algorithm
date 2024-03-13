# 动态规划

## 问题判断

总的来说，如果一个问题包含重叠子问题、最优子结构，并满足无后效性，那么它通常适合用动态规划求解。然而，我们很难从问题描述中直接提取出这些特性。因此我们通常会放宽条件，先观察问题是否适合使用回溯（穷举）解决。

适合用回溯解决的问题通常满足“决策树模型”，这种问题可以使用树形结构来描述，其中每一个节点代表一个决策，每一条路径代表一个决策序列。

换句话说，如果问题包含明确的决策概念，并且解是通过一系列决策产生的，那么它就满足决策树模型，通常可以使用回溯来解决。

在此基础上，动态规划问题还有一些判断的“加分项”。

问题包含最大（小）或最多（少）等最优化描述。
问题的状态能够使用一个列表、多维矩阵或树来表示，并且一个状态与其周围的状态存在递推关系。
相应地，也存在一些“减分项”。

问题的目标是找出所有可能的解决方案，而不是找出最优解。
问题描述中有明显的排列组合的特征，需要返回具体的多个方案。
如果一个问题满足决策树模型，并具有较为明显的“加分项”，我们就可以假设它是一个动态规划问题，并在求解过程中验证它。

## 求解步骤

动态规划的解题流程会因问题的性质和难度而有所不同，但通常遵循以下步骤：描述决策，定义状态，建立dp表，推导状态转移方程，确定边界条件等。

## 0-1背包问题

| 给定n个物品，第i个物品的重量为wgt[i-1]、价值为val[i-1]，和一个容量为cap的背包。每个物品只能被选择一次，问在限定背包容量下能放入物品的最大价值。

### 第一步

动态规划的解题流程会因问题的性质和难度而有所不同，但通常遵循以下步骤：描述决策，定义状态，建立dp表，推导状态转移方程，确定边界条件等。

对于每个物品来说，不放入背包，背包容量不变；放入背包，背包容量减小。由此可得状态定义：当前物品编号i和剩余背包容量c，记为 
[i,c]。

状态[i,c]对应的子问题为：前i个物品在剩余容量为c的背包中的最大价值，记为dp[i,c],待求解的是dp[n,cap],因此需要有一个尺寸为(n+1)*(cap+1)的二维dp表。

### 第二步

找出最优子结构，进而推导出状态转移方程。

当我们做出物品i的决策后，剩余的是前i-1个物品的决策，可分为两种情况。

* 不放入物品i：背包容量不变，状态变化为[i-1,c].
* 放入物品i：背包容量减少wgt[i-1],价值增加val[i-1],状态变化为[i-1,c-wgt[i-1]].

状态转移方程为：$dp[i][j] = max(dp[i-1][j], dp[i-1][j-wgt[i-1]] + val[i-1])$
  
### 第三步

确定边界条件和状态转移顺序。

当无物品或无剩余背包容量时最大价值为0，即$dp[i,0],dp[0,c]$都等于0.

```c++
/* 0-1 背包：动态规划 */
int knapsackDP(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    // 初始化 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // 若超过背包容量，则不选物品 i
                dp[i][c] = dp[i - 1][c];
            } else {
                // 不选和选物品 i 这两种方案的较大值
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][cap];
}
```

## 完全背包问题

给定n个物品，第i个物品的重量为wgt[i - 1]、价值为val[i - 1]，和一个容量为cap的背包。每个物品可以重复选取，问在限定包容量下能放入物品的最大价值。

与01背包问题不同，每个物品可以重复选取，所以状态转移方程为
$dp[i][j] = max(dp[i-1][j], dp[i][j-wgt[i-1]]+val[i-1])$