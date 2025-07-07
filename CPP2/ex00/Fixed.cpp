#include "Fixed.hpp"


Fixed::Fixed() : _fixedPointValue(0) 
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &other)
{
    cout << "Copy constructor called" << endl;
    this->_fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    cout << "Copy assignment operator called" << endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
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