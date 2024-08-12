#include "Graph.h"
#include <queue>
#include <unordered_map>
#include <iostream>

//TODO, STUDENTS: Implement this func
void Graph::addEdge(unsigned x, unsigned y)
{
    m_adjacencyList[x].push_back(y);
    m_adjacencyList[y].push_back(x);
}



//TODO, STUDENTS: Implement modified BFS algo to return path from start to destination only
//no need to traverse the whole Graph
std::vector<unsigned> Graph::bfs(unsigned start, unsigned destination)
{
    if (start == destination)
    {
        return { start };
    }

    std::vector<bool> visitedGraphs(m_numVertices, false);
    std::vector<int> graphs(m_numVertices, -1);
    std::queue<unsigned> q;

    visitedGraphs[start] = true;
    q.push(start);
    while (!q.empty())
    {
        unsigned currentGraph = q.front();
        q.pop();

        for (unsigned neighborGraph : m_adjacencyList[currentGraph])
        {
            if (!visitedGraphs[neighborGraph])
            {
                visitedGraphs[neighborGraph] = true;
                graphs[neighborGraph] = currentGraph;
                q.push(neighborGraph);

                if (neighborGraph == destination)
                {
                    std::vector<unsigned> resultPath;
                    for (unsigned i = destination; i != -1; i = graphs[i])
                    {
                        resultPath.push_back(i);
                    }
                    std::reverse(resultPath.begin(), resultPath.end());
                    return resultPath;
                }
            }

        }
    }
    return {}; // Return an empty path if no path is found
}
