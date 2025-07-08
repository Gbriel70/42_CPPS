#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->set_name("Bola");
    this->set_hit_points(100);
    this->set_energy_points(50);
    this->set_attack_damage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->set_hit_points(100);
    this->set_energy_points(50);
    this->set_attack_damage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){}

ScavTrap::~ScavTrap(){}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}


void ScavTrap::guardGate()
{
    cout << "ScavTrap " << this->_name << " is now in guard gate mode!" << endl;
    this->_guardMode = true;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        cout << "ScavTrap " << this->_name << " attacks " << target 
             << ", causing " << this->_attackDamage << " points of damage!" << endl;
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
    {
        cout << "ScavTrap " << this->_name << " is out of hit points and cannot attack!" << endl;
    }
    else
    {
        cout << "ScavTrap " << this->_name << " has no energy points left to attack!" << endl;
    }
}