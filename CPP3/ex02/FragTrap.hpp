#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using namespace std;

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const string &name);
        FragTrap(const FragTrap &other);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &other);

        void attack(const string &target);
        void highFivesGuys();
};

#endif