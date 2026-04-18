#include <iostream>
#include <cmath>
#include "Point.h"
#include "Triangle.h"
using namespace std;


Triangle::Triangle(): p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0), len(0.0)
{

}

Triangle::Triangle(const Point &p1_in, const Point &p2_in, const Point &p3_in): p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0), len(0.0)
{

    double size = Triangle_sizeFromPoints(p1_in, p2_in, p3_in);
    if (fabs(size) < EPSILON) //point1, 2, 3 inline with each other, cannot form a triangle
    {
        cout<<"ERROR: these three points cannot form a triangle"<<endl;
    }
    else
    {
        p1 = p1_in;
        p2 = p2_in;
        p3 = p3_in;
        len = Triangle_lenthFromPoints(p1, p2, p3);
    }
}

Triangle::Triangle(const Triangle &t): p1(t.p1), p2(t.p2), p3(t.p3), len(t.len)  
{

}


double Triangle::Triangle_lenth(void) const
{
    return len;
}
       
double Triangle::Triangle_size(void) const
{
    return Triangle_sizeFromPoints(p1, p2, p3);
}

double Triangle::Triangle_lenthFromPoints(const Point &p1_in, const Point &p2_in, const Point &p3_in) const
{
    double dx12 = p1_in.Point_xOut() - p2_in.Point_xOut();
    double dy12 = p1_in.Point_yOut() - p2_in.Point_yOut();
    double dx23 = p2_in.Point_xOut() - p3_in.Point_xOut();
    double dy23 = p2_in.Point_yOut() - p3_in.Point_yOut();
    double dx31 = p3_in.Point_xOut() - p1_in.Point_xOut();
    double dy31 = p3_in.Point_yOut() - p1_in.Point_yOut();

    double side1_2 = sqrt(dx12 * dx12 + dy12 * dy12);
    double side2_3 = sqrt(dx23 * dx23 + dy23 * dy23);
    double side3_1 = sqrt(dx31 * dx31 + dy31 * dy31);
    return side1_2 + side2_3 + side3_1;
}

double Triangle::Triangle_sizeFromPoints(const Point &p1_in, const Point &p2_in, const Point &p3_in) const
{
    double x1 = p1_in.Point_xOut();
    double y1 = p1_in.Point_yOut();
    double x2 = p2_in.Point_xOut();
    double y2 = p2_in.Point_yOut();
    double x3 = p3_in.Point_xOut();
    double y3 = p3_in.Point_yOut();

    double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

    // Heron's formula: area = sqrt(s * (s - a) * (s - b) * (s - c))
    double s = (a + b + c) / 2.0;
    double heron = s * (s - a) * (s - b) * (s - c);
    return sqrt(fmax(0.0, heron));
}
