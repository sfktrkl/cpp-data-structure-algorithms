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
}
