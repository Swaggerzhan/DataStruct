//
// Created by Swagger on 2021/8/7.
//
#include "sparseGraph.h"
#include <cassert>

SparseGraph::SparseGraph(int vertex_, bool isDirect)
:   vertex_(vertex_),
    isDirect_(isDirect),
    edge_(0)
{
    for (int i=0; i<vertex_; i++){
        graph_.push_back(vector<int>());
    }
}


SparseGraph::~SparseGraph() {

}


bool SparseGraph::hasEdge(int v, int w) {

    assert( v >= 0 && v < vertex_ );
    assert( w >= 0 && w < vertex_ );

    for (int i : graph_[v]){
        if ( i == w )
            return true;
    }
    return false;

}


void SparseGraph::addEdge(int v, int w) {

    assert( v >= 0 && v < vertex_ );
    assert( w >= 0 && w < vertex_ );

    if ( hasEdge(v, w) )
        return;

    graph_[v].push_back(w);
    if ( v != w && !isDirect_ ){
        graph_[w].push_back(v);
    }

}

