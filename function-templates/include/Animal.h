#pragma once
#include <string>
#include "../../abstract-data-types/include/Animal.h"

namespace AbstractDataTypes
{
    class Cat : public Animal
    {
    public:
        Cat(std::string name) : Animal(name) {}

        std::string makeSound() override;
    };

    template <typename T>
    std::string getNameAndMakeSound(T &animal)
    {
        return animal.getName() + " - " + animal.makeSound();
    }
}
