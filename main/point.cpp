#include "point.h"
#include <cmath>	// for sqrt, fabs


Point::Point(){

}

Point::Point(double* c, std::string l)
{
    this->coords=c;
    this->label=l;
}


double Point::dist(Point &q)
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


double Point::getcoord(int i){
    return coords[i];
}



void Point::print(Point p, int dim) {
  std::cout << p[0];
  for ( int j = 1; j < dim; j++)
    std::cout << " " << p[j];
  std::cout << "\n";
}

