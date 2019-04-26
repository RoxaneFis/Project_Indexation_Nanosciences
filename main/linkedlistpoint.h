#ifndef LINKEDLISTPOINT_H
#define LINKEDLISTPOINT_H
#include "point.h"

class LinkedListPoint
{
public:
    LinkedListPoint();
    LinkedListPoint(Point P, LinkedListPoint *n );
    ~LinkedListPoint();




private:
    Point *p;
    LinkedListPoint *next;

};

#endif // LINKEDLISTPOINT_H
