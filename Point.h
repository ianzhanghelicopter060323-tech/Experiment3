#ifndef POINT_H
#define POINT_H

class Rectangle;

class Point
{
    public:
        Point();
        Point(double x, double y);
        Point(const Point &p);

        Point &operator = (const Point&) = default;
        
        void Point_Input(double x_in, double y_in);

        double Point_xOut() const;
        double Point_yOut() const;
    private:
        friend class Rectangle;

        double x;
        double y;
};

#endif
