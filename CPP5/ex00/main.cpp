/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:59:50 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 10:59:51 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	tryCreateBureaucrat("A", 13);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("B", 150);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("C", 0);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("D", 500);
	return 0;
}
