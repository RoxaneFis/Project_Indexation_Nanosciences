#ifndef RECHERCHE_H
#define RECHERCHE_H
#include "kdtree.h"




class recherche
{
public:

    recherche(kdtree k, char* fichier);
    kdtree k;
    char* fichier;
    std::list<Point> *convert();
    std::list<result*> *neighbours();


};

#endif // RECHERCHE_H
