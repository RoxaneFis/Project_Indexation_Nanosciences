#include "recherche.h"

recherche::recherche(kdtree k, char* fichier)
{
    this->k=k;
    this->fichier=fichier;


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

std::list<result*> * resultat =  new std::list<result*> ;
int m =0;

std::cout<<"inch"<<std::endl;
while(!l->empty()){
    Point q= l->front();
    l->pop_front();
    std::list<result*>* res= k->search( q, rayon);
    resultat->insert(resultat->end(),res->begin(),res->end());
std::cout<<"RES"<<std::endl;
    std::list<result*>::iterator it;
    for(it=(*res).begin();it!=(*res).end();it++){
       // std::cout<<"PPP"<<std::endl;
        (*it)->p.print();
        std::cout<<(*it)->dist<<std::endl;

    }

}

std::map<std::string, proteine *> m;
std::list<result*>::iterator reponse;
for(reponse=(*resultat).begin();reponse!=(*resultat).end();reponse++){
    if(m.contains(reponse->name)){
        m[reponse->name]->second.addscore();

    }
    else{
     m
    }
}







