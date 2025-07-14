#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    //Animal* meta = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    cout << dog->getType() << endl;
    cout << cat->getType() << endl;

    dog->makeSound();
    cat->makeSound();

    return 0;
}