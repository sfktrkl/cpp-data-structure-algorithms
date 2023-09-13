#pragma once
#include <string>
#include "../../abstract-data-types/include/Animal.h"
#include "../../function-templates/include/Animal.h"

namespace AbstractDataTypes
{
    template <typename T>
    class AnimalTemplate
    {
    private:
        T animal;

    public:
        AnimalTemplate(T animal) : animal(animal) {}

        std::string getNameAndMakeSound()
        {
            return animal.getName() + " - " + animal.makeSound();
        }
    };
}
