//
// Created by swagger on 2021/4/9.
//

#ifndef DATASTRUCT_UNION2_H
#define DATASTRUCT_UNION2_H


#include <cassert>


/**
 * parent 的index索引表示对应数字
 * parent[index]的值则为指向的头节点
 * sz[index]表示所指向元素的并集合的大小
 */

class Union2{


private:
    int *parent;
    int length;
    int *sz; /* 这个sz表示其中每个集合的元素个数 */

public:


    Union2(int length){
        this->length = length;
        this->parent = new int[length];
        this->sz = new int[length];

        for (int i=0; i<length; i++) {
            /* 初始化为本身 */
            parent[i] = i;
            /* 开始时候每个元素都只有本身一个 */
            sz[i] = 1;
        }

    }

    /**
     * 找到对应数字的头节点
     * @return
     */
    int find( int target ){
        /* 当index和parent[index]相同时就表示是头节点了  */
        while ( target != parent[target] ){
            target = parent[target];
        }
        /* 这里return target和return parent[target]是没有区别的，因为都已经指向了相同的方向了 */
        return target;
    }


    /**
     *  检测left和right是否是并到一起的
     * @param left
     * @param right
     * @return
     */
    bool isConnected(int left, int right){
        return find(left) == find(right);
    }


    /**
     * 将给定的左值和右值并到一起
     * @param left 左边的元素
     * @param right 右边的元素
     * @return
     */
    void unionElements(int left, int right){
        assert( left >= 0 && left < length );
        assert( right >=0 && right < length );

        int leftRoot = find(left);
        int rightRoot = find(right);

        /* 这种情况下，左右元素已经并到一起了，直接返回 */
        if (leftRoot == rightRoot)
            return;

        /* 采用没有进行优化的方法，随意的将一片并到另外的一边，没有考虑高度问题 */
        // parent[rightRoot] = leftRoot;
        /* 经过测试10w级别需要14s */

        /* 采用元素少的指向元素多的优化方案 */
        if (sz[rightRoot] < sz[leftRoot]){
            parent[rightRoot] = leftRoot;
            /* 将左元素中所有元素个数加到一起 */
            sz[leftRoot] += sz[rightRoot];
        }else if ( sz[leftRoot] < sz[rightRoot]){
            parent[leftRoot] = rightRoot;
            /* 同上 */
            sz[rightRoot] += sz[leftRoot];
        }



    }
};

#endif //DATASTRUCT_UNION2_H
