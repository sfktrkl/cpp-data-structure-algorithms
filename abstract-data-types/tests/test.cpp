#include "Animal.h"
#include <catch2/catch_test_macros.hpp>

using namespace AbstractDataTypes;
using namespace std;

TEST_CASE("Dog Class Tests")
{
    Dog dog("Bulldog");
    SECTION("Properties of a Dog")
    {
        REQUIRE(dog.getName() == "Bulldog");
        REQUIRE(dog.makeSound() == "woof-woof!");
    }

    Dog dog2 = dog;
    SECTION("Copy Constructor Test")
    {
        REQUIRE(dog2.getName() == "Bulldog");
        REQUIRE(dog2.makeSound() == "woof-woof!");
    }

    Dog dog3("");
    SECTION("Copy Assignment Test")
    {
        dog3 = dog2;
        REQUIRE(dog3.getName() == "Bulldog");
        REQUIRE(dog3.makeSound() == "woof-woof!");
    }
}
