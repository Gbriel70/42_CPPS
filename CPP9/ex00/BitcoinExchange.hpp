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