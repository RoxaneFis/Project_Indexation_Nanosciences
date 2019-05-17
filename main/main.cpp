#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include <list>

#include"point.h"
#include "proteine.h"
#include "kdtree.h"
#include "result.h"
#include "noeud.h"



using namespace std;

void test_build(){
    std::cout<<"Test_Build"<<std::endl;
    int n = 7;  // n points in R^{dim}
    Point * P;
    P= new Point[n]; //new point
    Point::d=13;
    for (int i=0; i<n; i++) {
        double *c=new double[13];
        for (int j=0; j<13; j++){

            c[j] = (i+1);
        }
        P[i] =Point(c, "t");
        P[i].print();

    }
    kdtree * k = new kdtree( P, 0, n, 0, 13);
    k->printTree(k->racine);
    std::cout<<std::endl;
    double *co = new double[13];
    co[0]=2;
    co[1]=3;
    Point *q = new Point(co, "q");

    std::cout<<"Result2"<<std::endl;
    std::list<result*> *res= k->search( *q, 10);
    std::list<result*>::iterator it;
    for(it=res->begin();it!=res->end();it++){
        (*it)->p.print();
        std::cout<<(*it)->dist<<std::endl;
    }
     std::cout<<"Result3"<<std::endl;

}




void split(const string &chaine, char delimiteur, vector<string> &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}
vector<string> split(const string &chaine, char delimiteur)
{
    vector<string> elements;
    split(chaine, delimiteur, elements);
    return elements;
}



int main()
{
    //test_build();



    const char* file="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/prot0.txt";
    // premiere lecture du fichier pour avoir le nombre de proteines
    std::ifstream f(file);

    if(f.fail()){
        std::cout<<"Cannot open file from "<<file <<std::endl;

    }

    // tableau des scores
    int cmpt = 1;
    int cmptx =29;
    proteine *score =new proteine[cmpt];
    Point * Points = new Point[cmptx];


    //LECTURE FICHIER
    ifstream f2(file);
    string line2;


    int i=0;
    int j =0;


    while(getline(f2,line2)){
        //Lecture + creation point/proteine
        vector<string> x = split(line2, ' ');
        string name= x[13];
        double * coords= new double[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]); }
        Points[i++]= Point(coords,name);
        score[j++]= proteine(name, 0);
        while( split(line2,' ')[13]==name){
            if( !getline(f2,line2)){
                break;
            };
            vector<string> x = split(line2, ' ');
            string name= x[13];
            double * coords= new double[13];
            for(int i=0;i<13;i++){
                coords[i]=std::stod(x[i]); }
            Points[i++]= Point(coords,name);
        }

    }
    f2.close();




    //NAIF



    /*const char* fichier="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/prot.txt";
    ifstream f3(fichier);
    if(f3.fail()){
        std::cout<<"Cannot open file from "<<fichier <<std::endl;
    }
    string ligne_prime;
    while(getline(f3, ligne_prime))
    {
        vector<string> x = split(ligne_prime, ' ');
        double *coords =new double[13];
        for(int i=0;i<13;i++){
            // coords[i] =std::atof(x[i].c_str());
            coords[i]=std::stod(x[i]);
        }
        std::string s= x[12];
        Point * p= new Point(coords,s);
        for(int l=0;i<cmptx;i++) // on parcourt tous les autres vecteurs
        {
            Point q= Points[l];
            if( q.dist(*p)< 100)
            {
                string name1= q.label;
                for(int i=0;i<cmpt;i++){
                    if(score[i].name==name1){
                        score[i].addscore();
                    }
                }
            }
        }
    }
    f3.close();
    // selon une limite on decide ou pas de retenir une proteine
    int limite= 1;// a determiner
    for(int j=0; j< cmpt ;j++)
    {
        if(score[j].getscore()> limite ){
            std::cout<< score[j].name<< std::endl;
        }
    }
    // fin de l'algorithme naif*/



    //Lecture + creation point/proteine

    const char* fichier="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/prot0.txt";


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
    kdtree * k = new kdtree( Points, 0, cmptx, 0, 13);

    // k->printTree(k->racine);

    // std::cout<<"inch"<<std::endl;
    std::list<result*> *resultat =  new std::list<result*> ;
    int m =0;

    std::cout<<"inch"<<std::endl;
    while(!l->empty()){
        Point q= l->front();
        l->pop_front();
        std::list<result*>* res= k->search( q, 1.1);
        resultat->insert(resultat->end(),res->begin(),res->end());
    std::cout<<"RES"<<std::endl;
        std::list<result*>::iterator it;
        for(it=(*res).begin();it!=(*res).end();it++){
           // std::cout<<"PPP"<<std::endl;
            (*it)->p.print();
            std::cout<<(*it)->dist<<std::endl;

        }

    }





    return 0;
}

