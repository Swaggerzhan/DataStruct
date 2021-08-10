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
    int getEdge();
    int getVertex();

    /* 打印SparseGraph图 */
    void show();

    class Iter{
    public:
        /* 一个图的v顶点的迭代器 */
        Iter(SparseGraph& g, int v);
        ~Iter();

        int begin();
        bool end();
        int next();


    private:
        SparseGraph& G_;
        int index_;             // 当前遍历index
        int vertex_;            // 顶点
    };


private:

    int vertex_;
    bool isDirect_;
    int edge_;

    vector<vector<int> > graph_;


};








#endif //DATASTRUCT_SPARSEGRAPH_H
