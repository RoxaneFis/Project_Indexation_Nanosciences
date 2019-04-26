
#define KDTREE_H
#include <iostream>

class kdtree
{
public:
    kdtree();

    ~kdtree();


    double computeMedian(point* P, int start, int end, int c) ;

    int partition(point* P, int start, int end, int c, int dim);

private:

};

