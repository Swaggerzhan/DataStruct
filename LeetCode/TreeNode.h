//
// Created by swagger on 2021/4/14.
//

#ifndef DATASTRUCT_TREENODE_H
#define DATASTRUCT_TREENODE_H


#include <vector>
#include <queue>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#endif //DATASTRUCT_TREENODE_H
