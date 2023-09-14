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
}
