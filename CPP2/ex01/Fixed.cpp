#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) 
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &other): _fixedPointValue(other._fixedPointValue)
{
    cout << "Copy constructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    cout << "Copy assignment operator called" << endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::Fixed(const int value)
{
    cout << "Int constructor called" << endl;
    _fixedPointValue = value << _fractionalBits;
}

int Fixed::toInt() const
{
    return _fixedPointValue >> _fractionalBits;
}

Fixed::Fixed(const float value)
{
    cout << "Float constructor called" << endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::getRawBits() const
{
    cout << "getRawBits member function called" << endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

ostream &operator<<(ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}