#pragma once

namespace DataStructures
{
    class Graph;
}

namespace Algorithms
{
    class DepthFirstSearch
    {
    public:
        static void traverse(const DataStructures::Graph &graph, int source);
    };
}
