#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

using namespace DataStructures;
using namespace std;

TEST_CASE("Unweighted Adjacency List Test")
{
    AdjacencyList graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (1-1) (2-1) \n"
                "1: (0-1) (3-1) \n"
                "2: (0-1) (4-1) \n"
                "3: (1-1) \n"
                "4: (2-1) \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (2-1) \n"
                "1: (3-1) \n"
                "2: (0-1) (4-1) \n"
                "3: (1-1) \n"
                "4: (2-1) \n");
    }
}

TEST_CASE("Weighted Adjacency List Test")
{
    AdjacencyList graph(5);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (1-2) (2-1) \n"
                "1: (0-2) (3-3) \n"
                "2: (0-1) (4-4) \n"
                "3: (1-3) \n"
                "4: (2-4) \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (2-1) \n"
                "1: (3-3) \n"
                "2: (0-1) (4-4) \n"
                "3: (1-3) \n"
                "4: (2-4) \n");
    }
}

TEST_CASE("Directed Unweighted Adjacency List Test")
{
    AdjacencyList graph(5, true);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (1-1) (2-1) \n"
                "1: (3-1) \n"
                "2: (4-1) \n"
                "3: \n"
                "4: \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (2-1) \n"
                "1: (3-1) \n"
                "2: (4-1) \n"
                "3: \n"
                "4: \n");
    }
}

TEST_CASE("Directed Weighted Adjacency List Test")
{
    AdjacencyList graph(5, true);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (1-2) (2-1) \n"
                "1: (3-3) \n"
                "2: (4-4) \n"
                "3: \n"
                "4: \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "0: (2-1) \n"
                "1: (3-3) \n"
                "2: (4-4) \n"
                "3: \n"
                "4: \n");
    }
}

TEST_CASE("Unweighted Adjacency Matrix Test")
{
    AdjacencyMatrix graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# 1 1 # # \n"
                "1 # # 1 # \n"
                "1 # # # 1 \n"
                "# 1 # # # \n"
                "# # 1 # # \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# # 1 # # \n"
                "# # # 1 # \n"
                "1 # # # 1 \n"
                "# 1 # # # \n"
                "# # 1 # # \n");
    }
}

TEST_CASE("Weighted Adjacency Matrix Test")
{
    AdjacencyMatrix graph(5);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# 2 1 # # \n"
                "2 # # 3 # \n"
                "1 # # # 4 \n"
                "# 3 # # # \n"
                "# # 4 # # \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# # 1 # # \n"
                "# # # 3 # \n"
                "1 # # # 4 \n"
                "# 3 # # # \n"
                "# # 4 # # \n");
    }
}

TEST_CASE("Directed Unweighted Adjacency Matrix Test")
{
    AdjacencyMatrix graph(5, true);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# 1 1 # # \n"
                "# # # 1 # \n"
                "# # # # 1 \n"
                "# # # # # \n"
                "# # # # # \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# # 1 # # \n"
                "# # # 1 # \n"
                "# # # # 1 \n"
                "# # # # # \n"
                "# # # # # \n");
    }
}

TEST_CASE("Directed Weighted Adjacency Matrix Test")
{
    AdjacencyMatrix graph(5, true);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 3);
    graph.addEdge(2, 4, 4);

    SECTION("check edges")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# 2 1 # # \n"
                "# # # 3 # \n"
                "# # # # 4 \n"
                "# # # # # \n"
                "# # # # # \n");
    }

    graph.removeEdge(0, 1);

    SECTION("check edges after remove")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        graph.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "# # 1 # # \n"
                "# # # 3 # \n"
                "# # # # 4 \n"
                "# # # # # \n"
                "# # # # # \n");
    }
}
