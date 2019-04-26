#include "point.h"
Point::Point(){

}

Point::Point(double* c, std::string l)
{
    this->coords=c;
    this->label=s;
}
double Point::dist(point &q)
{
  double sqd = 0.0;

  for (int m = 0; m < d; m++)
    sqd += (coords[m]-q.coords[m]) * (coords[m]-q.coords[m]);

  return sqrt(sqd);
}
bool Point::set_dim (int _d) {
  if (d > 0)
    return false;

  d = _d;
  return true;
}
int Point::get_dim () {
  return d;
}
