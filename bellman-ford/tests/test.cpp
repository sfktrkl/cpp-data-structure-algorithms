#include "BellmanFord.h"
#include <catch2/catch_test_macros.hpp>
#include "../../graph/include/AdjacencyList.h"
#include "../../graph/include/AdjacencyMatrix.h"
#include <iostream>
#include <sstream>

using namespace DataStructures;
using namespace Algorithms;
using namespace std;

TEST_CASE("Bellman-Ford Algorithm Adjacency List Test")
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
    BellmanFord::shortestPath(graph, 0);
    cout.rdbuf(original);

    REQUIRE(capture.str() ==
            "0\t0\n"
            "1\t4\n"
            "2\t12\n"
            "3\t19\n"
            "4\t21\n"
            "5\t11\n"
            "6\t9\n"
            "7\t8\n"
            "8\t14\n");
}

TEST_CASE("Bellman-Ford Algorithm Adjacency Matrix Test")
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
    BellmanFord::shortestPath(graph, 0);
    cout.rdbuf(original);

    REQUIRE(capture.str() ==
            "0\t0\n"
            "1\t4\n"
            "2\t12\n"
            "3\t19\n"
            "4\t21\n"
            "5\t11\n"
            "6\t9\n"
            "7\t8\n"
            "8\t14\n");
}
