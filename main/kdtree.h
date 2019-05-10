
#define KDTREE_H
#include <iostream>
#include "noeud.h"

class kdtree
{
public:
    kdtree();

    ~kdtree();


    double computeMedian(Point* P, int start, int end, int c) ;

    int partition(Point* P, int start, int end, int c, int dim);

    void bsearch (noeud* n, Point q, int dim, double& res, Point& nnp) ;

    void swap(Point* P, int i, int j);

private:

};

