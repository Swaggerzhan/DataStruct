//
// Created by Swagger on 2021/8/10.
//

#ifndef DATASTRUCT_TOPO_H
#define DATASTRUCT_TOPO_H

#include <queue>
#include <vector>

// 拓扑排序

class Topo{
public:

    Topo(int vertex);
    ~Topo();

    /* 有向无环图 */
    void addEdge(int v, int w);

    bool hasEdge(int v, int w);

    bool sort();

    void show();

private:

    int vertex_;
    int edge_;
    std::vector<std::vector<int> > graph_;
    std::queue<int> queue_;     // 维护入度为0的角
    int *inDegree_;             // 入度
    std::vector<int> sort_;     // 排序顺序

};

#endif //DATASTRUCT_TOPO_H
