#include "AdjacencyList.h"
#include <iostream>
#include <limits>

using namespace DataStructures;
using namespace std;

AdjacencyList::AdjacencyList(int vertices, bool directed)
    : Graph(vertices, directed), adjacencyList(vertices)
{
}

void AdjacencyList::addEdge(int source, int destination, double weight)
{
    if (source >= 0 && source < vertices && destination >= 0 && destination < vertices)
    {
        adjacencyList[source][destination] = weight;
        if (!directed)
            adjacencyList[destination][source] = weight;
    }
}

void AdjacencyList::removeEdge(int source, int destination)
{
    if (source >= 0 && source < vertices && destination >= 0 && destination < vertices)
    {
        adjacencyList[source].erase(destination);
        if (!directed)
            adjacencyList[destination].erase(source);
    }
}

vector<tuple<int, int, double>> AdjacencyList::getEdges() const
{
    vector<tuple<int, int, double>> edges;
    for (int i = 0; i < adjacencyList.size(); ++i)
    {
        for (const auto &entry : adjacencyList[i])
        {
            int j = entry.first;
            double weight = entry.second;
            edges.push_back({i, j, weight});
        }
    }
    return edges;
}

vector<map<int, double>> AdjacencyList::getVertices() const
{
    return adjacencyList;
}

void AdjacencyList::print() const
{
    for (int i = 0; i < vertices; ++i)
    {
        cout << i << ": ";
        for (const auto &neighbor : adjacencyList[i])
            cout << "(" << neighbor.first << "-" << neighbor.second << ") ";
        cout << endl;
    }
}
