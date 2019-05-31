#ifndef KDTREE_H
#define KDTREE_H
#include <iostream>
#include "noeud.h"
#include "point.h"
#include "result.h"
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>


class kdtree
{
public:



    noeud * racine;

    noeud * build (Point* P, int start, int end, int c, int dim);

    kdtree(Point* P, int start, int end, int c, int dim);

    kdtree();

    ~kdtree();


    double computeMedian(Point* P, int start, int end, int c) ;
    int partition(Point* P, int start, int end, int c, int dim);
    void swap(Point* P, int i, int j);
    std::list<result*>* search( Point q, double r);
    void printTree(noeud* racine);
    int generation(noeud* racine);
    void KDTreeToText(noeud* racine);
    static void split(const std::string &chaine, char delimiteur, std::vector<std::string> &elements);
    static std::vector<std::string> split(const std::string &chaine, char delimiteur);
    static kdtree TextToKDTree();
    static void AuxFonction1(noeud* racine, std::ifstream& fichier);

private:

};
#endif

