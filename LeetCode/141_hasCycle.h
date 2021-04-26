//
// Created by swagger on 2021/4/24.
//

#ifndef DATASTRUCT_141_HASCYCLE_H
#define DATASTRUCT_141_HASCYCLE_H

#include "utility.h"


class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (!head)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast){
            fast = fast->next;
            if (fast == slow )
                return true;
            slow = slow->next;
            if (fast){
                fast = fast->next;
                if (fast == slow)
                    return true;
            }else{
                return false;
            }
        }



    }
};

#endif //DATASTRUCT_141_HASCYCLE_H
