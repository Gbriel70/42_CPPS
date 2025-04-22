/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:41:49 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/22 16:35:32 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

// MACROS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

// CLASSES
class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string dark_secret;

  public:
	Contact();
	~Contact();

	void setFIrstName(std::string name)
	{
		first_name = name;
	}

	void setLastName(std::string name)
	{
		last_name = name;
	}

	void setNickname(std::string name)
	{
		nickname = name;
	}

	bool setPhoneNumber(std::string number)
	{
		if (!isdigit(number[0]))
		{
			std::cout << RED << "Phone number must start with a digit!" << RESET << std::endl;
			return (false);
		}
		if (number.length() > 15)
		{
			std::cout << RED << "Phone number is too long!" << RESET << std::endl;
			return (false);
		}
		phone_number = number;
		return (true);
	}

	void setDarkSecret(std::string secret)
	{
		dark_secret = secret;
	}

	std::string getFirstName()
	{
		return (first_name);
	}

	std::string getLastName()
	{
		return (last_name);
	}

	std::string getNickname()
	{
		return (nickname);
	}

	std::string getPhoneNumber()
	{
		return (phone_number);
	}

	std::string getDarkSecret()
	{
		return (dark_secret);
	}
};

class PhoneBook
{
  private:
	Contact contacts[8];
	int total_contacts;
	int index;

  public:
	PhoneBook();
	~PhoneBook();

	int getTotalContacts() const
	{
		return (total_contacts);
	}

	void displayContactDetails(int index)
	{
		if (index < 1 || index > total_contacts)
		{
			std::cout << RED << "invalid index!" << RESET << std::endl;
			return ;
		}
		index--;

		std::cout << BLUE << "Contact Details:" << RESET << std::endl;
		std::cout << BLUE << "Name: " << RESET << contacts[index].getFirstName() << std::endl;
		std::cout << BLUE << "Surname: " << RESET << contacts[index].getLastName() << std::endl;
		std::cout << BLUE << "Nickname: " << RESET << contacts[index].getNickname() << std::endl;
		std::cout << BLUE << "Number: " << RESET << contacts[index].getPhoneNumber() << std::endl;
		std::cout << BLUE << "Secret: " << RESET << contacts[index].getDarkSecret() << std::endl;
	}

	void addContact(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number, std::string dark_secret)
	{
		if (!contacts[index].setPhoneNumber(phone_number))
		{
			std::cout << RED << "Contact not added due to invalid data." << RESET << std::endl;
			return ;
		}

		contacts[index].setFIrstName(first_name);
		contacts[index].setLastName(last_name);
		contacts[index].setNickname(nickname);
		contacts[index].setDarkSecret(dark_secret);

		index = (index + 1) % 8;
		if (total_contacts < 8)
			total_contacts++;

		std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
	}

	void searchContact(std::string name)
	{
		for (int i = 0; i < total_contacts; i++)
		{
			if (contacts[i].getFirstName() == name
				|| contacts[i].getLastName() == name
				|| contacts[i].getNickname() == name)
			{
				std::cout << "Contact found: " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << " " << contacts[i].getNickname() << " " << contacts[i].getPhoneNumber() << std::endl;
				return ;
			}
		}
		std::cout << "Contact not found." << std::endl;
	}

	std::string truncate(const std::string &str)
	{
		if (str.length() > 10)
			return (str.substr(0, 9) + ".");
		return (str);
	}

	void displayContacts()
	{
		if (total_contacts == 0)
		{
			std::cout << RED << "No contacts to display!" << RESET << std::endl;
			return ;
		}

		const int index_width = 8;
		const int data_width = 12;
		const int total_width = index_width + data_width * 3 + 5;

		std::cout << GREEN << "+" << std::string(total_width - 2,
			'-') << "+" << RESET << std::endl;

		std::cout << GREEN << "|" << std::setw(index_width) << "Index "
					<< "|" << std::setw(data_width) << "First Name "
					<< "|" << std::setw(data_width) << "Last Name "
					<< "|" << std::setw(data_width) << "Nickname "
					<< "|" << RESET << std::endl;

		std::cout << GREEN << "+" << std::string(total_width - 2,
			'-') << "+" << RESET << std::endl;

		for (int i = 0; i < total_contacts; i++)
		{
			std::cout << GREEN << "|" << RESET;
			std::cout << BLUE << std::setw(index_width) << (i + 1) << RESET;
			std::cout << GREEN << "|" << RESET;
			std::cout << BLUE << std::setw(data_width) << truncate(contacts[i].getFirstName()) << RESET;
			std::cout << GREEN << "|" << RESET;
			std::cout << BLUE << std::setw(data_width) << truncate(contacts[i].getLastName()) << RESET;
			std::cout << GREEN << "|" << RESET;
			std::cout << BLUE << std::setw(data_width) << truncate(contacts[i].getNickname()) << RESET;
			std::cout << GREEN << "|" << RESET << std::endl;
		}

		std::cout << GREEN << "+" << std::string(total_width - 2,
			'-') << "+" << RESET << std::endl;
	}
};