#include "kdtree.h"


double kdtree::computeMedian(point* P,int start, int end, int axe){

        double coords [end-start];
        for (int i=start; i<end; i++)
          coords[i-start] = P[i].getcoord(axe);
        std::sort (coords, coords + end-start);
        return coords [(end-start)/2];
 }


int kdtree::partition(point* P, int start, int end, int axe, int dim) {
  double m = computeMedian (P, start, end, axe);

  int e = end-1, p = -1;
  for (int i=start; i<=e;) {
    if (P[i].getcoord(axe) > m)
      swap (P, i, e--);
    else {
      if (P[i].getcoord(axe) == m)
        p = i;
      i++;
    }
  }
  assert (p >= start && p < end);
  swap (P, p, (start+end)/2);
  p = (start+end)/2;
  assert (P[p].getcoord[axe] == m);
  return p;
}


void kdtree::swap(point* P, int i, int j) {
    point temp = P[i];
    P[i] = P[j];
    P[j] = temp;
  }
