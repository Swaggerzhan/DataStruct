//
// Created by swagger on 2021/4/25.
//

#ifndef DATASTRUCT_111_MINDEPTH_H
#define DATASTRUCT_111_MINDEPTH_H

#include "utility.h"

class Solution {
public:


    int minDepth(TreeNode* root){

        if (root == nullptr)
            return 0;

        /* 一棵树为空就不要管了，直接调用另外一颗树 */
        if ( root->left == nullptr )
            return minDepth(root->right) + 1;
        if ( root->right == nullptr )
            return minDepth(root->left) + 1;

        int left_dep = minDepth(root->left);
        int right_dep = minDepth(root->right);

        if (left_dep < right_dep)
            return left_dep + 1;
        return right_dep + 1;

    }
};



#endif //DATASTRUCT_111_MINDEPTH_H
