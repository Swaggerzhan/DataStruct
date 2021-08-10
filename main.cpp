#include <iostream>
#include "Graph/sparseGraph.h"
#include "Graph/ReadGraph.hpp"

using std::endl;
using std::cout;
using std::string;

int main(int argc, char** args) {

    string file = "../Graph/graph.txt";

    SparseGraph graph(7, false);
    ReadGraph<SparseGraph> read(graph, file);

    graph.show();


}
