/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:32 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/23 15:29:33 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong_Animal.hpp"
#include "Wrong_Animal_Cat.hpp"

int main() 
{
    std::cout << "=== Testing Animal classes ===" << std::endl;
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

    std::cout << "\n=== Testing Wrong Animal classes ===" << std::endl;
    WrongAnimal* wrongMeta = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;

    wrongCat->makeSound();
    wrongMeta->makeSound(); 

    delete wrongMeta;
    delete wrongCat;

    return 0;
}