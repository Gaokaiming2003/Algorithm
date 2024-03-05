#include"TreeNode.h"
#include<vector>

std::vector<TreeNode* > pre_order_set; //前序遍历数组
std::vector<TreeNode* > mid_order_set; //中序遍历数组
std::vector<TreeNode* > post_order_set; //后序遍历数组

void preOrderDFS(TreeNode* root){ 
    /* 前序遍历 */
    /* root - left - right */
    if(root == nullptr) 
        return;
    pre_order_set.push_back(root);
    preOrderDFS(root -> left);
    preOrderDFS(root -> right);
}

void midOrderDFS(TreeNode* root){
    /* 中序遍历 */
    /* left - root - right */
    if(root == nullptr) 
        return;
    midOrderDFS(root -> left);
    mid_order_set.push_back(root);
    midOrderDFS(root -> right);
}

void postOrderDFS(TreeNode* root){
    /* 后序遍历 */
    /* left - right - root */
    if(root == nullptr) 
        return;
    
    postOrderDFS(root -> left);
    postOrderDFS(root -> right);
    post_order_set.push_back(root);
}

int main(){
    TreeNode* n1 = new TreeNode(1);    
    TreeNode* n2 = new TreeNode(2);    
    TreeNode* n3 = new TreeNode(3);    
    TreeNode* n4 = new TreeNode(5);    
    TreeNode* n5 = new TreeNode(5);    
    TreeNode* n6 = new TreeNode(6);    
    TreeNode* n7 = new TreeNode(7);    
    TreeNode* n8 = new TreeNode(8);    

    n1 -> left = n2;
    n1 -> right = n3;
    n2 -> left = n4;
    n2 -> right = n5;
    n4 -> left = n8;
    n3 -> left = n6;
    n3 -> right = n7;

    /* 前序遍历 */
    preOrderDFS(n1);

    for(auto c : pre_order_set){
        std::cout << c->val << ' ';
    }
    std::cout << std::endl;
    /* 中序遍历 */
    midOrderDFS(n1);
    
    for(auto c : mid_order_set){
        std::cout << c->val << ' ';
    }
    std::cout << std::endl;
    
    /* 后序遍历 */
    postOrderDFS(n1);
    for(auto c : post_order_set){
        std::cout << c-> val << ' ';
    }
}
