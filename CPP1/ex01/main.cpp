/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:49:37 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/23 10:49:38 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	Zombie *zombie;
	int nbr;

	if (ac < 2)
	{
		cout << "you need to give me a name!" << endl;
		return (1);
	}

	nbr = atoi(av[1]);
	if (nbr <= 0)
	{
		cout << "you need to give me a number!" << endl;
		return (1);
	}

	zombie = ZombieHorde(nbr, av[2]);
	for (int i = 0; i < nbr; i++)
		zombie[i].announce();

	delete[] zombie;
	return (0);
}