/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:01:49 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:39:45 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown") 
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const std::string &type) : _type(type) {}

Animal::Animal(const Animal &other) : _type(other._type) {}

Animal::~Animal() 
{
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::setType(const std::string &type) {
    _type = type;
}

std::string Animal::getType() const {
    return _type;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}