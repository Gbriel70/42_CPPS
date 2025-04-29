/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:11 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:12 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string name) : _name(name), _weapontype(NULL)
{
	return ;
}

HumanB::~HumanB(){
	return ;
}

void HumanB::attack(){
	if (_weapontype)
		cout << _name << " attacks with their " << _weapontype->getType() << endl;
	else
		cout << _name << " has no weapon to attack with" << endl;
}

void HumanB::setWeapon(Weapon& type){
	_weapontype = &type;
}