#include "BST.h"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>

using namespace DataStructures;
using namespace std;

TEST_CASE("Binary Search Tree Test")
{
    BST<int> bst;

    int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53};
    for (const int &key : keys)
        bst.insert(key);
}