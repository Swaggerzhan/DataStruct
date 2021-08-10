//
// Created by Swagger on 2021/8/10.
//

#ifndef DATASTRUCT_READGRAPH_H
#define DATASTRUCT_READGRAPH_H

#include <iostream>

template<typename Graph>
class ReadGraph{
public:

    ReadGraph(Graph& graph, std::string filename);
    ~ReadGraph();


private:

    Graph& G_;
    std::string filename_;
};;







#endif //DATASTRUCT_READGRAPH_H
