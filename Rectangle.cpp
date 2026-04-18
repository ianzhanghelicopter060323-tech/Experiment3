#include <iostream>
#include <cmath>
#include "Rectangle.h"


Rectangle::Rectangle(): p1(0.0, 0.0), p2(0.0, 0.0)
{

}

Rectangle::Rectangle(const Point &p1_in, const Point &p2_in): p1(p1_in), p2(p2_in)
{

}

Rectangle::Rectangle(const Rectangle &r): p1(r.p1), p2(r.p2)
{

}

double Rectangle::Rectangle_width() const
{
    return fabs(p1.x - p2.x);
}

double Rectangle::Rectangle_height() const
{
    return fabs(p1.y - p2.y);
}

double Rectangle::Rectangle_area() const
{
    return Rectangle_width() * Rectangle_height();
}

double Rectangle::Rectangle_perimeter() const
{
    return 2.0 * (Rectangle_width() + Rectangle_height());
}
