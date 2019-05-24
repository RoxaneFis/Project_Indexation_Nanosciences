#include "recherche.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include <list>




recherche::recherche(kdtree * k, char* fichier,double rayon)
{
    this->k=k;
    this->fichier=fichier;
    this->rayon=rayon;
}

std::list<Point> *recherche::convert(){
    ifstream f1(fichier);
    string line1;
    std::list<Point> *l= new std::list<Point>();
    while(getline(f1,line1)){

        vector<string> x = split(line1, ' ');
        string name= x[13];
        double * coords= new double[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]); }
        l->push_back(Point(coords,name));
    }
    int nb = l->size();
    f1.close();
    return l;
}


double rayon = 1.1;



std::list<result*> * recherche::neighbours(){
    std::list<result*> * resultat =  new std::list<result*> ;

    //l : point de la proteine
    std::list<Point> *l=this->convert();

    while(!l->empty()){
        Point q= l->front();
        l->pop_front();
        std::list<result*>* res= k->search( q, rayon);
        resultat->insert(resultat->end(),res->begin(),res->end());
    }
    return resultat;
}





std::map<std::string,proteine*> * recherche::mapping(){
    std::map<std::string,proteine*> * map = new  std::map<std::string,proteine*> ;
    std::list<result*> * resultat=this->neighbours();
    std::list<result*>::iterator reponse;
    for(reponse=(*resultat).begin();reponse!=(*resultat).end();reponse++){
        if(   (*map).find((*reponse)->name) != (*map).end()  ){
            proteine *p=(*map)[(*reponse)->name];
            p->addscore();
        }
        else{
            std::string nom =(*reponse)->name;
            proteine *p = new proteine(*(*reponse));
            map->insert(std::pair <std::string,proteine*> (nom,  p ));

        }
    }
    return map;
}



struct protcompare{
    bool operator()(const proteine& p,const proteine& h){
        return p.score<h.score;

    }
};


std::set<proteine*> *recherche::classement(){
    std::set<proteine*,protcompare> * set = new std::set<proteine*,protcompare> ;
    std::map<std::string,proteine*> * map = this->mapping();
    std::map<std::string,proteine*>::iterator pair;
    for(pair=map->begin();pair!=map->end();pair++){
        set->insert(pair->second);
    }




}


int main(){
    recherche * r = new recherche
    std::set<proteine*> result = this.

}








void recherche::split(const string &chaine, char delimiteur, vector<string> &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}
vector<string> recherche::split(const string &chaine, char delimiteur)
{
    vector<string> elements;
    split(chaine, delimiteur, elements);
    return elements;
}







