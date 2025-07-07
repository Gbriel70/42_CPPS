#include "Fixed.hpp"

Fixed::Fixed(): _fixedPointValue(0) 
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &other): _fixedPointValue(other._fixedPointValue)
{
    cout << "Copy constructor called" << endl;
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

Fixed Fixed::operator+(const Fixed &other)
{
    cout << "addition operator called" << endl;
    return Fixed((this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
    cout << "subtraction operator called" << endl;
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
    cout << "multiplication operator called" << endl;
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)
{
    cout << "division operator called" << endl;
    if (other._fixedPointValue == 0)
    {
        cout << "Error: Division by zero" << endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator=(const Fixed &other)
{
    cout << "operator= called" << endl;
    if (this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    cout << "postfix increment operator called" << endl;
    Fixed tmp(*this);
    _fixedPointValue++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    cout << "postfix decrement operator called" << endl;
    Fixed tmp(*this);
    _fixedPointValue--;
    return tmp;
}

Fixed &Fixed::operator++()
{
    cout << "prefix increment operator called" << endl;
    ++_fixedPointValue;
    return *this;
}

Fixed &Fixed::operator--()
{
    cout << "prefix decrement operator called" << endl;
    --_fixedPointValue;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    cout << "greater than operator called" << endl;
    return this->_fixedPointValue > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    cout << "less than operator called" << endl;
    return this->_fixedPointValue < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    cout << "greater than or equal operator called" << endl;
    return this->_fixedPointValue >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    cout << "less than or equal operator called" << endl;
    return this->_fixedPointValue <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    cout << "equal operator called" << endl;
    return this->_fixedPointValue == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    cout << "not equal operator called" << endl;
    return this->_fixedPointValue != other.getRawBits();
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    cout << "min function called" << endl;
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    cout << "const min function called" << endl;
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    cout << "max function called" << endl;
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    cout << "const max function called" << endl;
    if (a > b)
        return a;
    return b;
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

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}