/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:22 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:23 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdlib>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define SPECIAL 4
#define IMPOSSIBLE 5

class ScalarConverter 
{
    public:
        static void convert(const std::string& str);
        
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static bool isCharLiteral(const std::string& str);
        static bool isIntLiteral(const std::string& str);
        static bool isFloatLiteral(const std::string& str);
        static bool isDoubleLiteral(const std::string& str);
        static bool isSpecialFloat(const std::string& str);
        static bool isSpecialDouble(const std::string& str);

        static void convertFromChar(char c);
        static void convertFromInt(int value);
        static void convertFromFloat(float value);
        static void convertFromDouble(double value);
        static void convertSpecialValues(const std::string& str);

        static bool isDisplayable(char c);
};

#endif