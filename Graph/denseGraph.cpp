//
// Created by Swagger on 2021/8/7.
//

#include "denseGraph.h"
#include <iostream>
#include <cassert>

using std::endl;
using std::cout;

DenseGraph::DenseGraph(int vertex, bool isDirect)
:   isDirect_(isDirect),
    vertex_(vertex),
    edge_(0)
{
    for (int i=0; i<vertex_; i++){
        graph_.push_back(vector<bool>(vertex_, false));
    }
    //cout << graph_.size() << endl;

}


DenseGraph::~DenseGraph() {}

bool DenseGraph::hasEdge(int v, int w) {
    assert( v >= 0 && v < vertex_ );
    assert( w >= 0 && w < vertex_ );
    return graph_[v][w];
}


void DenseGraph::addEdge(int v, int w) {

    assert( v >= 0 && v < vertex_ );
    assert( w >= 0 && w < vertex_ );

    if (hasEdge(v, w) )
        return;

    graph_[v][w] = true;
    if ( !isDirect_ )
        graph_[w][v] = true;

    edge_ ++;
}



