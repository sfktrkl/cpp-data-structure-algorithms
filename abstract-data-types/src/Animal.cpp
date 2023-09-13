#include "Animal.h"

using namespace AbstractDataTypes;
using namespace std;

string Animal::getName()
{
    return name;
}

string Dog::makeSound()
{
    return "woof-woof!";
}
