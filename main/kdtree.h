
#define KDTREE_H
#include <iostream>

class kdtree
{
public:
    kdtree();

    ~kdtree();


    double computeMedian(point* P, int start, int end, int axe) ;

    int partition(point* P, int start, int end, int axe, int dim);

    void swap (point* P, int i, int j);

private:

};

