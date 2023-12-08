#ifndef GRAPH_H_
#define GRAPH_H_

#include "Tree.h"

class Graph
{
private:
    struct GraphNode {
        string fnc;
        GraphNode* next;
        GraphNode(string fnc) : fnc(fnc), next(nullptr) {}
    };
    int size;
    string funNames[10];
    GraphNode** adjacencyList;
public:
    Graph(Tree& bt) {
        size = numOfFunctions(bt);
        Stack s = finishedFunctions(bt);
        adjacencyList = new GraphNode * [size];
        for (int i = 0; i < size; ++i) {
            funNames[i] = s.pop()->function;
            adjacencyList[i] = nullptr;
        }
    }
    ~Graph();
    Graph& makeGraph(Tree& bt);
    void dfs();
    void findRecursion();
};
#endif
