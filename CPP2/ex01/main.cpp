#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    a = Fixed(1234.4321f);

    cout << "a is " << a << "\n" << endl;
    cout << "b is " << b << "\n" << endl;
    cout << "c is " << c << "\n" << endl;
    cout << "d is " << d << "\n" << endl;

    cout << "a as int: " << a.toInt() << "\n" << endl;
    cout << "b as int: " << b.toInt() << "\n" << endl;
    cout << "c as int: " << c.toInt() << "\n" << endl;
    cout << "d as int: " << d.toInt() << "\n" << endl;

    cout << "Raw bits of a: " << a.getRawBits() << "\n" << endl;
    cout << "Raw bits of b: " << b.getRawBits() << "\n" << endl;
    cout << "Raw bits of c: " << c.getRawBits() << "\n" << endl;
    cout << "Raw bits of d: " << d.getRawBits() << "\n" << endl;

    a.setRawBits(42);
    cout << "After setting raw bits of a to 42, a is now: " << a << "\n" << endl;
    cout << "Raw bits of a after setting: " << a.getRawBits() << "\n" << endl;

    cout << "a as float: " << a.toFloat() << "\n" << endl;
    cout << "b as float: " << b.toFloat() << "\n" << endl;
    cout << "c as float: " << c.toFloat() << "\n" << endl;
    cout << "d as float: " << d.toFloat() << "\n" << endl;

    return 0;
}