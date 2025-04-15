#include "PhoneBook.hpp"

Contact::Contact() 
{
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    dark_secret = "";
}

Contact::~Contact() 
{
    return;
}

PhoneBook::PhoneBook() 
{
    total_contacts = 0;
    index = 0;
}

PhoneBook::~PhoneBook() 
{
    return;
}

void convert(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
}

int main(void)
{
    PhoneBook phonebook;

    while (1)
    {
        std::string command;
        std::cout << MAGENTA << "Enter command (ADD, SEARCH, EXIT): " << RESET;

        if (!std::getline(std::cin, command))
        {
            std::cout << RED << "\nEnd of input detected. Exiting program." << RESET << std::endl;
            break;
        }
        convert(command);

        if (command == "ADD")
        {
            std::string first_name, last_name, nickname, phone_number;
            std::cout << MAGENTA << "Enter first name: " << RESET;
            std::getline(std::cin, first_name);
            std::cout << MAGENTA << "Enter last name: " << RESET;
            std::getline(std::cin, last_name);
            std::cout << MAGENTA << "Enter nickname: " << RESET;
            std::getline(std::cin, nickname);
            std::cout << MAGENTA << "Enter phone number: " << RESET;
            std::getline(std::cin, phone_number);
            std::string dark_secret;
            std::cout << MAGENTA << "Enter dark secret: " << RESET;
            std::getline(std::cin, dark_secret);
            phonebook.addContact(first_name, last_name, nickname, phone_number, dark_secret);
        }

        else if (command == "SEARCH")
            phonebook.displayContacts();

        else if (command == "EXIT")
            break;

        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}