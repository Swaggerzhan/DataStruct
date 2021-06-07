//
// Created by swagger on 2021/6/7.
//

#ifndef DATASTRUCT_2_ADDTWONUMBERS_H
#define DATASTRUCT_2_ADDTWONUMBERS_H

#include "utility.h"


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* left = l1;
        ListNode* right = l2;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        bool flag = false;
        int tmp;
        while ( left && right ){
            tmp = left->val + right->val + flag;
            flag = tmp >= 10;
            tmp %= 10;
            cur->next = new ListNode(tmp);
            left = left->next;
            right = right->next;
        }
        if ( !left && !right ){
            if (flag)
                cur->next = new ListNode(1);
            ListNode* retNode = dummyHead->next;
            delete dummyHead;
            return retNode;
        }else if ( left ){
            
        }




    }
};


#endif //DATASTRUCT_2_ADDTWONUMBERS_H
