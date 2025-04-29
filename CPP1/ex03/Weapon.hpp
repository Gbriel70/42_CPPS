/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:28 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:29 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using namespace std;

class Weapon {

	private:
		string _type;

	public:
		Weapon(string type);
		~Weapon();
		const string& getType();
		void setType(string type);
};

#endif