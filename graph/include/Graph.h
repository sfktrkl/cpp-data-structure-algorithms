#pragma once
#include <vector>
#include <map>

namespace DataStructures
{
    class Graph
    {
    public:
        Graph(int vertices, bool directed) : vertices(vertices), directed(directed) {}

        virtual void addEdge(int source, int destination, double weight = 1.0) = 0;
        virtual void removeEdge(int source, int destination) = 0;

        virtual std::vector<std::tuple<int, int, double>> getEdges() const = 0;
        virtual std::vector<std::map<int, double>> getVertices() const = 0;
        virtual int numberOfVertices() const { return vertices; };
        virtual int isDirected() const { return directed; };
        virtual void print() const = 0;

    protected:
        int vertices;
        bool directed;
    };
}
