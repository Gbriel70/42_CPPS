/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:02:24 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:02:25 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iomanip>
#include <iostream>

using namespace std;

class Zombie
{
  private:
	string _name;

  public:
	Zombie();
	Zombie(string name);
	~Zombie();

	void announce();
	void reName(string name);
};

Zombie *newZombie(string name);
void randomChump(string name);

#endif