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

        )

