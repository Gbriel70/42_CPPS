/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:59:43 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 13:05:18 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) 
{
	std::cout << "Bureaucrat created: " << GREEN << name << ", Grade: " << grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) 
{
	if (grade < 1)
		throw std::out_of_range("Grade too low");
	if (grade > 150)
		throw std::out_of_range("Grade too high");
	std::cout << "Bureaucrat created: " << GREEN << name << ", Grade: " << grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) 
{
	std::cout << "Bureaucrat copied: " << GREEN << name << ", Grade: " << grade << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other) {
		grade = other.grade;
		std::cout << "Bureaucrat assigned: " << GREEN << name << ", Grade: " << grade << RESET << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat destroyed: " << RED << name << RESET << std::endl;
}

const std::string& Bureaucrat::getName() const 
{
	return name;
}

int Bureaucrat::getGrade() const 
{
	return grade;
}

int Bureaucrat::setGrade(int newGrade) 
{
	if (newGrade < 1 || newGrade > 150)
		throw std::out_of_range("Invalid grade");
	grade = newGrade;
	return grade;
}

void Bureaucrat::incrementGrade() 
{
	if (getGrade() <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (getGrade() >= 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) 
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void tryCreateBureaucrat(const std::string& name, int grade)
{
	try {
		Bureaucrat b(name, grade);
	} catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}