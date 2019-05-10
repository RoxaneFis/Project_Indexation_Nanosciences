#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include"point.h"
#include "proteine.h"
#include <list>
using namespace std;





// je cree d'abord une fonction split qui renvoie un vecteur de string
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

// fin de la fonction split





int main()
{
    const char* file="pdb.txt";

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
        double coords[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]);
        }
        std::string s= x[13];
        Point p=  Point(coords,s);
        l.push_back(p);

    }


    f2.close();





    // on aura egalement un fichier txt decrivant notre proteine  ici debute l'algorithme naif

    const char* fichier="prot.txt";
     ifstream f3(fichier);
    if(f3.fail()){
        std::cout<<"Cannot open file from "<<fichier <<std::endl;

    }

    string ligne_prime;
    while(getline(f3, ligne_prime))
    {
        vector<string> x = split(ligne_prime, ' ');
        double coords[13];
        for(int i=0;i<13;i++){
            coords[i]=std::stod(x[i]);
        }
        std::string s= x[12];
        Point p=  Point(coords,s);
        while(! l.empty()) // on parcourt tous les autres vecteurs
        {
            Point q= l.front();
            if( q.dist(p)< 100)
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



    // fin de l'algorithme naif



    return 0;
}

