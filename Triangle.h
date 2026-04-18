#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Point.h"
using namespace std;

#define EPSILON  1e-9

class Triangle
{
    public:
        Triangle();
        Triangle(const Point &p1_in, const Point &p2_in, const Point &p3_in);
        Triangle(const Triangle &t);

        double Triangle_lenth() const; //side length calculate
        double Triangle_size() const; //size calculate

    private:
        double Triangle_lenthFromPoints(const Point &p1_in, const Point &p2_in, const Point &p3_in) const;
        double Triangle_sizeFromPoints(const Point &p1_in, const Point &p2_in, const Point &p3_in) const;

        Point p1;
        Point p2;
        Point p3;
        double len; //side length of the Triangle
};
#endif