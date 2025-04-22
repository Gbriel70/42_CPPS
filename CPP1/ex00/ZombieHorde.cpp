#include "Zombie.hpp"

Zombie* ZombieHorde(int x, std::string name)
{
    Zombie* horde = new Zombie[x];

    for (int i = 0; i < x; i++)
        horde[i].reName(name);
    return (horde);
}