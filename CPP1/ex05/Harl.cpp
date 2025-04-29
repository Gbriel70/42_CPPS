/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:45 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:03:46 by gcosta-m         ###   ########.fr       */
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

	int n = -1;
	if (level.length() == 1 && level[0] >= '0' && level[0] <= '9'){
		n = level[0] - '0';
	}

	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	if (n >= 0 && n < 4){
		(this->*functions[n])();
		return;
	}

	for (int i = 0; i < 4; i++){
		if (levels[i] == level){
			(this->*functions[i])();
			return;
		}
	}
	cout << "Iválid command!!" << endl;
}