//
// Created by swagger on 2021/6/8.
//

#ifndef DATASTRUCT_236_LOWESTCOMMONANCESTOR_H
#define DATASTRUCT_236_LOWESTCOMMONANCESTOR_H
#include "utility.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left && !right)
            return nullptr;
        if (left && right)
            return root;
        return left ? left : right;
    }
};

#endif //DATASTRUCT_236_LOWESTCOMMONANCESTOR_H
