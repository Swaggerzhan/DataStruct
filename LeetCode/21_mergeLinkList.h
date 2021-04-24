//
// Created by swagger on 2021/4/24.
//

#ifndef DATASTRUCT_21_MERGELINKLIST_H
#define DATASTRUCT_21_MERGELINKLIST_H

#include "utility.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        auto* head = new ListNode(1);
        ListNode* tmp = head;
        ListNode* left = l1;
        ListNode* right = l2;
        while (left && right){
            if (left->val <= right->val){
                tmp->next = left;
                tmp = tmp->next;
                left = left->next;
            }else if (right->val < left->val){
                tmp->next = right;
                tmp = tmp->next;
                right = right->next;
            }
        }
        if (right){
            tmp->next = right;
        }else{
            tmp->next = left;
        }
        ListNode *retNode = head->next;
        delete head;
        return retNode;
    }
};

#endif //DATASTRUCT_21_MERGELINKLIST_H
