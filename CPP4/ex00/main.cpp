//#include "Animal.hpp"
//#include "Dog.hpp"
//#include "Cat.hpp"
#include "Wrong_Animal.hpp"
#include "Wrong_Animal_Cat.hpp"

/*int main() 
{
    Animal* meta = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    cout << dog->getType() << endl;
    cout << cat->getType() << endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound(); 

    delete meta;
    delete dog;
    delete cat;
    return 0;
}*/


int main() 
{
    WrongAnimal* meta = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    cout << wrongCat->getType() << endl;

    wrongCat->makeSound();
    meta->makeSound(); 

    delete meta;
    delete wrongCat;
    return 0;
}