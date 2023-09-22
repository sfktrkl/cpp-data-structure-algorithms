#include "DepthFirstSearch.h"
#include <catch2/catch_test_macros.hpp>
#include "../../graph/include/AdjacencyList.h"
#include "../../graph/include/AdjacencyMatrix.h"
#include <iostream>
#include <sstream>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

TEST_CASE("Depth First Search Adjacency List Test")
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

    ostringstream capture;
    streambuf *original = cout.rdbuf(capture.rdbuf());
    DepthFirstSearch::traverse(graph, 0);
    cout.rdbuf(original);

    REQUIRE(capture.str() ==
            "Visited 0\n"
            "Visited 7\n"
            "Visited 8\n"
            "Visited 2\n"
            "Visited 5\n"
            "Visited 4\n"
            "Visited 3\n"
            "Visited 6\n"
            "Visited 1\n");
}

TEST_CASE("Depth First Search Adjacency Matrix Test")
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

    ostringstream capture;
    streambuf *original = cout.rdbuf(capture.rdbuf());
    DepthFirstSearch::traverse(graph, 0);
    cout.rdbuf(original);

    REQUIRE(capture.str() ==
            "Visited 0\n"
            "Visited 7\n"
            "Visited 8\n"
            "Visited 2\n"
            "Visited 5\n"
            "Visited 4\n"
            "Visited 3\n"
            "Visited 6\n"
            "Visited 1\n");
}
