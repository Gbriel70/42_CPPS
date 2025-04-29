/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:02:14 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:02:15 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void randomChump(string name)
{
	Zombie zombie(name);
	zombie.announce();
	return ;
}