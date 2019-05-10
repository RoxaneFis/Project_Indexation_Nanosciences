
#define KDTREE_H
#include <iostream>
#include "noeud.h"

class kdtree
{
public:

    noeud * racine;

    kdtree(Point* P, int start, int end, int c, int dim);

    kdtree();

    ~kdtree();

    double computeMedian(Point* P, int start, int end, int c) ;

    int partition(Point* P, int start, int end, int c, int dim);

    void swap(Point* P, int i, int j);

private:

};

