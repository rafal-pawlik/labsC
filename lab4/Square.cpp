#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Point.h"


Square::Square() : w1(0) , w2(0) , w3(0) , w4(0) {}

Square::Square(Point ww1,Point ww2 , Point ww3 , Point ww4) : w1(ww1) , w2(ww2) , w3(ww3) , w4(ww4) {}

Square::~Square() {}

double Square::Circumference(){
    return w1.Distance(w2) + w2.Distance(w3) + w3.Distance(w4) + w4.Distance(w1);
}

double Square::Area(){
    return w1.Distance(w2) * w2.Distance(w3)
}
