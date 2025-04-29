/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:59 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:04:00 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void){
	cout << "[Debug]: Showing debug information." << endl;
}

void Harl::error(void){
	cout << "[Error]: An error has occurred." << endl;
}

void Harl::info(void){
	cout << "[Info]: This is some information." << endl;
}

void Harl::warning(void){
	cout << "[Warning]: This is a warning." << endl;
}

void Harl::complain(string level){
	string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int n = 4;

	for (int i = 0; i < 4; i++){
		if (levels[i] == level){
			n = i;
			break;
		}
	}
	if (n == 4 && level.length() == 1 && level[0] >= '0' && level[0] <= '3'){
		n = level[0] - '0';
	}

	switch (n)
	{
		case 0:{
			debug();
			cout << "\n" << endl;
			goto case1;
		}
		case 1: case1:{
			info();
			cout << "\n" << endl;
			goto case2;
		}
		case 2: case2:{
			warning();
			cout << "\n" << endl;
			goto case3;
		}
		case 3: case3:{
			error();
			cout << "\n" << endl;
			break;
		}
		default:{
			cout << "Invalid command!!\n" << endl;
			break;
		}
	}
}