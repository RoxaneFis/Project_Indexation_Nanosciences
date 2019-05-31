#ifndef RECHERCHE_H
#define RECHERCHE_H
#include "kdtree.h"
#include "proteine.h"
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;



typedef proteine* proteinep;

struct protcompare{
    bool operator()(const proteinep& p,const proteinep& h){
        return p->score>h->score;
    }
};




class recherche
{
public:
    //constructeur
    recherche(kdtree * k, double rayon,char*fichier);

    //variables
    kdtree *k;
    const char* fichier="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/test_ok.txt";
    //char* fichier;
    double rayon;

    //fonctions
    std::list<Point> *convert();
    std::list<result*> *neighbours();
    std::map<std::string,proteine*> *mapping();
    std::set<proteine*,protcompare> *classement();


    static kdtree * creation();

    static void split(const string &chaine, char delimiteur, vector<string> &elements);
    static vector<string> split(const string &chaine, char delimiteur);


};

#endif // RECHERCHE_H
