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
    Point::d=2;
    for (int i=0; i<n; i++) {
        double *c=new double[2];
        for (int j=0; j<2; j++){

            c[j] = (i+1);
        }
        P[i] =Point(c, "t");
         P[i].print();

    }
    kdtree * k = new kdtree( P, 0, n, 0, 13);
    k->printTree(k->racine);
    std::cout<<std::endl;
    double *co = new double[2];
    co[0]=2;
    co[1]=3;
    Point *q = new Point(co, "q");

    std::cout<<"Result"<<std::endl;
     std::list<result> res= k->search( *q, 1.1);
     std::list<result>::iterator it;
     for(it=res.begin();it!=res.end();it++){
         it->p.print();
         std::cout<<it->dist<<std::endl;
    }
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


    const char* file="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/dataSet.txt";
    // premiere lecture du fichier pour avoir le nombre de proteines
    std::ifstream f(file);

    if(f.fail()){
        std::cout<<"Cannot open file from "<<file <<std::endl;

    }
    string line;
    int cmpt=1;
    while(getline(f,line)){
        vector<string> x = split(line, ' ');
        string name= x[13];

        while( split(line,' ')[13]==name){
            getline(f,line);
        }
        cmpt=cmpt+1;

    }
    f.close();


    // tableau des scores
    proteine score [cmpt];
    // 2eme parcours pour remplir le tableau et creer les proteines avec un score de zero
     ifstream f1(file);
    string line1;
    int i=0;
    while(getline(f1,line1)){
        vector<string> x = split(line1, ' ');
        string name= x[13];
        score[i]= proteine(name, 0);

        while( split(line1,' ')[13]==name){
            getline(f1,line1);
        }
        i=i+1;

    }
    f1.close();

    // pacrous du fichier pour creer les vecteurs et les stockes dans une structure linkedlist
    ifstream f2(file);
    std::list<Point> l;
    string ligne2;
    while(getline(f2, ligne2)){
        vector<string> x = split(ligne2, ' ');
        double * coords= new double[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]);
        }
        std::string s= x[13];
        Point *p= new Point(coords,s);
        l.push_back(*p);

    }

    f2.close();

    // on aura egalement un fichier txt decrivant notre proteine  ici debute l'algorithme naif

    const char* fichier="/Users/roxanefischer/Documents/cours/modal_nanosciences/Indexation_Modal_Nanosciences/kdtree/kdtree/main/prot.txt";
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
        while(! l.empty()) // on parcourt tous les autres vecteurs
        {
            Point q= l.front();
            if( q.dist(*p)< 100)
            {
                string name1= q.label;
                for(int i=0;i<cmpt;i++){
                    if(score[i].name==name1){
                        score[i].addscore();
                    }
                }

            }
            l.pop_front();

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





    return 0;
}

