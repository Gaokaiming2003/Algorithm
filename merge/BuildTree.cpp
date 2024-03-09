#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode
{
    int val{};
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

/* preOrder是前序遍历数组
    midOrder是节点值到索引的映射 */
TreeNode* dfs(vector<int> &preOrder, unordered_map<int, int> &midOrderMap, int i, int l, int r){
    
    if(r - l < 0)
        return nullptr;

    TreeNode* root = new TreeNode(preOrder[i]);

    int m = midOrderMap[preOrder[i]];

    root -> left = dfs(preOrder, midOrderMap, i + 1, l, m - 1);

    root -> right = dfs(preOrder, midOrderMap, i + 1 + m - l, m + 1, r);

    return root;
}

TreeNode* buildTree(vector<int>  &preOrder, vector<int> &midOrder){
    unordered_map<int, int> midOrderMap;
    for(int i = 0; i < midOrder.size(); i++)
        midOrderMap[midOrder[i]] = i;
    
    return dfs(preOrder, midOrderMap, 0, 0. midOrder.size() - 1);
}
