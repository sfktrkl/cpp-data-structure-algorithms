#include "Animal.h"
#include <catch2/catch_test_macros.hpp>

using namespace AbstractDataTypes;
using namespace std;

TEST_CASE("Class Template Test")
{
    SECTION("Template for Dog")
    {
        Dog dog("Bulldog");
        AnimalTemplate<Dog> dogTemplate(dog);
        REQUIRE(dogTemplate.getNameAndMakeSound() == "Bulldog - woof-woof!");
    }

    SECTION("Template for Cat")
    {
        Cat cat("Persian Cat");
        AnimalTemplate<Cat> catTemplate(cat);
        REQUIRE(catTemplate.getNameAndMakeSound() == "Persian Cat - meow-meow!");
    }
}
