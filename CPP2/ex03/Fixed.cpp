#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) 
{
}

Fixed::Fixed(const Fixed &other): _fixedPointValue(other._fixedPointValue)
{
}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBits;
}

int Fixed::toInt() const
{
    return _fixedPointValue >> _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (_fixedPointValue / (float)(1 << _fractionalBits));
}

Fixed Fixed::operator+(const Fixed &other)
{
    return Fixed((this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)
{
    if (other._fixedPointValue == 0)
    {
        cout << "Error: Division by zero" << endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _fixedPointValue++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _fixedPointValue--;
    return tmp;
}

Fixed &Fixed::operator++()
{
    ++_fixedPointValue;
    return *this;
}

Fixed &Fixed::operator--()
{
    --_fixedPointValue;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_fixedPointValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_fixedPointValue != other.getRawBits();
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

int Fixed::getRawBits() const
{
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

Fixed::~Fixed()
{
}