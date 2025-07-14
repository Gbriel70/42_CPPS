#include "Animal.hpp"

Animal::Animal() : _type("Unknown") {}

Animal::Animal(const std::string &type) : _type(type) {}

Animal::Animal(const Animal &other) : _type(other._type) {}

Animal::~Animal() {}

void Animal::setType(const std::string &type) {
    _type = type;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() {
    std::cout << "Animal makes a sound." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}