//
// Created by swagger on 2021/6/8.
//

#ifndef DATASTRUCT_226_INVERTTREE_H
#define DATASTRUCT_226_INVERTTREE_H

#include "utility.h"


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};



#endif //DATASTRUCT_226_INVERTTREE_H
