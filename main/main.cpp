#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "linkedlistpoint.h"
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

// il faut d'abord creer un tableau score avec toutes les references des proteines
    int score [/*nombre de proteines total */]
// mettre le score a 0 pour toutes les proteines

// code pour lire le fichier avec les vecteurs et creer une linkedlist de points
// on ouvre le fichier avec les differents vecteurs
    ifstream fichier("vecteurspdb.txt", ios::in);
    if(fichier)  // si l'ouverture a réussi

    {
        LinkedListPoint *l= new LinkedListPoint();
        string ligne;
        while(getligne(fichier, ligne)){
            vector<string> x = split(ligne, ' ');
            double coords[13];
            for(int i=0;i<12;i++){
                coords[i]=std::stod(x[i]);
            }
            std::string s= x[12];
            Point *p= new Point(coords,s);
            l = LinkedListPoint(p, l);

        }


        fichier.close();  // on ferme le fichier

    }

    else  // sinon

        cerr << "Impossible d'ouvrir le fichier !" << endl;

// on aura egalement un fichier txt decrivant notre proteine  ici debute l'algorithme naif

     ifstream fichier("notreproteine.txt", ios::in);
     if(fichier)
     {
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
                 if( l.point.dist(p)< /*distance a determiner */ )
                 {
                        score[stoi(l.point.label)]++;
                 }
                 l=l.next;
             }
         }
         for(int i=0; i< /*nbr de prot*/ ;i++)
         {
             if(score[numeroprot]> /* limite a determiner */ ){
                 // la proteine est a retenir
             }
         }


     }
     // ici se termine l'algorithme naif



    return 0;
}

