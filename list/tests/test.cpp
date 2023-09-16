#include "List.h"
#include <catch2/catch_test_macros.hpp>

using namespace AbstractDataTypes;
using namespace std;

TEST_CASE("List ADT Test")
{
    List<int> list;

    SECTION("Check empty List")
    {
        REQUIRE(list.size() == 0);
    }

    list.insert(0, 21);
    list.insert(1, 47);
    list.insert(2, 87);
    list.insert(3, 35);
    list.insert(4, 92);

    SECTION("Check item count in List")
    {
        REQUIRE(list.size() == 5);
    }

    SECTION("Check items in List")
    {
        int i = 0;
        for (const auto &value : {21, 47, 87, 35, 92})
            REQUIRE(list.get(i++) == value);
    }

    list.insert(2, 25);
    list.insert(2, 71);

    SECTION("Check item count in List")
    {
        REQUIRE(list.size() == 7);
    }

    SECTION("Check items in List")
    {
        REQUIRE(list.get(2) == 71);
        REQUIRE(list.get(3) == 25);
    }

    SECTION("Search items in List")
    {
        REQUIRE(list.search(71) == 2);
        REQUIRE_THROWS(list.search(44));
    }

    list.remove(2);

    SECTION("Check item in List")
    {
        REQUIRE(list.get(2) == 25);
    }

    SECTION("Search item in List")
    {
        REQUIRE_THROWS(list.search(71));
    }
}
