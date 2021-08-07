//
// Created by swagger on 2021/4/25.
//

#ifndef DATASTRUCT_101_ISSYMMETRIC_H
#define DATASTRUCT_101_ISSYMMETRIC_H

#include "utility.h"



class Solution {
public:

    bool dfs(TreeNode* left, TreeNode* right){

        if ( !left && !right)
            return true;

        if ( !(left && right) )
            return false;

        if ( left->val != right->val )
            return false;

        return dfs(left->left, right->right) &&
            dfs(left->right, right->left);




    }


    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return dfs(root->left, root->right);
    }
};

#endif //DATASTRUCT_101_ISSYMMETRIC_H
