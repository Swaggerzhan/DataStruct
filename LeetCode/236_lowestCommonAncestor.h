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



    TreeNode* reWrite(TreeNode* root, TreeNode* p, TreeNode* q){

        if ( !root )
            return nullptr;

        if ( root == p || root == q)
            return root;

        TreeNode* left_scan  = reWrite(root, p, q);
        TreeNode* right_scan = reWrite(root, p, q);

        if ( !left_scan && !right_scan )
            return nullptr;

        if ( left_scan && right_scan )
            return root;

        return left_scan ? left_scan : right_scan;


    }
};

#endif //DATASTRUCT_236_LOWESTCOMMONANCESTOR_H









