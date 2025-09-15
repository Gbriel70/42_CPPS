/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:26:01 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 11:26:02 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testCompleteWorkflow() {
    std::cout << "\n=== TESTING COMPLETE WORKFLOW ===" << std::endl;
    Intern intern;
    Bureaucrat manager("Manager", 25);
    
    std::string formTypes[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    std::string targets[] = {
        "office",
        "employee",
        "defendant"
    };
    
    for (int i = 0; i < 3; i++) {
        Form* form = intern.makeForm(formTypes[i], targets[i]);
        if (form) {
            std::cout << "\n--- Processing " << formTypes[i] << " ---" << std::endl;
            manager.signForm(*form);
            manager.executeForm(*form);
            delete form;
        }
    }
}

int main(void)
{
    testCompleteWorkflow();
    return 0;
}