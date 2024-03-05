#include<iostream>
#include"TreeNode.h"
class BinarySearchTree
{
private:
    TreeNode* root;
    
public:
    BinarySearchTree(/* args */);
    ~BinarySearchTree();

    TreeNode* search(int num){
        TreeNode* cur = root;
        while(cur != nullptr){
            if((cur -> val) < num){
                cur = cur -> right;
            }else if((cur -> val) > num){
                cur = cur -> left;
            }else{
                return cur;
            }
        }
        return nullptr;
    }

    void insert(int num){
        if(root == nullptr){
            root = new TreeNode(num);
            return;
        }
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur != nullptr){
            if(cur -> val == num){
                return;
            }

            pre = cur;

            if((cur -> val) > num){
                cur = cur -> left;
            }else {
                cur = cur -> right;
            }
        }
        TreeNode* node = new TreeNode(num);

        if((pre -> val) > num){
            node = pre -> left;
        }
        else {
            node = pre -> right;
        }
    }

    void remove(int num){
        if(root == nullptr)
            return;

        TreeNode *cur = root;
        TreeNode *pre = nullptr;

        while(cur != nullptr){
            if(cur -> val == num)
                break;
            pre = cur;
            
            if(cur -> val > num)
                cur = cur -> left;
            else 
                cur = cur ->right;
        }
        if(cur == nullptr)
            return;
        if(cur -> left == nullptr || cur -> right == nullptr){
            TreeNode* child = cur -> left != nullptr ? cur -> left : cur -> right;
            if(cur != root){
                if(pre -> left == cur){
                    pre -> left = child;
                }else {
                    pre -> right = child;
                }
            }else{
                root = child;
            }
            delete cur;
        }else{
            TreeNode* tmp = cur -> right;
            while(tmp -> left != nullptr){
                tmp = tmp -> left;
            }
            int tmp_val = tmp -> val;
            remove(tmp_val);
            cur -> val = tmp_val;
        }
    }
};

