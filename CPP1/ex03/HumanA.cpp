/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:05 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:06 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon& weapon) : _name(name), _weaponType(weapon)
{
	return ;
}

HumanA::~HumanA(){
	return ;
}

void HumanA::attack(){
	cout << _name << " attacks with their " << _weaponType.getType() << endl;
}
