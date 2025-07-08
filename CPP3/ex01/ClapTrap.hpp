#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

using namespace std;

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(const string &name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap();    
        ClapTrap &operator=(const ClapTrap &other);

        void attack(const string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void set_energy_points(int amount);
        void set_hit_points(int amount);
        void set_attack_damage(int amount);
        void set_name(const string &name);

        void get_name() const;
        unsigned int get_energy_points() const;
        unsigned int get_hit_points() const;
        unsigned int get_attack_damage() const;
};

#endif