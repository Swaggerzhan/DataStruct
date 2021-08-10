//
// Created by Swagger on 2021/8/10.
//


#include <fstream>
#include <cassert>
#include <sstream>
#include "ReadGraph.h"
#include "sparseGraph.h"

using std::string;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;

template<typename Graph>
ReadGraph<Graph>::ReadGraph(Graph& graph, string filename)
:   G_(graph),
    filename_(std::move(filename))
{
    ifstream file(filename_);
    string line;
    int vertex, edge;

    assert( file.is_open() );

    assert(getline(file, line));
    stringstream ss(line);

    ss >> vertex >> edge;
    cout << "got vertex: " << vertex << " " << "edge: " << edge << endl;
    assert( vertex == G_.getVertex() );

    for (int i=0; i<edge; i++){
        getline(file, line);
        stringstream ss(line);
        int a, b;
        ss >> a >> b;
        G_.addEdge(a, b);
    }

}

template<typename Graph>
ReadGraph<Graph>::~ReadGraph() {

}


