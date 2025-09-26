#include "function.hpp"
#include "Class.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

static bool seedInitialized = false;

Base* generate(void) {
    if (!seedInitialized) {
        std::srand(std::time(0));
        seedInitialized = true;
        std::cout << "Random seed initialized with: " << std::time(0) << std::endl;
    }
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated: A (random=" << random << ")" << std::endl;
            return new ClassA();
        case 1:
            std::cout << "Generated: B (random=" << random << ")" << std::endl;
            return new ClassB();
        case 2:
            std::cout << "Generated: C (random=" << random << ")" << std::endl;
            return new ClassC();
        default:
            return new ClassA();
    }
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Identified: NULL pointer" << std::endl;
        return;
    }
    
    std::cout << "Identify by pointer: ";
    
    if (dynamic_cast<ClassA*>(p)) {
        std::cout << "ClassA" << std::endl;
    } else if (dynamic_cast<ClassB*>(p)) {
        std::cout << "ClassB" << std::endl;
    } else if (dynamic_cast<ClassC*>(p)) {
        std::cout << "ClassC" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    std::cout << "Identify by reference: ";
    
    try {
        dynamic_cast<ClassA&>(p);
        std::cout << "ClassA" << std::endl;
        return;
    } catch (const std::bad_cast&) {
    }
    
    try {
        dynamic_cast<ClassB&>(p);
        std::cout << "ClassB" << std::endl;
        return;
    } catch (const std::bad_cast&) {
    }
    
    try {
        dynamic_cast<ClassC&>(p);
        std::cout << "ClassC" << std::endl;
        return;
    } catch (const std::bad_cast&) {
    }
    
    std::cout << "Unknown type" << std::endl;
}