#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) 
{
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) {
            delete brain;
        }   
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
}

void Cat::makeSound() {
    std::cout << "Meow! I am a cat." << std::endl;
}
