#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        Fixed _x;
        Fixed _y;

        public:
            Point();
            Point(const float x, const float y);
            Point(const Point &other);
            ~Point();

            Point &operator=(const Point &other);

            Fixed getX() const;
            Fixed getY() const;

            bool bsp(const Point a, const Point b, const Point c, Point const point);

            friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

#endif