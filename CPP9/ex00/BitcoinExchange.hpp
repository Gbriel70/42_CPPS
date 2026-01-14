/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:35:42 by gcosta-m          #+#    #+#             */
/*   Updated: 2026/01/14 10:36:36 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangedata;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processInputFile(const std::string &filename);
		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &value);
		float getExchangeRate(const std::string &date) const;
		std::string trim(const std::string &str);
};

#endif