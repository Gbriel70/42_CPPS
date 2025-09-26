#ifndef CLASS_HPP
#define CLASS_HPP

#include "Base.hpp"

class ClassA : public Base {
public:
    void display() const {
        std::cout << "ClassA instance" << std::endl;
    }
};

class ClassB : public Base {
public:
    void display() const {
        std::cout << "ClassB instance" << std::endl;
    }
};

class ClassC : public Base {
public:
    void display() const {
        std::cout << "ClassC instance" << std::endl;
    }
};

#endif