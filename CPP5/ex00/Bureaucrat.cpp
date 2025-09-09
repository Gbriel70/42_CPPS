#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) 
{
	std::cout << "Bureaucrat created: " << GREEN << name << ", Grade: " << grade << RESET << std::endl;
	if (grade < 1)
	throw std::out_of_range("Grade too low");
	if (grade > 150)
	throw std::out_of_range("Grade too high");
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
	setGrade(getGrade() + 1);
}

void Bureaucrat::decrementGrade() 
{
	setGrade(getGrade() - 1);
}

void tryCreateBureaucrat(const std::string& name, int grade)
{
	try {
		Bureaucrat b(name, grade);
	} catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}