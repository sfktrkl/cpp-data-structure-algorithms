#include "DepthFirstSearch.h"
#include "../../graph/include/Graph.h"
#include <iostream>
#include <limits>
#include <stack>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

void DepthFirstSearch::traverse(const Graph &graph, int source)
{
    auto vertices = graph.getVertices();
    vector<bool> visited(vertices.size(), false);
    stack<int> stack;
    stack.push(source);
    visited[source] = true;

    while (!stack.empty())
    {
        auto current = stack.top();
        cout << "Visited " << current << endl;
        stack.pop();

        for (const auto &neighbor : vertices[current])
        {
            if (!visited[neighbor.first] &&
                neighbor.second != numeric_limits<double>::infinity())
            {
                visited[neighbor.first] = true;
                stack.push(neighbor.first);
            }
        }
    }
}
