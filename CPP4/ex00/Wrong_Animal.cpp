#include "Wrong_Animal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") {}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::setType(const string &type) {
    _type = type;
}

string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    cout << "WrongAnimal makes a sound." << endl;
}

