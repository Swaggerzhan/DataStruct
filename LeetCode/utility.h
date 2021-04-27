//
// Created by swagger on 2021/4/24.
//

#ifndef DATASTRUCT_UTILITY_H
#define DATASTRUCT_UTILITY_H

#include <iostream>
#include <stack>
#include <string>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* getList(int arr[], int len){

    auto* dummyHead = new ListNode(1);
    ListNode* tmp = dummyHead;
    for (int i=0; i<len; i++){
        tmp->next = new ListNode(arr[i]);
        tmp = tmp->next;
    }
    ListNode* retNode = dummyHead->next;
    delete dummyHead;
    return retNode;

}

void printList(ListNode* node){
    ListNode* tmp = node;
    while (tmp){
        std::cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    std::cout << "null" << std::endl;
}


TreeNode* test_case_101(){
    auto left_3 = new TreeNode(3);
    auto left_4 = new TreeNode(4);
    auto right_4 = new TreeNode(4);
    auto right_3 = new TreeNode(3);
    auto left_2 = new TreeNode(2);
    auto right_2 = new TreeNode(2);
    auto root = new TreeNode(1);
    root->left = left_2;
    root->right = right_2;
    left_2->left = left_3;
    left_2->right = left_4;
    right_2->left = right_4;
    right_2->right = right_3;
    return root;
}



#endif //DATASTRUCT_UTILITY_H
