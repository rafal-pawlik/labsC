//
// Created by Kamil Woźniak on 2019-03-21.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Point.hpp"

using ::std::pow;
using ::std::sqrt;


Point::Point() : x_(0) , y_(0) {}

Point::Point(double x, double y) : x_(x), y_(y) {};

Point::~Point(){
    std::cout << "Destruktor" << '\n';
};

double Point::Distance(const Point &other){
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

double GetX()  {
    return x_;
}

double GetY()  {
    return y_;
}

void SetX(double x){
    x_ = x;
}

void SetY(double y){
    y_ = y;
}
