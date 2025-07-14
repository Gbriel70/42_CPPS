#include "Brain.hpp"

Brain::Brain() 
{
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Idea " + to_string(i + 1);
    }
}

Brain::Brain(const Brain &other) 
{
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(){}

void Brain::setIdea(int index, const string &idea)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; ++i) {
        cout << "Idea " << i + 1 << ": " << ideas[i] << endl;
    }
}