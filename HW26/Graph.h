#pragma once
#include <vector>
#include <list>
#include <iostream>

class Graph {
public:
    Graph(unsigned numVertices) : m_numVertices(numVertices), m_adjacencyList(numVertices) {}
        //TODO, STUDENTS: Init internal structure (adjacency list or adjacency matrix) with numVertices size

    
    //TODO, STUDENTS: Implement this func
    void addEdge(unsigned x, unsigned y);

    //TODO, STUDNETS: Implement modified BFS algo to return path from start to destination only
    //no need to traverse the whole Graph
    std::vector<unsigned> bfs(unsigned start, unsigned destination);

private:
    unsigned m_numVertices;
    std::vector < std::list<unsigned>> m_adjacencyList;
};

