#include "kdtree.h"

class kdtreeData : public QSharedData
{
public:

};

kdtree::kdtree() : data(new kdtreeData)
{

}

kdtree::kdtree(const kdtree &rhs) : data(rhs.data)
{

}

kdtree &kdtree::operator=(const kdtree &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

kdtree::~kdtree()
{

}
