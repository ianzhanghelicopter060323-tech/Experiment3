#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"


class Rectangle
{
    public:
        Rectangle();
        Rectangle(const Point &p1_in, const Point &p2_in);
        Rectangle(const Rectangle &r);

        double Rectangle_width() const;
        double Rectangle_height() const;
        double Rectangle_area() const;
        double Rectangle_perimeter() const;

    private:
        Point p1;
        Point p2;
};

#endif
