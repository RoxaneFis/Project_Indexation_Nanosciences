
#include "kdtree.h"

int main(){


      int n = 5;  // n points in R^{dim}
      Point * P; //new point
      int dim = P[0].d;
      for (int i=0; i<n; i++) {
          double* c;
          for (int j=0; j<dim; j++){
            c[j] = j;}
         P[i] =Point(c, "t");
      }

    kdtree* f = new kdtree( P, 0, n, 0,  dim);

    return 0;
}
