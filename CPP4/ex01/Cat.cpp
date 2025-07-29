/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:34:59 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:38:33 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	std::cout << "Cat constructor called." << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) 
{
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) {
            delete brain;
        }
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
    delete brain;
}

void Cat::makeSound() {
    std::cout << "Meow! I am a cat." << std::endl;
}
