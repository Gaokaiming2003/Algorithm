#ifndef TREENODE_H
#define TREENODE_H

#include<iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

#endif