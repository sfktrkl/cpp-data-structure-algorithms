#include "BellmanFord.h"
#include "../../graph/include/Graph.h"
#include <iostream>
#include <limits>
#include <queue>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

void BellmanFord::shortestPath(const Graph &graph, int source)
{
    auto vertices = graph.getVertices();
    auto edges = graph.getEdges();

    vector<double> distances(vertices.size(), numeric_limits<double>::infinity());
    distances[source] = 0;

    for (int i = 0; i < vertices.size() - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            auto u = get<0>(edge);
            auto v = get<1>(edge);
            auto weight = get<2>(edge);
            if (distances[u] != numeric_limits<double>::infinity() &&
                distances[u] + weight < distances[v])
                distances[v] = distances[u] + weight;
        }
    }

    for (const auto &edge : edges)
    {
        auto u = get<0>(edge);
        auto v = get<1>(edge);
        auto weight = get<2>(edge);
        if (distances[u] != numeric_limits<double>::infinity() &&
            distances[u] + weight < distances[v])
        {
            cout << "Graph contains negative weight cycle" << endl;
            return;
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
