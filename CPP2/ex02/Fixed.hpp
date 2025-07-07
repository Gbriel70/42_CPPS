#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed(const int value);
        Fixed(const float value);

        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;

        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);
        Fixed &operator=(const Fixed &other);

        Fixed operator++(int);
        Fixed operator--(int);
        Fixed &operator++();
        Fixed &operator--();

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

ostream &operator<<(ostream &os, const Fixed &fixed);

#endif