#include "iter.hpp"

void printInt(const int &n) {
    std::cout << n << " ";
}

void printFloat(const float &f) {
    std::cout << f << " ";
}

void printString(const std::string &s) {
    std::cout << s << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    std::string stringArray[] = {"Hello", "World"};

    std::cout << "Integers: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Floats: ";
    iter(floatArray, 3, printFloat);
    std::cout << std::endl;

    std::cout << "Strings: ";
    iter(stringArray, 2, printString);
    std::cout << std::endl;

    return 0;
}
