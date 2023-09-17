#pragma once
#include "Graph.h"

namespace DataStructures
{
    class AdjacencyMatrix : public Graph
    {
    public:
        AdjacencyMatrix(int vertices, bool directed = false);

        void addEdge(int source, int destination, double weight = 1.0) override;
        void removeEdge(int source, int destination) override;

        std::vector<std::tuple<int, int, double>> getEdges() const override;
        std::vector<std::map<int, double>> getVertices() const override;
        void print() const override;

    private:
        std::vector<std::map<int, double>> matrix;
    };
}
