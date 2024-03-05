/* 给定一个 
 的二维网格 grid ，网格中的每个单元格包含一个非负整数,
 表示该单元格的代价。机器人以左上角单元格为起始点，每次
 只能向下或者向右移动一步，直至到达右下角
 单元格。请返回从左上角到右下角的最小路径和。 */
#define N 10
#define M 10
#include<iostream>
#include<vector>

using namespace std;


int minPathSumDP(vector<vector<int>> &grip){
    /* 计算二维数组的大小 */
    int n = grip.size(), m = grip[0].size();
    /* 定义记忆数组：记忆(i,j)到(0,0)的距离 */
    vector<vector<int>> mem(n, vector<int>(m));
    /* (0,0)到(0,0)的距离 */
    mem[0][0] = grip[0][0];
    /* 第一行 */
    for(int i = 1; i < n; i++)
        mem[i][0] = mem[i - 1][0] + grip[i][0];
    /* 第一列 */
    for(int j = 1; j < m; j++)
        mem[0][j] = mem[0][j - 1] + grip[0][j];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++)
            mem[i][j] = min(mem[i][j - 1], 
            mem[i - 1][j]) + grip[i][j];//取最小值
    }
    return mem[n - 1][m - 1];
}

int main(){
    vector<vector<int >> grid(N, vector<int>(M));
    vector<vector<int >> mem(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            grid[i][j] = i + j;
        }
    }

    cout << minPathSumDP(grid);
 }