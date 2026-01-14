/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:35:34 by gcosta-m          #+#    #+#             */
/*   Updated: 2026/01/14 10:36:36 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _exchangedata(other._exchangedata){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_exchangedata = other._exchangedata;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open database file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::iterator pos = std::find(line.begin(), line.end(), ',');
		std::string date = line.substr(0, pos - line.begin());
		std::string value = line.substr(pos - line.begin() + 1);
		float float_value = std::atof(value.c_str());
		_exchangedata[date] = float_value;
	}
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		std::size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = trim(line.substr(0, pos));
		std::string value_str = trim(line.substr(pos + 1));
		float value;
		
		try {
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue ;
			}
			if (!isValidValue(value_str))
			{
				if (value_str.find('-') != std::string::npos)
					std::cerr << "Error: not a positive number." << std::endl;
				else
					std::cerr << "Error: too large a number." << std::endl;
				continue ;
			}
			value = std::atof(value_str.c_str());
			float rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < static_cast<int>(date.length()); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
	std::istringstream iss(value);
	float num;
	char c;

	if (value.empty())
		return false;
	if (!(iss >> num) || (iss >> c))
		return false;
	if (num < 0 || num > 1000)
		return false;
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	if (_exchangedata.empty())
	{
		std::cerr << "Error: Exchange data not loaded." << std::endl;
		return 0.0f;
	}
	if (date.empty())
		return _exchangedata.begin()->second;
	std::map<std::string, float>::const_iterator it = _exchangedata.lower_bound(date);
	if (it == _exchangedata.end())
		--it;
	else if (it->first != date && it != _exchangedata.begin())
		--it;
	else if (it->first != date && it == _exchangedata.begin())
	{
		std::cerr << "Error: No earlier date available for exchange rate." << std::endl;
		return 0.0f;
	}
	return it->second;
}

std::string BitcoinExchange::trim(const std::string &str)
{
	std::string result = str;
	while (result.length() > 0 && (std::isspace(result[0]) || std::isspace(result[result.length() - 1])))
	{
		if (std::isspace(result[0]))
			result.erase(result.begin());
		if (std::isspace(result[result.length() - 1]))
			result.erase(result.end() - 1);
	}
	return result;
}