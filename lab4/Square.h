#include "Point.h"

class Square{

Point w1,w2,w3,w4;

public:
    Square();
    Square(Point ww1,Point ww2 , Point ww3 , Point ww4);
    ~Square();

    double Circumference();
    double Area();

};
