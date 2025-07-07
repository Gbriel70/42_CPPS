#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
using namespace std;

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed() = default;
        Fixed(const int value);
        Fixed(const float value);

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
};

ostream &operator<<(ostream &os, const Fixed &fixed);

#endif