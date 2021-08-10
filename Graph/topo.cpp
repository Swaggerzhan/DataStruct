//
// Created by Swagger on 2021/8/10.
//

#include "topo.h"
#include <iostream>
#include <cassert>

using std::vector;
using std::cout;
using std::endl;


Topo::Topo(int vertex)
:   vertex_(vertex),
    graph_(),
    edge_(0),
    queue_()
{
    inDegree_ = new int[vertex_];
    for (int i=0; i<vertex_; i++){
        graph_.push_back(vector<int>());
        inDegree_[i] = 0;
    }

}

Topo::~Topo() {}

bool Topo::hasEdge(int v, int w) {
    assert( v >= 0 && v < vertex_ );
    assert( w >= 0 && w < vertex_ );

    for (int i=0; i<graph_[v].size(); i++){
        if ( graph_[v][i] == w)
            return true;
    }
    return false;

}


void Topo::addEdge(int v, int w) {
    assert( v >= 0 && v < vertex_ );
    assert( w >= 0 && w < vertex_ );

    if (hasEdge(v, w)){
        return;
    }
    edge_ ++;
    graph_[v].push_back(w);
    inDegree_[w] ++; // w入度 + 1

}


bool Topo::sort() {
    // 找出开始时入度为0的
    for (int i=0; i<vertex_; i++){
        if (inDegree_[i] == 0)
            queue_.push(i);
    }

    while ( !queue_.empty() ){
        int v = queue_.front();
        queue_.pop();
        sort_.push_back(v);

        /* 所有v节点指向的节点入度-1 */
        for (int i=0; i<graph_[v].size(); i++){
            inDegree_[graph_[v][i]] --;
            if ( inDegree_[graph_[v][i]] == 0 )
                queue_.push(graph_[v][i]); // 新的入度为0的节点
        }

    }
    // 节点数量对，图中有回路
    if ( sort_.size() < vertex_ )
        return false;
    return true;


}


void Topo::show(){
    if ( sort() ){
        for (int tmp: sort_ ){
            cout << tmp << " ";
        }
        cout << endl;
    }else {
        cout << "sort failed!" << endl;
    }
}



