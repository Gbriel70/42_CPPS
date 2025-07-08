#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    _name = "Default";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string &name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap::~ClapTrap(){}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        cout << "ClapTrap " << _name << " attacks " << target 
             << ", causing " << _attackDamage << " points of damage!" << endl;
    }
    else if (_hitPoints <= 0)
    {
        cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << endl;
    }
    else
    {
        cout << "ClapTrap " << _name << " has no energy points left to attack!" << endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        cout << "ClapTrap " << _name << " has taken too much damage and is destroyed!" << endl;
    }
    else
    {
        _hitPoints -= amount;
        cout << "ClapTrap " << _name << " takes " << amount 
             << " points of damage! Remaining hit points: " << _hitPoints << endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        cout << "ClapTrap " << _name << " repairs itself for " << amount 
             << " hit points! Current hit points: " << _hitPoints 
             << ", Energy points left: " << _energyPoints << endl;
    }
    else if (_hitPoints <= 0)
    {
        cout << "ClapTrap " << _name << " cannot be repaired because it is destroyed!" << endl;
    }
    else
    {
        cout << "ClapTrap " << _name << " has no energy points left to repair!" << endl;
    }
}

void ClapTrap::set_energy_points(int amount)
{
    _energyPoints = amount;
}

void ClapTrap::set_hit_points(int amount)
{
    _hitPoints = amount;
}

void ClapTrap::get_name() const
{
    cout << "ClapTrap name: " << _name << endl;
}

unsigned int ClapTrap::get_energy_points() const
{
    return _energyPoints;
}

unsigned int ClapTrap::get_hit_points() const
{
    return _hitPoints;
}

unsigned int ClapTrap::get_attack_damage() const
{
    return _attackDamage;
}
