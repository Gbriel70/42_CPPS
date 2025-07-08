#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool _guardMode;

    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &other);

        void attack(const std::string &target);
        void guardGate();
};



#endif