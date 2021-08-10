//
// Created by Swagger on 2021/8/10.
//

#ifndef DATASTRUCT_COMPONENT_H
#define DATASTRUCT_COMPONENT_H

template<typename Graph>
class Component{
public:

    Component(Graph& graph);
    ~Component();

    void show();

private:

    void dfs(int v);

private:

    Graph& G_;

    bool *isVisited_;

};




#endif //DATASTRUCT_COMPONENT_H
