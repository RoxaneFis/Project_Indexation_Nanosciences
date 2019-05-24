#ifndef RECHERCHE_H
#define RECHERCHE_H
#include "kdtree.h"
#include "proteine.h"
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;




class recherche
{
public:
    //constructeur
    recherche(kdtree * k, char* fichier, double rayon);

    //variables
    kdtree *k;
    char* fichier;
    double rayon;

    //fonctions
    std::list<Point> *convert();
    std::list<result*> *neighbours();
    std::map<std::string,proteine*> *mapping();
    std::set<proteine*> *classement();

    void split(const string &chaine, char delimiteur, vector<string> &elements);
    vector<string> split(const string &chaine, char delimiteur);


};

#endif // RECHERCHE_H
