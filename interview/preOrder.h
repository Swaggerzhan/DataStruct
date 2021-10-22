//
// Created by Swagger on 2021/10/22.
//

#ifndef DATASTRUCT_PREORDER_H
#define DATASTRUCT_PREORDER_H

#endif //DATASTRUCT_PREORDER_H
#include <stack>
#include <iostream>
#include <vector>
#include "util.h"

using std::stack;
using std::vector;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if ( !root )
            return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while ( !s.empty() ){
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node);
            if ( node->right)
                s.push(node->right);
            if ( node->left )
                s.push(node->left);
        }
        return res;
    }

    vector<int> inOrderIteration(TreeNode* root){
        if ( !root )
            return {};
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while ( !s.empty() || node != nullptr ) {
            while ( node != nullptr) {
                s.push(node);
                node = node->left;
            }
            if ( !s.empty() ){
                TreeNode* tmp = s.top();
                s.pop();
                ret.push_back(tmp->val);
                node = tmp->right;
            }
        }
        return ret;
    }


    vector<int> postOrderIteration(TreeNode* root) {
        if (!root)
            return {};
        stack<TreeNode*> tmp_stack;
        stack<TreeNode*> ret_stack;
        tmp_stack.push(root);

        while ( !tmp_stack.empty() ) {
            TreeNode* node = tmp_stack.top();
            tmp_stack.pop();
            ret_stack.push(node);
            if ( node->left )
                tmp_stack.push(node->left);
            if ( node->right )
                tmp_stack.push(node->right);
        }
        vector<int> ret;
        while ( !ret_stack.empty()) {
            TreeNode* node = ret_stack.top();
            ret_stack.pop();
            ret.push_back(node->val);
        }
        return ret;
    }
};











