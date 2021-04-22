//
// Created by swagger on 2021/4/9.
//

#ifndef DATASTRUCT_UNIONTEST_H
#define DATASTRUCT_UNIONTEST_H


#include <iostream>
#include <ctime>
#include "Union1.h"
#include "Union2.h"

using std::cout;
using std::endl;

void testUF1(int n){

    srand(time(nullptr));

    Union1 uf1(n);
    time_t startTime = clock();
    for (int i=0; i < n; i++){
        int a = rand() % n;
        int b = rand() % n;
        uf1.unionElements(a, b);
    }

    for (int i=0; i<n; i++){
        int a = rand() % n;
        int b = rand() % n;
        uf1.isConnected(a, b);
    }

    time_t endTime = clock();
    cout << "uf1 used time: " << (double)(endTime-startTime) / CLOCKS_PER_SEC << endl;

}

void testUF2(int n){

    srand(time(nullptr));

    Union2 uf2(n);
    time_t startTime = clock();
    for (int i=0; i < n; i++){
        int a = rand() % n;
        int b = rand() % n;
        uf2.unionElements(a, b);
    }

    for (int i=0; i<n; i++){
        int a = rand() % n;
        int b = rand() % n;
        uf2.isConnected(a, b);
    }

    time_t endTime = clock();
    cout << "uf2 used time: " << (double)(endTime-startTime) / CLOCKS_PER_SEC << endl;

}


#endif //DATASTRUCT_UNIONTEST_H
