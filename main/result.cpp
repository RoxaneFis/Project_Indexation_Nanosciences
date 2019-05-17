#include "result.h"


result::result(){}
result::~result(){}

result::result(std::string name, Point p, double dist)
{
    this->name=name;
    this->p=p;
    this->dist=dist;
}
