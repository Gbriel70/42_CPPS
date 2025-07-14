#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::Cat(const Cat &other) : Animal(other) {}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat(){}

void Cat::makeSound() {
    std::cout << "Meow! I am a cat." << std::endl;
}
