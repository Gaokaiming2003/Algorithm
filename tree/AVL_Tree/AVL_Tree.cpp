#include<iostream>

using namespace std;

/* 初始化AVL树的节点 */
struct TreeNode{
    int val;
    int height = 0; //保存节点高度
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

class AVL_Tree
{
private:
    TreeNode* root;
public:
    AVL_Tree(TreeNode* root){
        this -> root = root;
    }
    ~AVL_Tree();

    /* 获取节点高度 */
    int getHeight(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        return node -> height;
    }

    /* 更新节点高度 */
    void updateHeight(TreeNode* node){
        node -> height = max(node -> left -> height, node -> right -> height) + 1;
    }

    /* 获取平衡因子 */
    int getBalanceFactor(TreeNode* node){
        return (node -> left -> height) - (node -> right -> height);
    }

    /* 右旋 */
    TreeNode* rightRotate(TreeNode* node){
        auto child = node -> left;
        auto grandchild = child -> right;

        child -> right = node;
        node -> left = grandchild;

        updateHeight(node);
        updateHeight(child);

        return child;
    }

    /* 左旋 */
    TreeNode* leftRotate(TreeNode* node){
        auto child = node -> right;
        auto grandchild = child -> left;

        child -> left = node;
        node -> right = grandchild;

        updateHeight(node);
        updateHeight(child);

        return child;
    }

    /* 旋转 */
    TreeNode* rotate(TreeNode* node){
        int balanceFactor = getBalanceFactor(node);

        if(balanceFactor > 1){
            if(getBalanceFactor(node -> left) >= 0){
                return rightRotate(node);
            }else{
                node -> left = leftRotate(node -> left);
                return rightRotate(node);
            }
        }else if(balanceFactor < -1) {
            if(getBalanceFactor(node -> right) <= 0){
                return leftRotate(node);
            }else{
                node -> right = rightRotate(node -> right);
                return leftRotate(node);
            }
        }
        return node;
    }
};
