//
// Created by swagger on 2021/4/27.
//

#ifndef DATASTRUCT_92_REVERLINKLIST2_H
#define DATASTRUCT_92_REVERLINKLIST2_H

#include "utility.h"


class Solution {
public:

    /* 前开后闭，不过需要保存left-1节点所在位置 */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr)
            return nullptr;
        if (left == right)
            return head;

        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* left_pre = nullptr;
        ListNode* left_cur = nullptr;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        int cur_index = 1;
        while (cur){
            /* 这个节点需要记住 */
            if ( cur_index == left ){
                left_pre = pre;
                left_cur = cur;
            }
            if (cur_index > right)
                break;
            /* 当left < cur_index <= right时就要开始反转了！ */
            if (cur_index > left && cur_index <= right){
                cur_index ++;
                cur->next = pre;
                pre = cur;
                cur = nxt;
                if (!nxt)
                    break;
                nxt = nxt->next;
                continue;
            }
            cur_index ++;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        /* 循环结束后cur刚刚好指到right后一个元素 */
        left_cur->next = cur;
        left_pre->next = pre;
        return dummyHead->next;

    }
};


#endif //DATASTRUCT_92_REVERLINKLIST2_H
