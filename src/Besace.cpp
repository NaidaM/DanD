#include "Besace.h"

#include<limits>
Besace::Besace()
{
    objets = new Objet[100];
    nbObjets = 0;
}

void Besace::ouvrir(){
    std::cout << "\nVotre besace contient : ";
    for (int i = 0; i<nbObjets; i++) {
        std::cout << i+1 << "-" << objets[i].getNom() << "    ";
    }
}

Objet Besace::selectionnerObjet (int i){
    return objets[i];
}

void Besace::jeter(int i){
    if (nbObjets-1 == 0) {
        objets = new Objet [100];
    }
    else {
        Objet* o= new Objet [100];
        int y=0;
        for (int x=0; x<nbObjets; x++){
            if (x!=i) {
                o[y] = objets[x];
                y++;
            }
        }
        objets = o;
    }
    nbObjets--;
}

void Besace::ajouter(Objet o){
    objets[nbObjets] = o;
    nbObjets++;
}

int Besace::getNbObjets() {
    return nbObjets;
}
Besace::~Besace()
{
    //dtor
}
