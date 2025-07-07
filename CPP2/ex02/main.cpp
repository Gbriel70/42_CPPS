#include "Fixed.hpp"

int main(void)
{

    Fixed a;
    Fixed b(a);
    Fixed c;

    a = Fixed(5.05f);
    b = Fixed(2);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "a to int: " << a.toInt() << endl;
    cout << "b to float: " << b.toFloat() << endl;

    cout << "a + b: " << (a + b) << endl;
    cout << "a - b: " << (a - b) << endl;
    cout << "a * b: " << (a * b) << endl;
    cout << "a / b: " << (a / b) << endl;

    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    cout << "min(a, b): " << Fixed::min(a, b) << endl;
    cout << "max(a, b): " << Fixed::max(a, b) << endl;
    cout << "min(const a, const b): " << Fixed::min(a, b) << endl;
    cout << "max(const a, const b): " << Fixed::max(a, b) << endl;

    cout << "Incrementing a: " << ++a << endl;
    cout << "a after increment: " << a << endl;

    cout << "Decrementing b: " << --b << endl;
    cout << "b after decrement: " << b << endl;

    cout << "Post-increment a: " << a++ << endl;
    cout << "a after post-increment: " << a << endl;

    cout << "Post-decrement b: " << b-- << endl;
    cout << "b after post-decrement: " << b << endl;


    return 0;
}