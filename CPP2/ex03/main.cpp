#include "Point.hpp"

int main(void)
{
    Point   a(5,5);
    Point   b(0,0);
    Point   c(6,0);
    Point  point(3,2);

    if (point.bsp(a,b,c,point))
        std::cout << "This is in." << std::endl;
    else
        std::cout << "This is out." << std::endl;
    return (0);
}