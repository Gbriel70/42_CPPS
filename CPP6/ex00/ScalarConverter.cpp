/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:16 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:17 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
    std::cout << GREEN "Default constructor called" RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
    std::cout << GREEN "Copy constructor called" RESET << std::endl;
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    std::cout << GREEN "Copy assignment operator called" RESET << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() 
{
    std::cout << RED "Destructor called" RESET << std::endl;
}

bool ScalarConverter::isDisplayable(char c) {
    return (c >= 32 && c <= 126);
}

bool ScalarConverter::isCharLiteral(const std::string& str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    
    try {
        char* end;
        long value = std::strtol(str.c_str(), &end, 10);
        if (*end != '\0') return false;
        return (value >= std::numeric_limits<int>::min() && 
                value <= std::numeric_limits<int>::max());
    } catch (...) {
        return false;
    }
}

bool ScalarConverter::isFloatLiteral(const std::string& str) {
    if (str.length() < 3 || str[str.length() - 1] != 'f') return false;
    
    std::string withoutF = str.substr(0, str.length() - 1);
    
    if (withoutF.find('.') == std::string::npos) return false;
    
    if (withoutF[0] == '.') return false;
    
    if (withoutF[withoutF.length() - 1] == '.') return false;
    
    char* end;
    std::strtod(withoutF.c_str(), &end);
    return (*end == '\0');
}

bool ScalarConverter::isDoubleLiteral(const std::string& str) {
    if (str.empty()) return false;
    
    if (str.find('.') == std::string::npos) return false;

    if (str[str.length() - 1] == 'f') return false;
    
    if (str[0] == '.') return false;
    
    if (str[str.length() - 1] == '.') return false;
    
    char* end;
    std::strtod(str.c_str(), &end);
    return (*end == '\0');
}

bool ScalarConverter::isSpecialFloat(const std::string& str) {
    return (str == "+inff" || str == "-inff" || str == "nanf");
}

bool ScalarConverter::isSpecialDouble(const std::string& str) {
    return (str == "+inf" || str == "-inf" || str == "nan");
}

void ScalarConverter::convertFromChar(char c) {
    std::cout << "char: ";
    if (isDisplayable(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(int value) {
    std::cout << "char: ";
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (isDisplayable(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(float value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<char>::min() || 
        value > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (isDisplayable(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
    
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        if (value == static_cast<int>(value)) {
            std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
        } else {
            std::cout << std::noshowpoint << value << "f" << std::endl;
        }
    }
    
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convertFromDouble(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<char>::min() || 
        value > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (isDisplayable(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
    
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
    
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

void ScalarConverter::convertSpecialValues(const std::string& str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (str == "+inff" || str == "+inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (str == "-inff" || str == "-inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else if (str == "nanf" || str == "nan") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& str) {
    if (str.empty()) {
        std::cout << "Error: Empty string" << std::endl;
        return;
    }
    
    if (isSpecialFloat(str) || isSpecialDouble(str)) {
        convertSpecialValues(str);
        return;
    }
    
    if (isCharLiteral(str)) {
        convertFromChar(str[1]);
        return;
    }
    
    if (isFloatLiteral(str)) {
        float value = static_cast<float>(std::atof(str.c_str()));
        convertFromFloat(value);
        return;
    }
    
    if (isDoubleLiteral(str)) {
        double value = std::atof(str.c_str());
        convertFromDouble(value);
        return;
    }
    
    if (isIntLiteral(str)) {
        int value = std::atoi(str.c_str());
        convertFromInt(value);
        return;
    }
    
    std::cout << "Error: Invalid input format" << std::endl;
}