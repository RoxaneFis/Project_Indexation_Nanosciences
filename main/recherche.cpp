#include "recherche.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include <list>



recherche::recherche(kdtree * k,double rayon)
{
    this->k=k;

    this->rayon=rayon;
}
std::list<Point> *recherche::convert(){
    ifstream f1(fichier);

    string line1;
    std::list<Point> *l= new std::list<Point>();
    getline(f1,line1);
    getline(f1,line1);
    while(getline(f1,line1)){
        if(line1.size()==0){
            break;
        }

        vector<string> x = split(line1, ' ');
        string name= x[13];
        double * coords= new double[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]);
        }
        l->push_back(Point(coords,name));

    }
    int nb = l->size();
    f1.close();
    return l;

}




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
            std::cout<<"ajout"<<std::endl;
            (*reponse)->p.print();
             std::cout<<std::endl;
            p->addscore();
        }
        else{
            std::string nom =(*reponse)->name;
            proteine *p = new proteine(*(*reponse));
            p->addscore();
            std::cout<<"ajout"<<std::endl;
            (*reponse)->p.print();
             std::cout<<std::endl;
            map->insert(std::pair <std::string,proteine*> (nom,  p ));

        }
    }
    return map;

}



std::set<proteine*,protcompare> *recherche::classement(){
    std::set<proteine*,protcompare> * set = new std::set<proteine*,protcompare> ;

    std::map<std::string,proteine*> * map = this->mapping();

    std::map<std::string,proteine*>::iterator pair;
    for(pair=map->begin();pair!=map->end();pair++){
        set->insert(pair->second);
    }
    return set;


}


kdtree * recherche::creation(){

    const char* file="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/test_kd_ok.txt";
    // premiere lecture du fichier pour avoir le nombre de proteines
    ifstream f(file);
    string line2;
    if(f.fail()){
        std::cout<<"Cannot open file from "<<file <<std::endl;
    }
    //LECTURE FICHIER
    // tableau des scores
    getline(f,line2);
    int cmpt = std::stoi(line2);
    getline(f,line2);
    int cmptx = std::stoi(line2);

    Point * Points = new Point[cmptx];
    int b=0;
    int j =0;
    while(getline(f,line2)){
        vector<string> x = split(line2, ' ');
        string name= x[13];
        double * coords= new double[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]); }
        Points[b++]= Point(coords,name);
    }
    f.close();
    kdtree * k = new kdtree( Points, 0, cmptx, 0, 13);
    return k;

}





void recherche::split(const string &chaine, char delimiteur, vector<string> &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
};
vector<string> recherche::split(const string &chaine, char delimiteur){
    vector<string> elements;
    split(chaine, delimiteur, elements);
    return elements;
};





int main(){
    recherche * r = new recherche(recherche::creation(),1);
    std::set<proteine*,protcompare> *result = r->classement();
    std::set<proteine*> ::iterator it;
    for((it)=result->begin(); it!=result->end(); it++){
        std::cout<<"name : "<<(*it)->name<<" score "<<(*it)->score<<std::endl;
    }
    return 0;


}








