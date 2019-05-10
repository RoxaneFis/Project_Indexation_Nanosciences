#include "kdtree.h"
#include "point.h"


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
        //print(P[i],dim);
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

std::list<result> kdtree::search( Point q, float r){

    std::list<result> reponse();
    std::list<noeud> attente();

    attente.push_front(racine);

    while (attente.size()>0) {
        noeud* a= attente.pop_front();



    }






}








int main(){


      int n = 5;  // n points in R^{dim}
      int dim = 2;
      // random input data points (uniformly sampled in unit cube)
      srand (time(NULL));
      Point * P[n];
      for (int i=0; i<n; i++) {
          double *c;
          c={1,2};
          P[i] =Point(c, "t");
        for (int j=0; j<dim; j++)
          P[i][j] = i;
      }
      noeud* f = build ( P, 0, n, 0,  dim);
      //std::cout<<"debut built" << f->m << f->left->m <<f->right->m <<"fin built"<< std::endl;





    return 0;
}


