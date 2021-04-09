//
// Created by swagger on 2021/4/9.
//

#ifndef DATASTRUCT_UNION1_H
#define DATASTRUCT_UNION1_H

#include <cassert>


/**
 * parent 的index索引表示对应数字
 * parent[index]的值则为指向的头节点
 */
class Union1{


private:
    int *parent;
    int length;

public:


    Union1(int length){
        this->length = length;
        this->parent = new int[length];

        /* 初始化为本身 */
        for (int i=0; i<length; i++)
            parent[i] = i;
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
        parent[rightRoot] = leftRoot;
        /* 经过测试10w级别需要14s */


    }
};

#endif //DATASTRUCT_UNION1_H
