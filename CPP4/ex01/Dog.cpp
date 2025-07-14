#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) 
{
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) {
            delete brain;
        }
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
}

void Dog::makeSound() {
    std::cout << "Woof! I am a dog." << std::endl;
}