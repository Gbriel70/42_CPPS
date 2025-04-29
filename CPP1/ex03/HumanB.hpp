/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:14 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:15 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

using namespace std;

class HumanB {

	private:
		string _name;
		Weapon* _weapontype;
	
	public:
		HumanB(string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon& type);
};

#endif