/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:24:08 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/12/12 11:24:16 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

void printHeader(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

void printSubHeader(const std::string& subtitle) {
    std::cout << "\n--- " << subtitle << " ---" << std::endl;
}

void testDefaultConstructor() {
    printHeader("TESTING DEFAULT CONSTRUCTOR");
    
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    Array<std::string> emptyStringArray;
    std::cout << "Empty string array size: " << emptyStringArray.size() << std::endl;
}

void testParameterizedConstructor() {
    printHeader("TESTING PARAMETERIZED CONSTRUCTOR");
    
    printSubHeader("Integer arrays");
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    printSubHeader("String arrays");
    Array<std::string> stringArray(3);
    std::cout << "String array size: " << stringArray.size() << std::endl;
    std::cout << "Default string values: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << "\"" << stringArray[i] << "\" ";
    }
    std::cout << std::endl;
    
    printSubHeader("Float arrays");
    Array<float> floatArray(4);
    std::cout << "Float array size: " << floatArray.size() << std::endl;
    std::cout << "Default float values: ";
    for (unsigned int i = 0; i < floatArray.size(); i++) {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl;
}

void testCopyConstructor() {
    printHeader("TESTING COPY CONSTRUCTOR");
    
    printSubHeader("Copying integer array");
    Array<int> original(5);
    
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i * 10;
    }
    
    std::cout << "Original array: ";
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    Array<int> copy(original);
    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl;
    
    original[0] = 999;
    std::cout << "After modifying original[0] = 999:" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should be unchanged)" << std::endl;
}

void testAssignmentOperator() {
    printHeader("TESTING ASSIGNMENT OPERATOR");
    
    Array<int> array1(3);
    Array<int> array2(5);
    
    for (unsigned int i = 0; i < array1.size(); i++) {
        array1[i] = i + 1;
    }
    
    for (unsigned int i = 0; i < array2.size(); i++) {
        array2[i] = (i + 1) * 100;
    }
    
    std::cout << "Array1 before assignment (size " << array1.size() << "): ";
    for (unsigned int i = 0; i < array1.size(); i++) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Array2 before assignment (size " << array2.size() << "): ";
    for (unsigned int i = 0; i < array2.size(); i++) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;
    
    array1 = array2;
    
    std::cout << "Array1 after array1 = array2 (size " << array1.size() << "): ";
    for (unsigned int i = 0; i < array1.size(); i++) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    
    array2[0] = 777;
    std::cout << "After modifying array2[0] = 777:" << std::endl;
    std::cout << "Array1[0]: " << array1[0] << " (should be unchanged)" << std::endl;
    std::cout << "Array2[0]: " << array2[0] << std::endl;
}

void testSubscriptOperator() {
    printHeader("TESTING SUBSCRIPT OPERATOR");
    
    Array<int> array(5);
    
    printSubHeader("Writing to array");
    for (unsigned int i = 0; i < array.size(); i++) {
        array[i] = i * i;
    }
    
    printSubHeader("Reading from array");
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
    
    printSubHeader("Const array access");
    const Array<int> constArray(array);
    std::cout << "Const array values: ";
    for (unsigned int i = 0; i < constArray.size(); i++) {
        std::cout << constArray[i] << " ";
    }
    std::cout << std::endl;
}

void testOutOfBoundsAccess() {
    printHeader("TESTING OUT OF BOUNDS ACCESS");
    
    Array<int> array(3);
    
    std::cout << "Array size: " << array.size() << std::endl;
    std::cout << "Valid indices: 0, 1, 2" << std::endl;
    
    printSubHeader("Testing valid access");
    try {
        array[0] = 10;
        array[1] = 20;
        array[2] = 30;
        std::cout << "✅ Valid access successful" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "❌ Unexpected exception on valid access: " << e.what() << std::endl;
    }
    
    printSubHeader("Testing invalid access - index too high");
    try {
        std::cout << "Attempting to access array[3]..." << std::endl;
        array[3] = 40;
        std::cout << "❌ ERROR: Should have thrown exception!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }
    
    printSubHeader("Testing invalid access - negative index (if using signed int)");
    try {
        std::cout << "Attempting to access array[-1]..." << std::endl;
        std::cout << "Note: Negative index test skipped (using unsigned int)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ Exception caught: " << e.what() << std::endl;
    }
    
    printSubHeader("Testing const array out of bounds");
    const Array<int> constArray(array);
    try {
        std::cout << "Attempting to read constArray[5]..." << std::endl;
        int value = constArray[5];
        std::cout << "❌ ERROR: Should have thrown exception! Got value: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "✅ Exception caught on const access: " << e.what() << std::endl;
    }
}

void testDifferentTypes() {
    printHeader("TESTING DIFFERENT TYPES");
    
    printSubHeader("String array");
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Template";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << "\"" << stringArray[i] << "\" ";
    }
    std::cout << std::endl;
    
    printSubHeader("Float array");
    Array<float> floatArray(4);
    floatArray[0] = 3.14f;
    floatArray[1] = 2.71f;
    floatArray[2] = 1.41f;
    floatArray[3] = 1.73f;
    
    std::cout << "Float array: ";
    for (unsigned int i = 0; i < floatArray.size(); i++) {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl;
    
    printSubHeader("Character array");
    Array<char> charArray(5);
    charArray[0] = 'H';
    charArray[1] = 'e';
    charArray[2] = 'l';
    charArray[3] = 'l';
    charArray[4] = 'o';
    
    std::cout << "Character array: ";
    for (unsigned int i = 0; i < charArray.size(); i++) {
        std::cout << charArray[i];
    }
    std::cout << std::endl;
}

void testSizeMethod() {
    printHeader("TESTING SIZE METHOD");
    
    Array<int> array0;
    Array<int> array1(1);
    Array<int> array10(10);
    Array<int> array100(100);
    
    std::cout << "Empty array size: " << array0.size() << std::endl;
    std::cout << "Array(1) size: " << array1.size() << std::endl;
    std::cout << "Array(10) size: " << array10.size() << std::endl;
    std::cout << "Array(100) size: " << array100.size() << std::endl;
}

void testLargeArrays() {
    printHeader("TESTING LARGE ARRAYS");
    
    printSubHeader("Creating large array");
    Array<int> largeArray(1000);
    std::cout << "Large array size: " << largeArray.size() << std::endl;
    
    printSubHeader("Filling large array");
    for (unsigned int i = 0; i < largeArray.size(); i++) {
        largeArray[i] = i;
    }
    
    std::cout << "First 10 elements: ";
    for (unsigned int i = 0; i < 10; i++) {
        std::cout << largeArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Last 10 elements: ";
    for (unsigned int i = largeArray.size() - 10; i < largeArray.size(); i++) {
        std::cout << largeArray[i] << " ";
    }
    std::cout << std::endl;
}

void testSubjectExample() {
    printHeader("TESTING SUBJECT EXAMPLE");
    
    Array<int> numbers(5);
    
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i;
    }
    
    std::cout << "Original array: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    
    std::cout << "After copy constructor: ";
    for (unsigned int i = 0; i < test.size(); i++) {
        std::cout << test[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "      ARRAY TEMPLATE TESTING SUITE" << std::endl;
    std::cout << "========================================" << std::endl;
    
    try {
        testDefaultConstructor();
        testParameterizedConstructor();
        testCopyConstructor();
        testAssignmentOperator();
        testSubscriptOperator();
        testSizeMethod();
        testDifferentTypes();
        testLargeArrays();
        testSubjectExample();        
        testOutOfBoundsAccess();
        
    } catch (const std::exception& e) {
        std::cout << "❌ Unexpected exception in main: " << e.what() << std::endl;
    }
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "           ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}