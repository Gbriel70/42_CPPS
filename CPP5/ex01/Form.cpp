/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:00:08 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 13:17:50 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), execGrade(150)
{
    std::cout << "Default Form created: " << YELLOW << name << ", Sign Grade: " << signGrade << ", Exec Grade: " << execGrade << RESET << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooLowException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooHighException();
    isSigned = false;
    std::cout << "Form created: " << YELLOW << name << ", Sign Grade: " << signGrade << ", Exec Grade: " << execGrade << RESET << std::endl;
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
    std::cout << "Form copied: " << YELLOW << name << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    std::cout << "Form assigned: " << YELLOW << name << RESET << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destroyed: " << RED << name << RESET << std::endl;
}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (isSigned) {
        std::cout << "Form " << name << " is already signed!" << std::endl;
        throw std::runtime_error("Form already signed");
    }
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    isSigned = true;
    std::cout << "Form signed: " << name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}


std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getExecGrade();
    return os;
}

Form *tryCreateForm(const std::string &name, int signGrade, int execGrade)
{
    try
    {
        Form *form = new Form(name, signGrade, execGrade);
        std::cout << YELLOW << form->getName() << " created successfully.\n" << RESET << std::endl;
        return form;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Failed to create form: " << e.what() << "\n" << RESET << std::endl;
        return NULL;
    }
}