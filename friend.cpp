#include <iostream>
#include <cmath>
using namespace std;


// class Segment; // pre-declearation

class Point
{
    private:
        double x;
        double y;

        //friend class Segment; // define Point as friend of Segment 

    public:
        Point(double x=0, double y=0): x(x), y(y) {}
        ~Point() {}

        // friend function declearation
        friend double getX(const Point &p);
        friend double getY(const Point &p);
};

// friend function
double getX(const Point &p)
{
    return p.x;
}
double getY(const Point &p)
{
    return p.y;
}

class Segment 
{
private:
    Point p1;
    Point p2;
public:
    Segment(Point a, Point b): p1(a), p2(b) {}
    ~Segment() {}

    double length() const 
    {
        double delta_x = getX(p1) - getX(p2); /*p1.x - p2.x;*/ // (x1-x2)
        double delta_y = getY(p1) - getY(p2); /*p1.y - p2.y*/; // (y1-y2)

        return sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    }

    void midpoint() const
    {
        double mid_x = 0.5 * (getX(p1) + getX(p2));
        double mid_y = 0.5 * (getY(p1) + getY(p2));
        
        cout << "mid point axis: " 
             << "(" << mid_x << ", " << mid_y << ")" 
             << endl;
    }

    void show() const
    {
        cout << "p1 axis: "
             << "(" << getX(p1) << ", " << getY(p1) << ")"
             << endl;

        cout << "p2 axis: "
             << "(" << getX(p2) << ", " << getY(p2) << ")"
             << endl;
    }
};


int main()
{
    Point p1(0, 0);
    Point p2(0, 2);

    Segment s1(p1, p2);
    double segLength = s1.length();

    cout << "length: "
         << segLength << endl;
    
    s1.midpoint();
    s1.show();

    return 0;
}