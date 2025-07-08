#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_name = "DefaultFragTrap";
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
}

FragTrap::FragTrap(const string &name) : ClapTrap(name)
{
    this->_name = name;
    this->set_hit_points(100);
    this->set_energy_points(100);
    this->set_attack_damage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap " << this->_name << " is destroyed!" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

void FragTrap::attack(const string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        cout << "FragTrap " << this->_name << " attacks " << target 
             << ", causing " << this->_attackDamage << " points of damage!" << endl;
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
    {
        cout << "FragTrap " << this->_name << " is out of hit points and cannot attack!" << endl;
    }
    else
    {
        cout << "FragTrap " << this->_name << " has no energy points left to attack!" << endl;
    }
}

void FragTrap::highFivesGuys()
{
    cout << "FragTrap " << this->_name << " requests a high five!" << endl;
}