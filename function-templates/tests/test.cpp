#include "Animal.h"
#include <catch2/catch_test_macros.hpp>

using namespace AbstractDataTypes;
using namespace std;

TEST_CASE("Function Template Test")
{
    SECTION("Template for Dog")
    {
        Dog dog("Bulldog");
        REQUIRE(getNameAndMakeSound(dog) == "Bulldog - woof-woof!");
    }

    SECTION("Template for Cat")
    {
        Cat cat("Persian Cat");
        REQUIRE(getNameAndMakeSound(cat) == "Persian Cat - meow-meow!");
    }
}
