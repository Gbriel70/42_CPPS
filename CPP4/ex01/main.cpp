#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"


int main() 
{
    std::cout << "=== Basic Animal tests ===" << std::endl;
    Animal* meta = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound(); 

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Array of Animals test ===" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new Dog();
        std::cout << "Created Dog " << i << std::endl;
    }

    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new Cat();
        std::cout << "Created Cat " << i << std::endl;
    }

    std::cout << "\n--- Testing sounds ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Deleting animal " << i << " (" << animals[i]->getType() << ")" << std::endl;
        delete animals[i];
    }

    return 0;
}