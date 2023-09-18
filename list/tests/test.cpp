#include "List.h"
#include "SmartList.h"
#include <catch2/catch_test_macros.hpp>

using namespace AbstractDataTypes;
using namespace std;

template <typename ListType>
void ListOperations()
{
    ListType list;
    REQUIRE(list.size() == 0);

    list.insert(0, 21);
    list.insert(1, 47);
    list.insert(2, 87);
    list.insert(3, 35);
    list.insert(4, 92);

    int i = 0;
    REQUIRE(list.size() == 5);
    for (const auto &value : {21, 47, 87, 35, 92})
        REQUIRE(list.get(i++) == value);

    list.insert(2, 25);
    list.insert(2, 71);

    REQUIRE(list.size() == 7);
    REQUIRE(list.get(2) == 71);
    REQUIRE(list.get(3) == 25);
    REQUIRE(list.search(71) == 2);
    REQUIRE_THROWS(list.search(44));

    list.remove(2);
    REQUIRE(list.get(2) == 25);
    REQUIRE_THROWS(list.search(71));
}

TEST_CASE("List ADT Test")
{
    ListOperations<List<int>>();
}

TEST_CASE("SmartList ADT Test")
{
    ListOperations<SmartList<int>>();
}
