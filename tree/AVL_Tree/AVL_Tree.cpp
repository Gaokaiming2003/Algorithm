#include<vector>
#include<iostream>

using namespace std;

/* 初始化AVL树的节点 */
struct TreeNode{
    int val{};
    int height = 0; //保存节点高度
    TreeNode* left{};
    TreeNode* right{};
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

class AVL_Tree
{
private:
    TreeNode* root;
    TreeNode* searchHelper(TreeNode* node, int num){

        if(node == nullptr)
            return nullptr;
        if(node -> val > num){
            return searchHelper(node -> left, num);
        }else if(node -> val < num){
            return searchHelper(node -> right, num);
        }else 
            return node;
    }

    /* 递归插入节点（辅助方法） */
TreeNode *insertHelper(TreeNode *node, int val) {
    if (node == nullptr)
        return new TreeNode(val);
    /* 1. 查找插入位置并插入节点 */
    if (val < node->val)
        node->left = insertHelper(node->left, val);
    else if (val > node->val)
        node->right = insertHelper(node->right, val);
    else
        return node;    // 重复节点不插入，直接返回
    updateHeight(node); // 更新节点高度
    /* 2. 执行旋转操作，使该子树重新恢复平衡 */
    node = rotate(node);
    // 返回子树的根节点
    return node;
}
public:
    AVL_Tree(TreeNode* root){
        this -> root = root;
    }
    ~AVL_Tree();

    TreeNode* getRoot(){
        return root;
    }
    /* 获取节点高度 */
    int getHeight(TreeNode* node){
        if(node == nullptr){
            return -1;
        }
        return node -> height;
    }

    /* 更新节点高度 */
    void updateHeight(TreeNode* node){
        node -> height = max(getHeight(node -> left), getHeight(node -> right)) + 1;
    }

    /* 获取平衡因子 */
    int getBalanceFactor(TreeNode* node){
        return getHeight(node -> left) - getHeight(node -> right);
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

/* 插入节点 */
    void insert(int val) {
        root = insertHelper(root, val);
    }
    void remove(int val){
        root = removeHelper(root, val);
    }

    /* 递归删除(辅助) */
    TreeNode* removeHelper(TreeNode* node, int val){
        if(node == nullptr)
            return nullptr;

        /* 查找要删除的节点 */
        if(node -> val < val){
            node -> right= removeHelper(node -> right, val);
        }else if(node -> val > val){
            node -> left= removeHelper(node -> left, val);
        }else {
            /* 找到了 */
            if(node -> left == nullptr || node -> right == nullptr){
                TreeNode* child = node -> left != nullptr ? node -> left : node -> right;
                /* 要删除节点为叶节点 */
                if(child == nullptr){
                    delete node;
                    return nullptr;
                }else{
                    /* 要删除节点度数为1 */
                    delete node;
                    node = child;
                }
            }else{
                /* 要删除的节点度数为2 */
                    TreeNode* tmp = node -> right;
                    /* 找到右子树中值最小的节点将其删除替换为node */
                    while(tmp -> left != nullptr){
                        tmp = tmp -> left;
                    }
                    int tmp_val = tmp -> val;
                    node -> right = removeHelper(node -> right, tmp_val);
                    node -> val = tmp_val;
            }
        }

        updateHeight(node);

        node = rotate(node);

        return node;
    }

    TreeNode* search(int num){
       return searchHelper(root, num);
    }
    
    void preOrderDFS(TreeNode* root, vector<int> &res){ 
    /* 前序遍历 */
    /* root - left - right */

    if(root == nullptr) 
        return;
    res.push_back(root -> val);
    preOrderDFS(root -> left, res);
    preOrderDFS(root -> right, res);

}
};

int main(){
    AVL_Tree* tree = new AVL_Tree(new TreeNode(3));
    tree -> insert(9);
    tree -> insert(10);
    tree -> insert(8);
    tree -> insert(6);
    tree -> insert(2);

    auto root = tree -> getRoot();
    vector<int> res;
    tree -> preOrderDFS(root, res);
    for(int c : res){
        cout << c << ' ';
    }

    tree -> remove(3);
    res.clear();

    cout << endl;
    root = tree -> getRoot();
    tree -> preOrderDFS(root, res);
    for(int c : res){
        cout << c << ' ';
    }
}
