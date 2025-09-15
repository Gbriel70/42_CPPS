/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:59:50 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 11:41:41 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testIncrementGrade() {
    std::cout << "\n=== TESTING INCREMENT GRADE ===" << std::endl;
    
    try {
        Bureaucrat b("John", 50);
        std::cout << b << std::endl;
        
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
        
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testDecrementGrade() {
    std::cout << "\n=== TESTING DECREMENT GRADE ===" << std::endl;
    
    try {
        Bureaucrat b("Jane", 50);
        std::cout << b << std::endl;
        
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
        
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testIncrementBoundary() {
    std::cout << "\n=== TESTING INCREMENT BOUNDARY (GRADE 1) ===" << std::endl;
    
    try {
        Bureaucrat b("CEO", 2);
        std::cout << b << std::endl;
        
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
        
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testDecrementBoundary() {
    std::cout << "\n=== TESTING DECREMENT BOUNDARY (GRADE 150) ===" << std::endl;
    
    try {
        Bureaucrat b("Intern", 149);
        std::cout << b << std::endl;
        
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
        
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testMultipleOperations() {
    std::cout << "\n=== TESTING MULTIPLE OPERATIONS ===" << std::endl;
    
    try {
        Bureaucrat b("Manager", 75);
        std::cout << "Initial: " << b << std::endl;
        
        for (int i = 0; i < 5; i++) {
            b.incrementGrade();
            std::cout << "After increment " << (i+1) << ": " << b << std::endl;
        }
        
        for (int i = 0; i < 10; i++) {
            b.decrementGrade();
            std::cout << "After decrement " << (i+1) << ": " << b << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

int main()
{
	tryCreateBureaucrat("A", 13);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("B", 150);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("C", 0);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("D", 500);

	testIncrementGrade();
    testDecrementGrade();
    testIncrementBoundary();
    testDecrementBoundary();
    testMultipleOperations();
	
	return 0;
}
