#include "Kruskal.h"
#include <catch2/catch_test_macros.hpp>
#include "../../graph/include/AdjacencyList.h"
#include "../../graph/include/AdjacencyMatrix.h"
#include <iostream>
#include <sstream>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

TEST_CASE("Kruskal's Algorithm Adjacency List Test")
{
    AdjacencyList graph(9);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    REQUIRE(Kruskal::minimumSpanningTree(graph) == 37);
}

TEST_CASE("Kruskal's Algorithm Adjacency Matrix Test")
{
    AdjacencyMatrix graph(9);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    REQUIRE(Kruskal::minimumSpanningTree(graph) == 37);
}
