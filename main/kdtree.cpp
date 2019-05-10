#include "kdtree.h"
#include "point.h"

void kdtree::swap(Point* P, int i, int j) {
    Point temp = P[i];
    P[i] = P[j];
    P[j] = temp;
  }

kdtree::kdtree(point* P, int start, int end, int c, int dim){
    assert (end-start >= 0);
      if (debug)
        std::cout << "start=" << start << ", end=" << end << ", c=" << c << std::endl;
      if (end-start == 0)  // no data point left to process
        return NULL;
      else if (end-start == 1)  // leaf node
        return create_node (start);
      else {  // internal node
        if (debug) {
          std::cout << "array:\n";
          for (int i=start; i<end; i++)
            print(P[i],dim);
        // std::cout << P[i] << ((i==end-1)?"\n":" ");
        }
        // compute partition
        // rearrange subarray (less-than-median first, more-than-median last)
        int p = partition (P, start, end, c, dim);
        double m = P[p][c];
        // prepare for recursive calls
        int cc = (c+1)%dim;  // next coordinate
        return create_node (c, m, p,
                 build (P, start, p, cc, dim),
                 build (P, p+1, end, cc, dim));
      }

}

double kdtree::computeMedian(point* P,int start, int end, int axe){

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
  assert (P[p].getcoord[axe] == m);
  return p;
}



Point* bsearch (noeud* n, Point q, int dim, double& res, Point& nnp, double seuil) {
    //Point*


    if (n != NULL) {
    double d= std::min(res, q.dist(n->p));
    if (d < res) {
        res = d; //distance
        nnp = n->p; //index
      }
    if (n->left != NULL || n->right != NULL) {  // internal node
      if (q.coords[n->axe] - res <= n->med)  // ball intersects left side of H // q-d < cood
  bsearch ( n->left, q, dim,  res,nnp);

      if (q.coords[n->axe] + res > n->med)  // ball intersects right side of H //  cord de q+distance > mediane
  bsearch ( n->right, q, dim,  res,nnp);
    }
  }
}




