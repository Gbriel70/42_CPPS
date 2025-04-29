/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:49:45 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/23 10:49:46 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	_name = "Zombie";
	cout << "A Zombie was born!" << endl;
	return ;
}

Zombie::Zombie(string name)
{
	this->_name = name;
	cout << "A was born!. Its name is" << this->_name << endl;
	return ;
}

Zombie::~Zombie()
{
	cout << this->_name << " Is dead again!" << endl;
	return ;
}

void Zombie::announce()
{
	cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
	return ;
}

void Zombie::reName(string name)
{
	cout << this->_name << " Is now called ";
	this->_name = name;
	cout << this->_name << endl;
	return ;
}