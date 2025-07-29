/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong_Animal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:30:02 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:34 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong_Animal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown") 
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::setType(const std::string &type) {
    _type = type;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a sound." << std::endl;
}

