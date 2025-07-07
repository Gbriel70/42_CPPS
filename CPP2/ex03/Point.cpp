#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
}

Point::~Point() {
}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        this->_x = other._x;
        this->_y = other._y;
    }
    return *this;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "Point(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

bool Point::bsp(const Point a, const Point b, const Point c, Point const point)
{
    Fixed ix = a.getX();
	Fixed iy = a.getY();
	Fixed jx = b.getX();
	Fixed jy = b.getY();
	Fixed kx = c.getX();
	Fixed ky = c.getY();

	Fixed pointx = point.getX();
	Fixed pointy = point.getY();
	
    Fixed denominator = (jx - ix) * (ky - iy) - 
                        (jy - iy) * (kx - ix);

    Fixed alpha = ((pointx - ix) * (ky - iy) - 
                   (pointy - iy) * (kx - ix)) / denominator;

    Fixed beta = ((jx - ix) * (pointy - iy) - 
                  (jy - iy) * (pointx - ix)) / denominator;

    Fixed gamma = Fixed(1) - alpha - beta;

    return (alpha > Fixed(0) && beta > Fixed(0) && gamma > Fixed(0));
}