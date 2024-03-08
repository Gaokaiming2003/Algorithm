/* 给定三根柱子，记为 A、B 和 C 。起始状态下，柱子 A 上套着 
个圆盘，它们从上到下按照从小到大的顺序排列。我们的任务是要把这
个圆盘移到柱子 C 上，并保持它们的原有顺序不变（如图 12-10 所示
。在移动圆盘的过程中，需要遵守以下规则。
圆盘只能从一根柱子顶部拿出，从另一根柱子顶部放入。
每次只能移动一个圆盘。
小圆盘必须时刻位于大圆盘之上。 */

#include<iostream>
#include<vector>

using namespace std;

int res = 0;
void move(vector<int> &src, vector<int> &tar){
    /* 从src顶部拿出一个盘子 */
    int val = src.back();
    src.pop_back();
    /* 放到target上 */
    tar.push_back(val);
    res++;
}
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> tar){
    /* 如果src里只剩一个盘子，将这个盘子移动到target */
    if(i == 1){
        move(src, tar);
        return;
    }
    // 子问题 f(i-1) ：将 src 顶部 i-1 个圆盘借助 tar 移到 buf
    dfs(i - 1, src, buf, tar);
    // 子问题 f(1) ：将 src 剩余一个圆盘移到 tar
    move(src, tar);
    // 子问题 f(i-1) ：将 buf 顶部 i-1 个圆盘借助 src 移到 tar
    dfs(i - 1, src, buf, tar);
}
void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C){
    int n = A.size();
    dfs(n, A, B, C);
}

int main(){
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B;
    vector<int> C;
    solveHanota(A, B, C);
    cout << res;
}
/* 时间复杂度:O(2^n)
    空间复杂度:O(n) */