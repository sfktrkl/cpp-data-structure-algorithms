#pragma once
#include <string>

namespace AbstractDataTypes
{
    class Animal
    {
    protected:
        std::string name;

    public:
        Animal(std::string name) : name(name) {}

        virtual std::string makeSound() = 0;

        std::string getName();
    };

    class Dog : public Animal
    {
    public:
        Dog(std::string name) : Animal(name) {}

        std::string makeSound() override;
    };
}
