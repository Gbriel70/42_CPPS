/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:21 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:22 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const string& Weapon::getType() {
	return (_type);
}

void Weapon::setType(string type) {
	_type = type;
}

Weapon::Weapon(string type) {
	_type = type;
}

Weapon::~Weapon() {
	return ;
}