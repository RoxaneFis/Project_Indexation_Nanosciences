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

    double dist( Point &q);
    static bool set_dim (int _d);
    static int get_dim();

};

#endif // POINT_H
