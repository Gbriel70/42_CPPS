/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:25:56 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 11:25:57 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copied" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern assigned" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	typedef Form* (Intern::*FormCreator)(const std::string &target) const;

	FormCreator creators[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*creators[i])(target);
		}
	}

	std::cout << "Error: Unknown form name '" << formName << "'." << std::endl;
	return NULL;
}
