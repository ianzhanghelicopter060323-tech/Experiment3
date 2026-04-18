#include "Point.h"


Point::Point():  x(0.0), y(0.0)
{

}

Point::Point(double x, double y): x(x), y(y)
{

}

Point::Point(const Point &p): x(p.x), y(p.y)
{

}

void Point::Point_Input(double x_in, double y_in)
{
    x = x_in;
    y = y_in;
}

double Point::Point_xOut() const
{
    return x;
}

double Point::Point_yOut() const
{
    return y;
}