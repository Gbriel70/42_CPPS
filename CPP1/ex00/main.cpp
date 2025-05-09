/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:02:08 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:02:09 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1;
	Zombie zombie2("Zombie2");
	Zombie *zombie3 = newZombie("Zombie3");

	zombie1.announce();
	cout << "\n------------------------" << endl;
	zombie2.announce();
	cout << "\n------------------------" << endl;
	zombie3->announce();
	cout << "\n------------------------" << endl;

	randomChump(" Bola ");
	cout << "\n------------------------" << endl;
	delete zombie3;
	return (0);
}