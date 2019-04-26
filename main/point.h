#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>


class Point
{
public:
    Point();
    ~Point();

    static int d;
    double* coords;
    std::string label;


};

#endif // POINT_H
