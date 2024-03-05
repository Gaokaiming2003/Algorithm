/* 下标从零开始 */
#include<iostream>
#include<vector>
#include"TreeNode.h"

using namespace std;

class ArrayBinaryTree
{
private:
    vector<int> tree;

    void dfs(int i, string order, vector<int>& res){
        if(val(i) == INT_MAX)
            return;
        if(order == "pre")
            res.push_back(val(i));
        dfs(left(i), order, res);
        if(order == "mid")
            res.push_back(val(i));
        dfs(right(i), order, res);
        if(order == "post")
            res.push_back(val(i));
    } 
public:
    vector<int> pre_order_set;
    vector<int> mid_order_set;
    vector<int> post_order_set;
    ArrayBinaryTree(vector<int> arr){
        tree = arr;
    }
    ~ArrayBinaryTree(){
        vector<int> tmp;
        tree.swap(tmp);
    }

    /* 获取二叉树的大小 */
    int size(){
        return tree.size();
    }

    /* 获取索引值为i节点的值 */
    int val(int i){
        if(i < 0 || i >= size()){
            return INT_MAX;
        }
        return tree[i];
    }

    /* 获取索引值为i节点的左节点的索引值 */
    int left(int i){
        return 2 * i + 1;
    }

    /* 获取索引值为i节点的右节点的索引值 */
    int right(int i){
        return 2 * i + 2;
    }

    /* 获取索引值为i节点的父节点的索引值 */
    int parent(int i){
        return (i - 1) / 2;
    }

    vector<int> preOrder(){
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }
    
    vector<int> midOrder(){
        vector<int> res;
        dfs(0, "mid", res);
        return res;
    }
    
    vector<int> postOrder(){
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }

    vector<int> leverOrder(){
        vector<int> res;
        for(int i = 0; i < size(); i++){
            if(tree[i] != INT_MAX){
                res.push_back(tree[i]);
            }
        }
        return res;
    }
};

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8};

    ArrayBinaryTree* tree = new ArrayBinaryTree(arr);

    auto res = tree -> midOrder();

    for(auto c : res){
        cout << c << " ";
    }

    return 0;
}
