/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:48 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:34:06 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() 
{
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() {
    std::cout << "Woof! I am a dog." << std::endl;
}