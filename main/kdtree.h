#ifndef KDTREE_H
#define KDTREE_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class kdtreeData;

class kdtree
{
public:
    kdtree();
    kdtree(const kdtree &);
    kdtree &operator=(const kdtree &);
    ~kdtree();

private:
    QSharedDataPointer<kdtreeData> data;
};

#endif // KDTREE_H