/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:31 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:32 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() 
{
    std::cout << GREEN << "Serializer constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other) 
{ 
    (void)other;
    std::cout << GREEN << "Serializer copy constructor called" << RESET << std::endl; 
}

Serializer& Serializer::operator=(const Serializer& other) 
{ 
    (void)other; 
    std::cout << GREEN << "Serializer assignment operator called" << RESET << std::endl;
    return *this; 
}

Serializer::~Serializer() 
{
    std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) 
{
    return reinterpret_cast<Data*>(raw);
}
