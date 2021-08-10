#include <iostream>
#include "Graph/sparseGraph.h"
#include "Graph/ReadGraph.hpp"
#include "Graph/Component.hpp"
#include "Graph/topo.h"

using std::endl;
using std::cout;
using std::string;

int main(int argc, char** args) {

//    string file = "../Graph/graph.txt";
//
//    SparseGraph graph(7, false);
//    ReadGraph<SparseGraph> read(graph, file);
//
//    //graph.show();
//
//    Component<SparseGraph> component(graph);
//    //component.show();
    Topo g(6);   // 创建图
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.show();


}
