/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:33:52 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/07/29 11:37:21 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain constructor called." << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Idea ";
    }
}

Brain::Brain(const Brain &other) 
{
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; ++i) {
        std::cout << "Idea " << i + 1 << ": " << ideas[i] << std::endl;
    }
	    std::cout << "... (95 more ideas)" << std::endl;
}