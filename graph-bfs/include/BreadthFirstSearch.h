#pragma once

namespace DataStructures
{
    class Graph;
}

namespace Algorithms
{
    class BreadthFirstSearch
    {
    public:
        static void traverse(const DataStructures::Graph &graph, int source);
    };
}
