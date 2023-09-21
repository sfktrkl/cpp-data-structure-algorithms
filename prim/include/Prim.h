#pragma once

namespace DataStructures
{
    class Graph;
}

namespace Algorithms
{
    class Prim
    {
    public:
        static int minimumSpanningTree(const DataStructures::Graph &graph);
    };
}
