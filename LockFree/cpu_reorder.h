//
// Created by Swagger on 2021/10/27.
//

#ifndef DATASTRUCT_CPU_REORDER_H
#define DATASTRUCT_CPU_REORDER_H

#include <bits/stdc++.h>
using namespace std;

inline void nocpufence(volatile int& x, volatile int& y, volatile int& r) {
    x = 1;
    asm volatile("" ::: "memory");
    r = y;
}

inline void mfence(volatile int& x, volatile int& y, volatile int& r) {
    x = 1;
    asm volatile("mfence" ::: "memory");
    r = y;
}

inline void lockadd(volatile int& x, volatile int& y, volatile int& r) {
    x = 1;
    asm volatile("lock; addl $0,0(%%rsp)" ::: "memory", "cc");
    r = y;
}

inline void xchg(volatile int& x, volatile int& y, volatile int& r) {
    int tmp = 1;
    asm volatile("xchgl %0, %1" : "+r"(tmp), "+m"(x)::"memory", "cc"); // swap(x, tmp)
    r = y;
}

volatile int g_cnt = 0;
void threadfun(volatile int& loop_cnt, volatile int& x, volatile int& y, volatile int& r) {
    while(true) {
        while(g_cnt == loop_cnt) ;

        asm volatile("" ::: "memory");

        nocpufence(x, y, r);
        //mfence(x, y, r);

        asm volatile("" ::: "memory");
        loop_cnt++;
    }
}

int test() {
    alignas(64) volatile int cnt1 = 0;
    alignas(64) volatile int cnt2 = 0;
    alignas(64) volatile int x = 0;
    alignas(64) volatile int y = 0;
    alignas(64) volatile int r1 = 0;
    alignas(64) volatile int r2 = 0;
    thread thr1(threadfun, ref(cnt1), ref(x), ref(y), ref(r1));
    thread thr2(threadfun, ref(cnt2), ref(y), ref(x), ref(r2));

    int detected = 0;
    while(true) {
        x = y = 0;
        asm volatile("" ::: "memory");
        g_cnt++;
        while(cnt1 != g_cnt || cnt2 != g_cnt)
            ;

        asm volatile("" ::: "memory");
        if(r1 == 0 && r2 == 0) {
            detected++;
            cout << "bad, g_cnt: " << g_cnt << " detected: " << detected << endl;
        }
    }
    return 0;
}


#endif //DATASTRUCT_CPU_REORDER_H
