//
// Created by swagger on 2021/4/24.
//

#ifndef DATASTRUCT_160_GETINTERSECTIONNODE_H
#define DATASTRUCT_160_GETINTERSECTIONNODE_H

#include <set>
#include "utility.h"


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (headA == nullptr && headB == nullptr)
            return nullptr;

        ListNode* left = headA;
        ListNode* right = headB;

        while (left != right ){

            if ( left ){
                left = left->next;
            }else{
                left = headB;
            }
            if (right){
                right = right->next;
            }else {
                right = headA;
            }
        }
        return left;
    }



};



#endif //DATASTRUCT_160_GETINTERSECTIONNODE_H
