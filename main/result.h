#ifndef RESULT_H
#define RESULT_H
#include <string>
#include "point.h"


class result
{
public:
    result(std::string name, Point p, double dist);
    std::string name;
    Point p;
    double dist;

};

#endif // RESULT_H
