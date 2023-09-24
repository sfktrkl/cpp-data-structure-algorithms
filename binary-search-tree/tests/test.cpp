#include "BST.h"
#include <catch2/catch_test_macros.hpp>
#include <functional>
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

    auto capture = [](function<void()> print)
    {
        ostringstream result;
        streambuf *original = cout.rdbuf(result.rdbuf());
        print();
        cout.rdbuf(original);
        return result.str();
    };

    auto preorder = capture([&]()
                            { bst.preorder(); });
    REQUIRE(preorder == "23 12 3 7 15 31 29 88 53 \n");

    auto inorder = capture([&]()
                           { bst.inorder(); });
    REQUIRE(inorder == "3 7 12 15 23 29 31 53 88 \n");

    auto postorder = capture([&]()
                             { bst.postorder(); });
    REQUIRE(postorder == "7 3 15 12 29 53 88 31 23 \n");

    auto levelorder = capture([&]()
                              { bst.levelorder(); });
    REQUIRE(levelorder == "23 12 31 3 15 29 88 7 53 \n");
}