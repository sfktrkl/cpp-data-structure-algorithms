#include "BTree.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

using namespace DataStructures;
using namespace std;

TEST_CASE("B-Tree Test")
{
    BTree<int> tree(3);

    SECTION("Search empty B-Tree")
    {
        REQUIRE(tree.search(3) == nullptr);
    }

    tree.insert(9);
    tree.insert(15);
    tree.insert(17);
    tree.insert(21);
    tree.insert(22);
    tree.insert(23);
    tree.insert(25);
    tree.insert(27);
    tree.insert(30);
    tree.insert(32);
    tree.insert(39);
    tree.insert(40);
    tree.insert(41);
    tree.insert(47);
    tree.insert(55);
    tree.insert(56);
    tree.insert(60);
    tree.insert(63);

    SECTION("Search in B-Tree")
    {
        REQUIRE(tree.search(3) == nullptr);
        REQUIRE(tree.search(9) != nullptr);
    }

    SECTION("Print B-Tree")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        tree.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "17 23 30 40 55 \n"
                "  9 15 \n"
                "  21 22 \n"
                "  25 27 \n"
                "  32 39 \n"
                "  41 47 \n"
                "  56 60 63 \n");
    }

    SECTION("Search before delete from B-Tree")
    {
        REQUIRE(tree.search(30) != nullptr);
    }

    tree.remove(30);

    SECTION("Search after delete from B-Tree")
    {
        REQUIRE(tree.search(30) == nullptr);
    }

    SECTION("Print B-Tree")
    {
        ostringstream capture;
        streambuf *original = cout.rdbuf(capture.rdbuf());
        tree.print();
        cout.rdbuf(original);

        REQUIRE(capture.str() ==
                "17 23 40 55 \n"
                "  9 15 \n"
                "  21 22 \n"
                "  25 27 32 39 \n"
                "  41 47 \n"
                "  56 60 63 \n");
    }
}
