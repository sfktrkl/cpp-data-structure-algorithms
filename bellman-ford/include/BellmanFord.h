#pragma once

namespace DataStructures
{
    class Graph;
}

namespace Algorithms
{
    class BellmanFord
    {
    public:
        static void shortestPath(const DataStructures::Graph &graph, int source);
    };
}
