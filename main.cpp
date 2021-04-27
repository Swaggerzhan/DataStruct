#include "Tree/Tree_test.h"
#include "Sort/SortTestHelper.h"
#include "LeetCode/92_reverLinkList2.h"

int main() {

    Solution s;

    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = getList(arr, 5);
    printList(head);
    head = s.reverseBetween(head, 4, 5);
    printList(head);

}
