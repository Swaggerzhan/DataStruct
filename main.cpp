#include "LeetCode/92_reverLinkList2.h"


int main(int argc, char** args) {


    int arr[] = {1, 2, 3, 4, 5};
    auto head = getList(arr, 5);
    Solution s;
    printList(head);
    head = s.reverseList(head);
    printList(head);

}
