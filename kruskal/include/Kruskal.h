#pragma once

namespace DataStructures
{
    class Graph;
}

namespace Algorithms
{
    class Kruskal
    {
    public:
        Kruskal(const DataStructures::Graph &graph);
        ~Kruskal();

        static int minimumSpanningTree(const DataStructures::Graph &graph);

    private:
        int *parent, *rank;
        const DataStructures::Graph &graph;

        int find(int u);
        void merge(int x, int y);
    };
}
