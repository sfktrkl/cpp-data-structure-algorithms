#include "AdjacencyMatrix.h"
#include <iostream>
#include <limits>

using namespace DataStructures;
using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int vertices, bool directed)
    : Graph(vertices, directed), matrix(vertices, map<int, double>())
{
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
            matrix[i][j] = numeric_limits<double>::infinity();
    }
}

void AdjacencyMatrix::addEdge(int source, int destination, double weight)
{
    if (source >= 0 && source < vertices && destination >= 0 && destination < vertices)
    {
        matrix[source][destination] = weight;
        if (!directed)
            matrix[destination][source] = weight;
    }
}

void AdjacencyMatrix::removeEdge(int source, int destination)
{
    if (source >= 0 && source < vertices && destination >= 0 && destination < vertices)
    {
        matrix[source][destination] = numeric_limits<double>::infinity();
        if (!directed)
            matrix[destination][source] = numeric_limits<double>::infinity();
    }
}

vector<tuple<int, int, double>> AdjacencyMatrix::getEdges() const
{
    vector<tuple<int, int, double>> edges;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (const auto &entry : matrix[i])
        {
            int j = entry.first;
            double weight = entry.second;
            edges.push_back({i, j, weight});
        }
    }
    return edges;
}

vector<map<int, double>> AdjacencyMatrix::getVertices() const
{
    return matrix;
}

void AdjacencyMatrix::print() const
{
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            if (matrix.at(i).at(j) == numeric_limits<double>::infinity())
                cout << "# ";
            else
                cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
