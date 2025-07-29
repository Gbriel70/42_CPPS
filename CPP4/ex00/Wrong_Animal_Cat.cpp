/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong_Animal_Cat.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:29:55 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:35:19 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong_Animal_Cat.hpp"

WrongCat::WrongCat() : WrongAnimal() 
{
	std::cout << "WrongCat constructor called." << std::endl;
    setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    setType(other.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        setType(other.getType());
    }
    return *this;
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong meow!" << std::endl;
}

