#include "Wrong_Animal_Cat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    setType(other.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        setType(other.getType());
    }
    return *this;
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const {
    cout << "Wrong meow!" << endl;
}

