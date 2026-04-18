#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;


int main()
{
    Point rp1(0.0, 0.0);
    Point rp2(4.0, 3.0);
    Rectangle rect(rp1, rp2);

    Point tp1(0.0, 0.0);
    Point tp2(4.0, 0.0);
    Point tp3(0.0, 3.0);
    Triangle tri(tp1, tp2, tp3);

    cout << "Rectangle perimeter: " << rect.Rectangle_perimeter() << endl;
    cout << "Rectangle area: " << rect.Rectangle_area() << endl;
    cout << "Triangle perimeter: " << tri.Triangle_lenth() << endl;
    cout << "Triangle area: " << tri.Triangle_size() << endl;
    return 0;
}
