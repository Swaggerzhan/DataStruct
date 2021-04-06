//
// Created by swagger on 2021/4/6.
//

#ifndef DATASTRUCT_TREE_TEST_H
#define DATASTRUCT_TREE_TEST_H


#include "BinaryTree.h"
#include <ctime>


void tree_test(){
    srand(time(nullptr));
    int arr[] = {10, 22, 1, 22, 31, 51, 76, 99, 23, 65, 78, 11, 9};
    int length = sizeof(arr) / sizeof(int);
    int value[length];
    for (int i=0; i<length; i++)
        value[i] = rand() % 100;

    BinaryTree<int, int> tree;

    for (int i=0; i<length; i++){
        tree.insert(arr[i], value[i]);
    }


    tree.inOrder();

    bool is_22_exist = tree.contain(22);
    if (is_22_exist){
        printf("yes\n");
        int* value = tree.search(22);
        printf("22 values is %d\n", *value);
    }


}


#endif //DATASTRUCT_TREE_TEST_H
