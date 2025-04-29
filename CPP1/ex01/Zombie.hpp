/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:02:40 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:02:41 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <string>

using namespace	std;

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

Zombie			*ZombieHorde(int x, std::string name);

#endif