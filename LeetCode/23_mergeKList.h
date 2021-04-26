#include "utility.h"


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    	int k = lists.size();
    	vector<bool> isEmpty = vector<bool>(k, true);
    	vector<int> head = vector<ListNode*>(k + 1, nullptr);

    	for (int i=0; i<k; i++){
    		head[i] = lists[i]; /* tmp节点 */
    	}
    	head[k] = new ListNode(99999);


    	ListNode* dummyHead = new ListNode(-1);
    	ListNode* tmp = dummyHead;
    	

    	while (k > 0){

    		int min_head_index = head.nums();
    		for (int i=0; i<head.nums()-1; i++){
    			/* 这个节点已经为空了 */
    			if (isEmpty[i] == false)
    				continue;
    			/* 找出最小值的节点的索引 */
    			if (head[i]->val < head[min_head_index]->val)
    				min_head_index = i;
    		}
			
			tmp->next = head[min_head_index];
			tmp = tmp->next;
			if (head[min_head_index]->next == nullptr){
				isEmpty[min_head_index] = true;
				k --;
			}
			else
				head[min_head_index] = head[min_head_index]->next;

    	}
    	ListNode* retNode = dummyHead->next;
    	delete dummyHead;
    	return retNode;

    }
};