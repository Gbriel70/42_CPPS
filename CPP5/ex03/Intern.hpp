/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:09:28 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/09/15 11:13:14 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
  public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	Form *makeForm(const std::string &formName, const std::string &target) const;

  private:
	Form *createShrubberyCreationForm(const std::string &target) const
	{
		return new ShrubberyCreationForm(target);
	}
	Form *createRobotomyRequestForm(const std::string &target) const
	{
		return new RobotomyRequestForm(target);
	}
	Form *createPresidentialPardonForm(const std::string &target) const
	{
		return new PresidentialPardonForm(target);
	}
};

#endif