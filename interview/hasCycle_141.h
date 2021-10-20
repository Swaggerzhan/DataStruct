//
// Created by Swagger on 2021/10/20.
//

#ifndef DATASTRUCT_HASCYCLE_141_H
#define DATASTRUCT_HASCYCLE_141_H
#include "util.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* pre = head;
        ListNode* cur = head;
        while( cur->next != nullptr ){
            if ( cur == pre ) {
                return true;
            }
            pre = pre->next;
            nxt = nxt->next;
        }
        return false;
    }
};

#endif //DATASTRUCT_HASCYCLE_141_H
