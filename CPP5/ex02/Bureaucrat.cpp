#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(class Form &form) const 
{
	try {
		form.beSigned(*this);
		std::cout << GREEN << name << " signed " << form.getName() << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
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

Bureaucrat* tryCreateBureaucrat(const std::string& name, int grade)
{
	try {
		Bureaucrat* bureaucrat = new Bureaucrat(name, grade);
		std::cout << GREEN << *bureaucrat << "\n" << RESET << std::endl;
		return bureaucrat;
	} catch (const std::exception& e) {
		std::cerr << RED << "Error creating Bureaucrat: " << e.what() << "\n" << RESET << std::endl;
		return NULL;
	}
}