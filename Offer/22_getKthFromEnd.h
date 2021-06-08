//
// Created by swagger on 2021/6/8.
//

#ifndef DATASTRUCT_22_GETKTHFROMEND_H
#define DATASTRUCT_22_GETKTHFROMEND_H

#include "../LeetCode/utility.h"

class Solution {
public:

    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode* pre = head;
        for (int i=0; i<k; i++){
            if (!pre)
                return nullptr;
            pre = pre->next;
        }
        ListNode* last = head;
        while (pre){
            pre = pre->next;
            last = last->next;
        }
        return last;
    }
};

#endif //DATASTRUCT_22_GETKTHFROMEND_H
