#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Zombie
{
    private:
        string _name;
    public:

        Zombie();
            Zombie(string name);
        ~Zombie();

        void announce();
        void reName(string name);
};

Zombie* ZombieHorde(int x, std::string name);

#endif