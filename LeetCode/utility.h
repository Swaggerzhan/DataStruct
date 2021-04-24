//
// Created by swagger on 2021/4/24.
//

#ifndef DATASTRUCT_UTILITY_H
#define DATASTRUCT_UTILITY_H

#include <iostream>

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

#endif //DATASTRUCT_UTILITY_H
