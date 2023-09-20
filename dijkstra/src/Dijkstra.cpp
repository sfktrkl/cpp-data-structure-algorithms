#include "Dijkstra.h"
#include "../../graph/include/Graph.h"
#include <iostream>
#include <limits>
#include <queue>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

void Dijkstra::shortestPath(const Graph &graph, int source)
{
    auto vertices = graph.getVertices();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<double> distances(vertices.size(), numeric_limits<double>::infinity());
    heap.push({0, source});
    distances[source] = 0;

    while (!heap.empty())
    {
        int u = heap.top().second;
        heap.pop();

        map<int, double>::iterator it;
        for (it = vertices[u].begin(); it != vertices[u].end(); ++it)
        {
            int v = it->first;
            double weight = it->second;

            if (distances[v] > distances[u] + weight)
            {
                distances[v] = distances[u] + weight;
                heap.push({distances[v], v});
            }
        }
    }

    for (int i = 0; i < vertices.size(); ++i)
    {
        auto distance = distances[i];
        if (distances[i] == numeric_limits<double>::infinity())
            cout << i << "\tINF" << endl;
        else
            cout << i << "\t" << distance << endl;
    }
}
