//
// Created by Swagger on 2021/8/7.
//

#ifndef DATASTRUCT_SPARSEGRAPH_H
#define DATASTRUCT_SPARSEGRAPH_H


#include <vector>

using std::vector;

class SparseGraph{
public:

    SparseGraph(int vertex_, bool isDirect);

    ~SparseGraph();

    bool hasEdge(int v, int w);

    void addEdge(int v, int w);

private:

    int vertex_;
    bool isDirect_;
    int edge_;

    vector<vector<int>> graph_;


};








#endif //DATASTRUCT_SPARSEGRAPH_H
