#include "Kruskal.h"
#include "../../graph/include/Graph.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

Kruskal::Kruskal(const Graph &graph) : graph(graph)
{
    int n = graph.numberOfVertices();
    rank = new int[n + 1];
    parent = new int[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

Algorithms::Kruskal::~Kruskal()
{
    delete[] rank;
    delete[] parent;
}

int Kruskal::find(int u)
{
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void Kruskal::merge(int x, int y)
{
    x = find(x), y = find(y);
    if (rank[x] > rank[y])
        parent[y] = x;
    else
        parent[x] = y;
    if (rank[x] == rank[y])
        rank[y]++;
}

int Kruskal::minimumSpanningTree(const Graph &graph)
{
    int mst{};
    Kruskal kruskal(graph);
    auto edges = graph.getEdges();
    sort(edges.begin(), edges.end(),
         [](const tuple<int, int, double> &first, const tuple<int, int, double> &second)
         {
             return get<2>(first) < get<2>(second);
         });
    vector<tuple<int, int, double>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = get<0>(*it);
        int v = get<1>(*it);

        int parentU = kruskal.find(u);
        int parentV = kruskal.find(v);
        if (parentU != parentV)
        {
            mst += get<2>(*it);
            kruskal.merge(parentU, parentV);
            cout << u << " - " << v << endl;
        }
    }
    cout << "Weight of MST is " << mst << endl;
    return mst;
}
