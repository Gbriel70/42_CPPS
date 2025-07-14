#ifndef WRONG_ANIMAL_CAT_HPP
#define WRONG_ANIMAL_CAT_HPP

#include "Wrong_Animal.hpp"

using namespace std;

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        ~WrongCat();

        void makeSound() const override;
};

#endif