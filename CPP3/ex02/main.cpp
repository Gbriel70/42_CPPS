#include "FragTrap.hpp"

int main(void)
{
    FragTrap fragtrap("Fraggy");

    fragtrap.attack("target1");
    fragtrap.takeDamage(3);
    fragtrap.beRepaired(2);
    
    fragtrap.attack("target2");
    fragtrap.takeDamage(5);
    fragtrap.beRepaired(1);

    fragtrap.attack("target3");
    fragtrap.takeDamage(10);
    fragtrap.highFivesGuys();
    
    return 0;
}