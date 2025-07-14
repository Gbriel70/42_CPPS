#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

using namespace std;

class Animal
{
    protected:
        string _type;

    public:
        Animal();
        Animal(const string &type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        void setType(const string &type);
        string getType() const;
        virtual void makeSound() = 0;
};

#endif