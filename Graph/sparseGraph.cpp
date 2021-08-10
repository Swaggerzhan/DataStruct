//
// Created by Swagger on 2021/8/7.
//
#include "sparseGraph.h"
#include <cassert>
#include <iostream>

using std::endl;
using std::cout;

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


int SparseGraph::getEdge() { return edge_; }

int SparseGraph::getVertex() { return vertex_; }

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


void SparseGraph::show() {

    for (int i=0; i<vertex_; i++){
        cout << "vertex: " << i << ": \t";
        for (int j=0; j<graph_[i].size(); j++){
            cout << graph_[i][j] << "\t";
        }
        cout << endl;
    }

}

/////////////////////////////////////////////////////////
/// 迭代器


SparseGraph::Iter::Iter(SparseGraph &g, int v)
:   G_(g),
    index_(0),
    vertex_(v)
{

}


int SparseGraph::Iter::begin() {
    index_ = 0;
    if ( G_.graph_[vertex_].empty() ){
        return -1; // 没有数据
    }
    return G_.graph_[vertex_][0];
}

int SparseGraph::Iter::next() {
    index_ ++;
    if ( index_ < G_.graph_[vertex_].size() ){
        return G_.graph_[vertex_][index_];
    }
    return -1;
}


bool SparseGraph::Iter::end() {
    return index_ >= G_.graph_[vertex_].size();
}

SparseGraph::Iter::~Iter() {

}


