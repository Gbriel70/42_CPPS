#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("Clappy");

    claptrap.attack("target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(2);
    
    claptrap.attack("target2");
    claptrap.takeDamage(5);
    claptrap.beRepaired(1);

    claptrap.attack("target3");
    claptrap.takeDamage(10);
    
    return 0;
}