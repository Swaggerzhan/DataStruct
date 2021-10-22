//
// Created by Swagger on 2021/10/22.
//

#ifndef DATASTRUCT_DETECTCYCLE_OFFER2_022_H
#define DATASTRUCT_DETECTCYCLE_OFFER2_022_H

struct ListNode{
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( !head )
            return nullptr;
        ListNode* slow = head;
        ListNode* faster = head;
        while (faster && faster->next) {
            slow = slow->next;
            faster = faster->next->next;
            if ( slow == faster ) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

#endif //DATASTRUCT_DETECTCYCLE_OFFER2_022_H
