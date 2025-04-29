/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:49:53 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/23 10:49:55 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*ZombieHorde(int x, std::string name)
{
	Zombie *horde = new Zombie[x];

	for (int i = 0; i < x; i++)
		horde[i].reName(name);
	return (horde);
}