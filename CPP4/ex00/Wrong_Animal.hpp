#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

using namespace std;

class WrongAnimal
{
    protected:
        string _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        virtual ~WrongAnimal();

        void setType(const string &type);
        string getType() const;

        virtual void makeSound() const;

};

#endif