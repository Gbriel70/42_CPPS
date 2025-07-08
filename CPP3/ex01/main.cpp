#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scavtrap("Scavvy");

    scavtrap.attack("target1");
    scavtrap.takeDamage(3);
    scavtrap.beRepaired(2);
    
    scavtrap.attack("target2");
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(1);

    scavtrap.attack("target3");
    scavtrap.takeDamage(10);
    
    return 0;
}