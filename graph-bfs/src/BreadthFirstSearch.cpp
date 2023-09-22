#include "BreadthFirstSearch.h"
#include "../../graph/include/Graph.h"
#include <iostream>
#include <limits>
#include <queue>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

void BreadthFirstSearch::traverse(const Graph &graph, int source)
{
    auto vertices = graph.getVertices();
    vector<bool> visited(vertices.size(), false);
    queue<int> queue;
    queue.push(source);
    visited[source] = true;

    while (!queue.empty())
    {
        auto current = queue.front();
        cout << "Visited " << current << endl;
        queue.pop();

        for (const auto &neighbor : vertices[current])
        {
            if (!visited[neighbor.first] &&
                neighbor.second != numeric_limits<double>::infinity())
            {
                visited[neighbor.first] = true;
                queue.push(neighbor.first);
            }
        }
    }
}
