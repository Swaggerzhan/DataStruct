//
// Created by swagger on 2021/4/14.
//

#ifndef DATASTRUCT_102_LEVELORDER_H
#define DATASTRUCT_102_LEVELORDER_H


#include "TreeNode.h"

using namespace std;

class Solution{
    vector<vector<int>> levelOrder(TreeNode* root){
        if (root == nullptr)
            return vector<vector<int>>();

        int top = 1;
        int bottom = 0;
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ){
            TreeNode* tmp = q.front();
            q.pop();

            

        }

    }
};



#endif //DATASTRUCT_102_LEVELORDER_H
