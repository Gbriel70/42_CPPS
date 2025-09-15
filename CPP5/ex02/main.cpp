/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:00:53 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 11:01:27 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm() {
    std::cout << "\n=== TESTING SHRUBBERY CREATION FORM ===" << std::endl;
    Bureaucrat gardener("Gardener", 137);
    ShrubberyCreationForm shrubForm("garden");

    gardener.executeForm(shrubForm);
    gardener.signForm(shrubForm);
    gardener.executeForm(shrubForm);
}

void testRobotomyRequestForm() {
    std::cout << "\n=== TESTING ROBOTOMY REQUEST FORM ===" << std::endl;
    Bureaucrat robotomist("Robotomist", 45);
    RobotomyRequestForm roboForm("Bender");

    robotomist.executeForm(roboForm);
    robotomist.signForm(roboForm);
    for (int i = 0; i < 3; ++i)
        robotomist.executeForm(roboForm);
}

void testPresidentialPardonForm() {
    std::cout << "\n=== TESTING PRESIDENTIAL PARDON FORM ===" << std::endl;
    Bureaucrat president("President", 1);
    PresidentialPardonForm pardonForm("Alice");

    president.executeForm(pardonForm);
    president.signForm(pardonForm);
    president.executeForm(pardonForm);
}

void testInsufficientGrade() {
    std::cout << "\n=== TESTING INSUFFICIENT GRADE FOR EXECUTION ===" << std::endl;
    Bureaucrat low("Intern", 150);
    ShrubberyCreationForm shrubForm("tiny");

    low.signForm(shrubForm);
    low.executeForm(shrubForm);
}

int main(void)
{
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testInsufficientGrade();
    return 0;
}