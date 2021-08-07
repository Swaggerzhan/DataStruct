//
// Created by Swagger on 2021/8/7.
//

#ifndef DATASTRUCT_DENSEGRAPH_H
#define DATASTRUCT_DENSEGRAPH_H




#include <vector>

using std::vector;


class DenseGraph{
public:

    DenseGraph(int vertex, bool isDirect);

    ~DenseGraph();


    void addEdge(int v, int w);

    bool hasEdge(int v, int w);



private:

    bool isDirect_;
    int vertex_;
    int edge_;

    vector<vector<bool>> graph_;


};


#endif //DATASTRUCT_DENSEGRAPH_H
