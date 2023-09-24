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

    REQUIRE(bst.search(31) == true);
    REQUIRE(bst.search(18) == false);

    REQUIRE(bst.min() == 3);
    REQUIRE(bst.max() == 88);

    REQUIRE(bst.successor(31) == 53);
    REQUIRE(bst.successor(15) == 23);
    REQUIRE(bst.successor(88) == std::nullopt);

    REQUIRE(bst.predecessor(12) == 7);
    REQUIRE(bst.predecessor(29) == 23);
    REQUIRE(bst.predecessor(3) == std::nullopt);

    bst.remove(15);
    bst.remove(53);

    preorder = capture([&]()
                       { bst.preorder(); });
    REQUIRE(preorder == "23 12 3 7 31 29 88 \n");

    inorder = capture([&]()
                      { bst.inorder(); });
    REQUIRE(inorder == "3 7 12 23 29 31 88 \n");

    postorder = capture([&]()
                        { bst.postorder(); });
    REQUIRE(postorder == "7 3 12 29 88 31 23 \n");

    levelorder = capture([&]()
                         { bst.levelorder(); });
    REQUIRE(levelorder == "23 12 31 3 29 88 7 \n");

    bst.remove(31);

    preorder = capture([&]()
                       { bst.preorder(); });
    REQUIRE(preorder == "23 12 3 7 88 29 \n");

    inorder = capture([&]()
                      { bst.inorder(); });
    REQUIRE(inorder == "3 7 12 23 29 88 \n");

    postorder = capture([&]()
                        { bst.postorder(); });
    REQUIRE(postorder == "7 3 12 29 88 23 \n");

    levelorder = capture([&]()
                         { bst.levelorder(); });
    REQUIRE(levelorder == "23 12 88 3 29 7 \n");
}