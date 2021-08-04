cmake_minimum_required(VERSION 3.5)
project(DataStruct)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE debug)


add_executable(DataStruct main.cpp
        Tree/BinaryTree.h Tree/Tree_test.h
        Sort/mergeSort.h Sort/SortTestHelper.h
        Union/Union1.h Union/UnionTest.h Union/Union2.h
        Union/Union3.h
        LeetCode/utility.h
        LeetCode/21_mergeLinkList.h
        LeetCode/160_getIntersectionNode.h
        LeetCode/141_hasCycle.h
        LeetCode/111_minDepth.h LeetCode/101_isSymmetric.h
        LeetCode/92_reverLinkList2.h
        LeetCode/415_addStrings.h
        LeetCode/179_largetNumber.h
         LeetCode/179_largetNumber.h
        acm/shun.h
        LeetCode/47_findCombination.h
        LeetCode/53_maxSubArray.h

        acm/permu.h acm/isbn.h Sort/quickSort.h Sort/sortHelper.h LeetCode/912_sort.h LeetCode/1_addTwo.h LeetCode/3_lengthOfLongestSubstring.h LeetCode/2_addTwoNumbers.h LeetCode/226_invertTree.h LeetCode/236_lowestCommonAncestor.h LeetCode/88_merge.h LeetCode/232_MyQueue.h Offer/22_getKthFromEnd.h LeetCode/20_isValid.h Sort/heapSort.h)

