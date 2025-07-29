/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:35:27 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:38:47 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "Dog constructor called." << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) 
{
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) {
            delete brain;
        }
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
    delete brain;
}

void Dog::makeSound() {
    std::cout << "Woof! I am a dog." << std::endl;
}