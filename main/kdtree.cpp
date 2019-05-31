#include "kdtree.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <vector>
#include <sstream>
#include <list>



//fonction constructeurs
noeud* kdtree::build (Point* P, int start, int end, int c, int dim) {
    // int k=0;

    assert (end-start >= 0);
    if (end-start == 0)
        return nullptr;
    else if (end-start == 1){  // leaf node
        noeud* n = new noeud(P[start]);
        return n;}

    else {  // internal node
        for (int i=start; i<end; i++){
            // std::cout << P[i].getcoord(0) <<std::endl;
            //k++;
        }
    }
    int p = partition (P, start, end, c, dim);
    double m = P[p].getcoord(c);
    int cc = (c+1)%dim;  // next coordinate

    noeud*left = build (P, start, p, cc, dim);
    noeud *right=build (P, p+1, end, cc, dim);
    noeud *racine =new noeud(c,m,P[p],left,right);
    // noeud* retour= &racine;
    //std::cout<<"k"<<k<<std::endl;
    return racine;
}

kdtree::kdtree(Point* P, int start, int end, int c, int dim){
    racine = build (P, start, end, c,  dim);
}
kdtree::~kdtree(){

}

kdtree::kdtree(){

}



void kdtree::swap(Point* P, int i, int j) {
    Point temp = P[i];
    P[i] = P[j];
    P[j] = temp;
}

double kdtree::computeMedian(Point* P,int start, int end, int axe){
    double coords [end-start];
    for (int i=start; i<end; i++)
        coords[i-start] = P[i].getcoord(axe);
    std::sort (coords, coords + end-start);
    return coords [(end-start)/2];
}

int kdtree::partition(Point* P, int start, int end, int axe, int dim) {
    double m = computeMedian (P, start, end, axe);
    int e = end-1, p = -1;
    for (int i=start; i<=e;) {
        if (P[i].getcoord(axe) > m)
            swap (P, i, e--);
        else {
            if (P[i].getcoord(axe) == m)
                p = i;
            i++;
        }
    }
    assert (p >= start && p < end);
    swap(P, p, (start+end)/2);
    p = (start+end)/2;
    assert (P[p].getcoord(axe) == m);
    return p;
}

std::list<result*>* kdtree::search( Point q, double r){

    std::list<result*>* reponse = new std::list<result*>();
    std::list<noeud*> attente;
    //std::cout << "push front racine" << std::endl;
    attente.push_front(racine);

    while (attente.size()>0) {
        noeud* a= attente.front();
        attente.pop_front();

        // std::cout << "pop front" << std::endl;
        //std::cout << "a:" << a << std::endl;

        if(a->isleaf()){
            // std::cout << "leaf" << std::endl;
            if(a->p.dist(q)<r){
                result *match=new result(a->p.label,a->p,a->p.dist(q));
                reponse->push_front(match);
            }
        }
        else{
            //std::cout << "not leaf" << std::endl;
            int c=a->axe;
            if(a->p.dist(q)<r){
                result *match= new result(a->p.label,a->p,a->p.dist(q));
                reponse->push_front(match);

            }

            if(std::abs(q.coords[c]-a->med)<=r){
                if (a->left) attente.push_back(a->left);
                if (a->right) attente.push_back(a->right);


            }

            else{
                if(q.coords[c]>a->med){
                    if (a->right) attente.push_back(a->right);
                }
                else{if (a->left) attente.push_back(a->left);}

            }
        }
    }
    return reponse;
}


void kdtree::printTree(noeud* racine){
    int gen = 0;
    int i = 0;
    if(racine!=nullptr){
        gen=generation(racine);
        for(i=0;i<gen;i++){
            std::cout<<" "<<std::endl;
        }
        racine->p.print(); //affiche point
        printTree(racine->left);
        printTree(racine->right);
    }
}


int kdtree::generation(noeud * racine){
    if (racine == nullptr)
        return 0;
    else
        return 1 + std::max(generation(racine->left), generation((racine->right)));

}


void kdtree::KDTreeToText(noeud* racine){
    if(racine != nullptr){

        std::ofstream fichier("/users/eleves-b/2017/antoine.dupre/KDTreeText.txt", std::ios::out | std::ios::app);

        bool feuille = racine->noeud::isleaf() ;
        double* coords = racine->p.coords  ;
        std::string label =racine->p.label ;

        std::string point = std::to_string(feuille) + " " ;

        for(int i=0; i<13; i++){
            point += std::to_string(coords[i]) ;
            point += " " ;
        }
        point += label ;
        fichier << point << std::endl ;
        KDTreeToText(racine->left);
        KDTreeToText(racine->right);

    }
}




void kdtree::split(const std::string &chaine, char delimiteur, std::vector<std::string> &elements){
    std::stringstream ss(chaine);
    std::string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}

std::vector<std::string> kdtree::split(const std::string &chaine, char delimiteur){
    std::vector<std::string> elements;
    split(chaine, delimiteur, elements);
    return elements;
}




void kdtree::AuxFonction1(noeud* racine, std::ifstream& fichier){

    std::string ligne;
    while (getline(fichier, ligne)) {

        std::vector<std::string> pointTxt = split(ligne, ' ');

        int isleaf = stoi(pointTxt[0]) ;

        double* coords = new double(13);
        for(int i = 1; i<14; i++){
            coords[i] = stod(pointTxt[i]);
        }

        Point* P = new Point(coords, pointTxt[14]);

        racine->p= *P ;

        if(isleaf == 0){
            AuxFonction1(racine->left, fichier);
            AuxFonction1(racine->right, fichier);

        }

    }

}


kdtree kdtree::TextToKDTree(){

    std::ifstream fichier("/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/KDTreeText.txt", std::ios::out | std::ios::app);
    noeud* racine = nullptr ;

    AuxFonction1(racine, fichier) ;

    fichier.close();

    kdtree* k= new kdtree();
    k->racine = racine ;

    return *k ;
}








