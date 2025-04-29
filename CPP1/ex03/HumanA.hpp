/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:08 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:09 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

using namespace std;

class HumanA {

	private:
		string _name;
		Weapon& _weaponType;

	public:
		HumanA(string name, Weapon& type);
		~HumanA();
		void attack();
};

#endif