#include "kdtree.h"


kdtree::computeMedian(point* P,int start, int end, int axe){

        double coords [end-start];
        for (int i=start; i<end; i++)
          coords[i-start] = P[i].getcoord(axe);
        std::sort (coords, coords + end-start);
        return coords [(end-start)/2];
 }
