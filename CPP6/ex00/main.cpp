/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:13 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:14 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printHeader(const std::string& title) {
    std::cout << "\n" << BLUE << "==== " << title << " ====" << RESET << std::endl;
}

void printSubHeader(const std::string& subtitle) {
    std::cout << "\n" << YELLOW << "--- " << subtitle << " ---" << RESET << std::endl;
}

void testConversion(const std::string& input) {
    std::cout << "\nInput: \"" << GREEN << input << RESET << "\"" << std::endl;
    ScalarConverter::convert(input);
}

void testCharLiterals() {
    printHeader("TESTING CHAR LITERALS");
    
    printSubHeader("Valid displayable chars");
    testConversion("'a'");
    testConversion("'Z'");
    testConversion("'0'");
    testConversion("'9'");
    testConversion("' '");
    testConversion("'@'");
    testConversion("'#'");
    testConversion("'~'");
    
    printSubHeader("Invalid char literals");
    testConversion("'ab'");
    testConversion("''");
    testConversion("'");
    testConversion("a");
    testConversion("'abc'");
}

void testIntLiterals() {
    printHeader("TESTING INT LITERALS");
    
    printSubHeader("Valid integers");
    testConversion("0");
    testConversion("42");
    testConversion("-42");
    testConversion("+42");
    testConversion("2147483647");
    testConversion("-2147483648");
    
    printSubHeader("Boundary cases for char conversion");
    testConversion("32");
    testConversion("31");
    testConversion("126");
    testConversion("127");
    testConversion("255");
    testConversion("256");
    testConversion("-1");
    
    printSubHeader("Invalid integers");
    testConversion("abc");
    testConversion("42abc");
    testConversion("42.0");
    testConversion("++42");
    testConversion("--42");
    testConversion("4 2");
}

void testFloatLiterals() {
    printHeader("TESTING FLOAT LITERALS");
    
    printSubHeader("Valid floats");
    testConversion("0.0f");
    testConversion("42.0f");
    testConversion("-42.0f");
    testConversion("+42.5f");
    testConversion("0.5f");
    testConversion("123.456f");
    testConversion("-0.1f");
    testConversion("3.14159f");
    
    printSubHeader("Special float values");
    testConversion("+inff");
    testConversion("-inff");
    testConversion("nanf");
    
    printSubHeader("Invalid floats");
    testConversion("42f");
    testConversion("42.0");
    testConversion(".5f");
    testConversion("42.f");
    testConversion("f");
    testConversion("42.0ff");
    testConversion("inff");
    testConversion("42.0.5f");
}

void testDoubleLiterals() {
    printHeader("TESTING DOUBLE LITERALS");
    
    printSubHeader("Valid doubles");
    testConversion("0.0");
    testConversion("42.0");
    testConversion("-42.0");
    testConversion("+42.5");
    testConversion("0.5");
    testConversion("123.456");
    testConversion("-0.1");
    testConversion("3.14159");
    testConversion("2.71828");
    
    printSubHeader("Special double values");
    testConversion("+inf");
    testConversion("-inf");
    testConversion("nan");
    
    printSubHeader("Invalid doubles");
    testConversion(".5");
    testConversion("42.");
    testConversion("42.0.0");
    testConversion("abc.def");
    testConversion("inf");
    testConversion("42. 5");
}

void testEdgeCases() {
    printHeader("TESTING EDGE CASES");
    
    printSubHeader("Float/Double precision and overflow");
    testConversion("999999999999999999999999999.0f");
    testConversion("0.000000000000000000001f");
    testConversion("999999999999999999999999999.0");
    testConversion("0.000000000000000000001");
    
    printSubHeader("Conversion impossibilities");
    testConversion("300");
    testConversion("-200");
    
    printSubHeader("Mixed valid/invalid formats");
    testConversion("42.0f ");
    testConversion(" 42.0f");
    testConversion("42,0f");
    testConversion("42.0F");
    testConversion("NAN");
    testConversion("INF");
}

void testErrorCases() {
    printHeader("TESTING ERROR CASES");
    
    printSubHeader("Empty and invalid inputs");
    testConversion("");
    testConversion("   ");
    testConversion("hello");
    testConversion("42hello");
    testConversion("hello42");
    
    printSubHeader("Malformed literals");
    testConversion("'");
    testConversion("''a'");
    testConversion("42..0f");
    testConversion("4.2.0");
    testConversion("+-42");
    testConversion("-+42");
    
    printSubHeader("Overflow cases");
    testConversion("99999999999999999999");
    testConversion("-99999999999999999999");
}

void testSpecialScenarios() {
    printHeader("TESTING SPECIAL SCENARIOS");
    
    printSubHeader("Boundary char values using ints");
    testConversion("0");
    testConversion("9");
    testConversion("10");
    testConversion("13");
    testConversion("32");
    testConversion("33");
    testConversion("125");
    testConversion("126");
    testConversion("127");
    
    printSubHeader("Zero variations");
    testConversion("0");
    testConversion("0.0");
    testConversion("0.0f");
    testConversion("+0");
    testConversion("-0");
    testConversion("+0.0");
    testConversion("-0.0");
    testConversion("+0.0f");
    testConversion("-0.0f");
    
    printSubHeader("Decimal precision tests");
    testConversion("42");
    testConversion("42.0");
    testConversion("42.0f");
    testConversion("42.5");
    testConversion("42.5f");
    testConversion("42.999");
    testConversion("42.999f");
}

int main() {
    std::cout << BLUE << "========================================" << RESET << std::endl;
    std::cout << BLUE << "    SCALAR CONVERTER COMPREHENSIVE TEST" << RESET << std::endl;
    std::cout << BLUE << "========================================" << RESET << std::endl;
    
    testCharLiterals();
    testIntLiterals();
    testFloatLiterals();
    testDoubleLiterals();
    testEdgeCases();
    testErrorCases();
    testSpecialScenarios();
    
    std::cout << "\n" << BLUE << "========================================" << RESET << std::endl;
    std::cout << BLUE << "           ALL TESTS COMPLETED" << RESET << std::endl;
    std::cout << BLUE << "========================================" << RESET << std::endl;
    
    return 0;
}