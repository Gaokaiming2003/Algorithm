#include"TreeNode.h"
#include<vector>
#include<queue>
using namespace std;
vector<int> levelOrder(TreeNode* root){
   queue<TreeNode* > queue;
   vector<int> vector_val;
   queue.push(root);

   while (!queue.empty())
   {
        TreeNode* node = queue.front();
        vector_val.push_back(node -> val);
        queue.pop();
        if(node -> left != nullptr){
            queue.push(node -> left);
        }
        if(node -> right !=nullptr){
            queue.push(node -> right);
        }
   }
   return vector_val;   
}

int main(){
    /* 初始化二叉树 */
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    /* 构建节点之间的引用（关系） */
    n1 -> left = n2;
    n1 -> right = n3;
    n2 -> left = n4;
    n2 -> right = n5;

    /* 插入节点P */
    TreeNode* P = new TreeNode(6);
    // 在n1和n2之间插入
    n1 -> left = P;
    P -> left = n2;

    auto tmp = levelOrder(n1);
    for(auto c : tmp){
        std::cout << c << " ";
    }
    /* 删除节点P */
    n1 -> left = n2;
}