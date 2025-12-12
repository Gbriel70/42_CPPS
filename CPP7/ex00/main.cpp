/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:23:41 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/12/12 11:23:41 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include "whatever.hpp"
#include <iostream>
#include <string>

void printHeader(const std::string& title) {
    std::cout << "\n" << "==== " << title << " ====" << std::endl;
}

void printSubHeader(const std::string& subtitle) {
    std::cout << "\n" << "--- " << subtitle << " ---" << std::endl;
}

void testSwapInts() {
    printHeader("TESTING SWAP WITH INTEGERS");
    
    int a = 42;
    int b = 24;
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    
    // Test with negative numbers
    int c = -10;
    int d = 100;
    
    std::cout << "\nBefore swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
    
    // Test with zero
    int e = 0;
    int f = 999;
    
    std::cout << "\nBefore swap: e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After swap:  e = " << e << ", f = " << f << std::endl;
}

void testSwapFloats() {
    printHeader("TESTING SWAP WITH FLOATS");
    
    float a = 3.14f;
    float b = 2.71f;
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    
    // Test with negative floats
    float c = -1.5f;
    float d = 0.5f;
    
    std::cout << "\nBefore swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
}

void testSwapStrings() {
    printHeader("TESTING SWAP WITH STRINGS");
    
    std::string a = "Hello";
    std::string b = "World";
    
    std::cout << "Before swap: a = \"" << a << "\", b = \"" << b << "\"" << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = \"" << a << "\", b = \"" << b << "\"" << std::endl;
    
    // Test with empty string
    std::string c = "";
    std::string d = "Non-empty";
    
    std::cout << "\nBefore swap: c = \"" << c << "\", d = \"" << d << "\"" << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = \"" << c << "\", d = \"" << d << "\"" << std::endl;
}

void testSwapChars() {
    printHeader("TESTING SWAP WITH CHARS");
    
    char a = 'A';
    char b = 'Z';
    
    std::cout << "Before swap: a = '" << a << "', b = '" << b << "'" << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  a = '" << a << "', b = '" << b << "'" << std::endl;
}

void testMinInts() {
    printHeader("TESTING MIN WITH INTEGERS");
    
    int a = 42;
    int b = 24;
    
    std::cout << "min(" << a << ", " << b << ") = " << ::min(a, b) << std::endl;
    std::cout << "min(" << b << ", " << a << ") = " << ::min(b, a) << std::endl;
    
    // Test with equal values
    int c = 100;
    int d = 100;
    
    std::cout << "min(" << c << ", " << d << ") = " << ::min(c, d) << std::endl;
    
    // Test with negative numbers
    int e = -50;
    int f = -20;
    
    std::cout << "min(" << e << ", " << f << ") = " << ::min(e, f) << std::endl;
    
    // Test with zero
    int g = 0;
    int h = -1;
    
    std::cout << "min(" << g << ", " << h << ") = " << ::min(g, h) << std::endl;
}

void testMinFloats() {
    printHeader("TESTING MIN WITH FLOATS");
    
    float a = 3.14f;
    float b = 2.71f;
    
    std::cout << "min(" << a << ", " << b << ") = " << ::min(a, b) << std::endl;
    
    // Test with very close values
    float c = 1.000001f;
    float d = 1.000002f;
    
    std::cout << "min(" << c << ", " << d << ") = " << ::min(c, d) << std::endl;
    
    // Test with negative floats
    float e = -1.5f;
    float f = -1.6f;
    
    std::cout << "min(" << e << ", " << f << ") = " << ::min(e, f) << std::endl;
}

void testMinStrings() {
    printHeader("TESTING MIN WITH STRINGS");
    
    std::string a = "apple";
    std::string b = "banana";
    
    std::cout << "min(\"" << a << "\", \"" << b << "\") = \"" << ::min(a, b) << "\"" << std::endl;
    
    // Test with same strings
    std::string c = "same";
    std::string d = "same";
    
    std::cout << "min(\"" << c << "\", \"" << d << "\") = \"" << ::min(c, d) << "\"" << std::endl;
    
    // Test with empty string
    std::string e = "";
    std::string f = "non-empty";
    
    std::cout << "min(\"" << e << "\", \"" << f << "\") = \"" << ::min(e, f) << "\"" << std::endl;
    
    // Test case sensitivity
    std::string g = "Apple";
    std::string h = "apple";
    
    std::cout << "min(\"" << g << "\", \"" << h << "\") = \"" << ::min(g, h) << "\"" << std::endl;
}

void testMinChars() {
    printHeader("TESTING MIN WITH CHARS");
    
    char a = 'Z';
    char b = 'A';
    
    std::cout << "min('" << a << "', '" << b << "') = '" << ::min(a, b) << "'" << std::endl;
    
    // Test with numbers
    char c = '5';
    char d = '3';
    
    std::cout << "min('" << c << "', '" << d << "') = '" << ::min(c, d) << "'" << std::endl;
    
    // Test with same chars
    char e = 'X';
    char f = 'X';
    
    std::cout << "min('" << e << "', '" << f << "') = '" << ::min(e, f) << "'" << std::endl;
}

void testMaxInts() {
    printHeader("TESTING MAX WITH INTEGERS");
    
    int a = 42;
    int b = 24;
    
    std::cout << "max(" << a << ", " << b << ") = " << ::max(a, b) << std::endl;
    std::cout << "max(" << b << ", " << a << ") = " << ::max(b, a) << std::endl;
    
    // Test with equal values
    int c = 100;
    int d = 100;
    
    std::cout << "max(" << c << ", " << d << ") = " << ::max(c, d) << std::endl;
    
    // Test with negative numbers
    int e = -50;
    int f = -20;
    
    std::cout << "max(" << e << ", " << f << ") = " << ::max(e, f) << std::endl;
    
    // Test with zero
    int g = 0;
    int h = -1;
    
    std::cout << "max(" << g << ", " << h << ") = " << ::max(g, h) << std::endl;
}

void testMaxFloats() {
    printHeader("TESTING MAX WITH FLOATS");
    
    float a = 3.14f;
    float b = 2.71f;
    
    std::cout << "max(" << a << ", " << b << ") = " << ::max(a, b) << std::endl;
    
    // Test with very close values
    float c = 1.000001f;
    float d = 1.000002f;
    
    std::cout << "max(" << c << ", " << d << ") = " << ::max(c, d) << std::endl;
    
    // Test with negative floats
    float e = -1.5f;
    float f = -1.6f;
    
    std::cout << "max(" << e << ", " << f << ") = " << ::max(e, f) << std::endl;
}

void testMaxStrings() {
    printHeader("TESTING MAX WITH STRINGS");
    
    std::string a = "apple";
    std::string b = "banana";
    
    std::cout << "max(\"" << a << "\", \"" << b << "\") = \"" << ::max(a, b) << "\"" << std::endl;
    
    // Test with same strings
    std::string c = "same";
    std::string d = "same";
    
    std::cout << "max(\"" << c << "\", \"" << d << "\") = \"" << ::max(c, d) << "\"" << std::endl;
    
    // Test with different lengths
    std::string e = "short";
    std::string f = "verylongstring";
    
    std::cout << "max(\"" << e << "\", \"" << f << "\") = \"" << ::max(e, f) << "\"" << std::endl;
    
    // Test case sensitivity
    std::string g = "Apple";
    std::string h = "apple";
    
    std::cout << "max(\"" << g << "\", \"" << h << "\") = \"" << ::max(g, h) << "\"" << std::endl;
}

void testMaxChars() {
    printHeader("TESTING MAX WITH CHARS");
    
    char a = 'A';
    char b = 'Z';
    
    std::cout << "max('" << a << "', '" << b << "') = '" << ::max(a, b) << "'" << std::endl;
    
    // Test with numbers
    char c = '3';
    char d = '9';
    
    std::cout << "max('" << c << "', '" << d << "') = '" << ::max(c, d) << "'" << std::endl;
    
    // Test with same chars
    char e = 'X';
    char f = 'X';
    
    std::cout << "max('" << e << "', '" << f << "') = '" << ::max(e, f) << "'" << std::endl;
}

void testSubjectExample() {
    printHeader("TESTING SUBJECT EXAMPLE");
    
    int a = 2;
    int b = 3;
    
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
}

void testEdgeCases() {
    printHeader("TESTING EDGE CASES");
    
    printSubHeader("Equal values behavior");
    
    int equal1 = 5;
    int equal2 = 5;
    
    std::cout << "For equal values (5, 5):" << std::endl;
    std::cout << "min should return first parameter: " << ::min(equal1, equal2) << std::endl;
    std::cout << "max should return first parameter: " << ::max(equal1, equal2) << std::endl;
    
    printSubHeader("Extreme values");
    
    int maxInt = 2147483647;
    int minInt = -2147483648;
    
    std::cout << "min(" << maxInt << ", " << minInt << ") = " << ::min(maxInt, minInt) << std::endl;
    std::cout << "max(" << maxInt << ", " << minInt << ") = " << ::max(maxInt, minInt) << std::endl;
    
    printSubHeader("Very long strings");
    
    std::string longStr1 = "This is a very long string for testing purposes";
    std::string longStr2 = "This is another very long string for testing";
    
    std::cout << "min(long1, long2) first 20 chars: " << ::min(longStr1, longStr2).substr(0, 20) << "..." << std::endl;
    std::cout << "max(long1, long2) first 20 chars: " << ::max(longStr1, longStr2).substr(0, 20) << "..." << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "    TEMPLATE FUNCTIONS TESTING SUITE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Test all swap functions
    testSwapInts();
    testSwapFloats();
    testSwapStrings();
    testSwapChars();
    
    // Test all min functions
    testMinInts();
    testMinFloats();
    testMinStrings();
    testMinChars();
    
    // Test all max functions
    testMaxInts();
    testMaxFloats();
    testMaxStrings();
    testMaxChars();
    
    // Test subject example
    testSubjectExample();
    
    // Test edge cases
    testEdgeCases();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "           ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}