#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Brain
{
    private:
        array<string, 100> ideas;

    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();

        void setIdea(int index, const string &idea);
        void printIdeas() const;
};

#endif