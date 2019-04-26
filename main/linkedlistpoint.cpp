#include "linkedlistpoint.h"

LinkedListPoint::LinkedListPoint()
{

    this->p= new Point();
    this->next= NULL;

}
LinkedListPoint::LinkedListPoint(Point P, LinkedListPoint *n)
{
    this->p=P;
    this->next=n;

}
LinkedListPoint::~LinkedListPoint()
{

}

