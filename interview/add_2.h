//
// Created by Swagger on 2021/10/19.
//

#ifndef DATASTRUCT_ADD_2_H
#define DATASTRUCT_ADD_2_H

#endif //DATASTRUCT_ADD_2_H
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* left = l1;
        ListNode* right = l2;
        while ( left->next != nullptr && right->next != nullptr) {
            left->val = left->val + right->val + flag;
            flag = left->val / 10;
            left->val = left->val % 10;
            left = left->next;
            right = right->next;
        }
        if ( left->next == nullptr ){
            left->val = left->val + right->val + flag;
            flag = left->val / 10;
            left->val = left->val % 10;
            left->next = right->next;
            left = left->next;
        }
        while(left->next && flag){
            left->val += flag;
            flag = left->val / 10;
            left->val = left->val % 10;
            left = left->next;
        }
        if (flag){

        }

        return l1;
    }
};
