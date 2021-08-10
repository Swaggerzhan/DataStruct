#include "Component.h"
#include <iostream>
#include "sparseGraph.h"

using std::endl;
using std::cout;

template<typename Graph>
Component<Graph>::Component(Graph &graph)
:   G_(graph),
    isVisited_(new bool[G_.getVertex()])
{
    // 初始化
    for (int i=0; i<G_.getVertex(); i++){
        isVisited_[i] = false;
    }

    // 深度优先遍历
    // 如果一个节点没有遍历过，那我们就优先遍历它，一直往深度去遍历即可
    for (int i=0; i<G_.getVertex(); i++){
        if ( !isVisited_[i] )
            dfs(i);
    }

}


template<typename Graph>
void Component<Graph>::dfs(int v){
    isVisited_[v] = true;

    cout << v << " ";

    typename Graph::Iter iter(G_, v);
    for (int w=iter.begin(); !iter.end(); w = iter.next()){
        if ( !isVisited_[w] )
            dfs(w);
    }

}


template<typename Graph>
void Component<Graph>::show() {
    cout << "-----------" << endl;
    for (int i=0; i<G_.getVertex(); i++){
        typename Graph::Iter iter(G_, i);
        cout << "vertex: " << i << ": ";
        for (int w=iter.begin(); !iter.end(); w=iter.next()){
            cout << w << "\t";
        }
        cout << endl;
    }

}

template<typename Graph>
Component<Graph>::~Component() {
    delete[] isVisited_;
}