//
// Created by swagger on 2021/4/25.
//

#ifndef DATASTRUCT_101_ISSYMMETRIC_H
#define DATASTRUCT_101_ISSYMMETRIC_H

#include "utility.h"



class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        /* 左树使用前序遍历进栈，右边树使用后续遍历进行对比 */
        std::stack<int> s;
        getStack(s, root->left);
        return check(s, root->right);

    }

    void getStack(std::stack<int>& s, TreeNode* node){
        if (!node){
            s.push(-1);
            return;
        }

        s.push(node->val);
        getStack(s, node->left);
        getStack(s, node->right);
    }

    bool check(std::stack<int>& s, TreeNode* node){
        if (!node){
            if (s.top() == -1){
                s.pop();
                return true;
            }
            return false;
        }
        if ( check(s, node->left) && check(s, node->right) ){
            if ( s.top() == node->val ){
                s.pop();
                return true;
            }
        }
        return false;
    }
};

#endif //DATASTRUCT_101_ISSYMMETRIC_H
