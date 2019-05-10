#include "kdtree.h"
#include "point.h"
#include <list>



//noeud(Point _p);
//noeud(int _axe, double _med, Point _p, noeud* _left, noeud* _right);


//fonction constructeurs
noeud* kdtree::build (Point* P, int start, int end, int c, int dim) {
  assert (end-start >= 0);
  if (end-start == 0)
    return nullptr;
  else if (end-start == 1){  // leaf node
      noeud n =noeud(P[start]);
      noeud *i = &n;
      return i;}

  else {  // internal node
      for (int i=start; i<end; i++){
       std::cout << P[i].getcoord(0) << ((i==end-1)?"\n":" ");
      }
    }
    int p = partition (P, start, end, c, dim);
    double m = P[p].getcoord(c);
    int cc = (c+1)%dim;  // next coordinate

    noeud*left = build (P, start, p, cc, dim);
    noeud *right=build (P, p+1, end, cc, dim);
    noeud racine =noeud(c,m,P[p],left,right);
    noeud* retour= &racine;
    return retour;
}

kdtree::kdtree(Point* P, int start, int end, int c, int dim){
    racine = build (P, start, end, c,  dim);
}


void kdtree::swap(Point* P, int i, int j) {
    Point temp = P[i];
    P[i] = P[j];
    P[j] = temp;
  }

double kdtree::computeMedian(Point* P,int start, int end, int axe){
        double coords [end-start];
        for (int i=start; i<end; i++)
          coords[i-start] = P[i].getcoord(axe);
        std::sort (coords, coords + end-start);
        return coords [(end-start)/2];
}

int kdtree::partition(Point* P, int start, int end, int axe, int dim) {
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
  swap(P, p, (start+end)/2);
  p = (start+end)/2;
  assert (P[p].getcoord(axe) == m);
  return p;
}






