/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:52 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:53 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		cout << "Usage: ./harlFilter <level>" << endl;
		return 1;
	}
	Harl harl;
	harl.complain(av[1]);
	return 0;
}