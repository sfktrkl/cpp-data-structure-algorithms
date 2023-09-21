#include "Prim.h"
#include "../../graph/include/Graph.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

int Prim::minimumSpanningTree(const Graph &graph)
{
    int mst{};
    auto vertices = graph.getVertices();
    vector<bool> visited(vertices.size(), false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> heap;
    heap.push({0, 0});

    while (!heap.empty())
    {
        auto p = heap.top();
        heap.pop();

        double weight = p.first;
        int u = p.second;

        if (visited[u])
            continue;

        mst += weight;
        visited[u] = true;

        for (auto v : vertices[u])
        {
            if (!visited[v.first])
                heap.push({v.second, v.first});
        }
    }

    cout << "Weight of MST is " << mst << endl;
    return mst;
}
