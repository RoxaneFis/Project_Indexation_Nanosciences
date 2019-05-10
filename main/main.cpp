#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "linkedlistpoint.h"
#include "proteine.h"
using namespace std;





// je cree d'abord une fonction split qui renvoie un vecteur de string
void split(const string &chaine, char delimiteur, vector &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}
vector split(const string &chaine, char delimiteur)
{
    vector elements;
    split(chaine, delimiteur, elements);
    return elements;
}

// fin de la fonction split





int main()
{
    const char* file=".txt";

    // premiere lecture du fichier pour avoir le nombre de proteines

    std::ifstream fs(file);

    if(fs.fail()){
        std::cout<<"Cannot open file from "<<file <<std::endl;

    }
    string line;
    int cmpt=1;
    while(getligne(fs,line)){
    vector<string> x = split(line, ' ');
    string name= x[12];

        while( split(line,' ')[12]==name){
        getligne(fs,line);
        }
    cmpt=cmpt+1;

    }
    fs.close();



// tableau des scores
    proteine score [cmpt];





    // 2eme parcours pour remplir le tableau et creer les proteines avec un score de zero
     std::ifstream fs(file);
     string line;
     int i=0;
     while(getligne(fs,line)){
     vector<string> x = split(line, ' ');
     string name= x[12];
     score[i]= proteine(name, 0);

         while( split(line,' ')[12]==name){
         getligne(fs,line);
         }
     i=i+1;

     }
     fs.close();





// pacrous du fichier pour creer les vecteurs et les stockes dans une structure linkedlist
     std::ifstream fs(file);
    LinkedListPoint *l= new LinkedListPoint();
        string ligne;
        while(getligne(fs, ligne)){
            vector<string> x = split(ligne, ' ');
            double coords[13];
            for(int i=0;i<12;i++){
                coords[i]=std::stod(x[i]);
            }
            std::string s= x[12];
            Point *p= new Point(coords,s);
            l = LinkedListPoint(p, l);

        }


        fs.close();





// on aura egalement un fichier txt decrivant notre proteine  ici debute l'algorithme naif

        const char* fichier=".txt";
     std::ifstream fs(fichier);
     if(fs.fail()){
         std::cout<<"Cannot open file from "<<fichier <<std::endl;

     }

         string ligne_prime;
         while(getligne(fichier, ligne_prime))
         {
             vector<string> x = split(ligne, ' ');
             double coords[13];
             for(int i=0;i<12;i++){
                 coords[i]=std::stod(x[i]);
             }
             std::string s= x[12];
             Point *p= new Point(coords,s);
             while(l.next != NULL) // on parcourt tous les autres vecteurs
             {
                 if( l->point.dist(p)< /*distance a determiner */ )
                 {
                        string name1= l->point.label;
                        for(int i=0;i<cmpt;i++){
                            if(score[i].name==name1){
                                score[i].addscore();
                            }
                        }

                 }
                 l=l.next;
             }
         }

         int limite= ;// a determiner
         for(int j=0; j< cmpt ;j++)
         {
             if(score[j].getscore()> limite ){
                  std::cout<< score[j].name<< std::endl;
             }
         }



     // fin de l'algorithme naif



    return 0;
}

