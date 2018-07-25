#include "Salle.h"
#include <string>

Salle::Salle(int largeur, int hauteur)
{
    this->largeur = largeur;
    this->hauteur = hauteur;


    std::string s = " ";

    for (int l=0; l<largeur; l++) {
        s+=std::string("-");
    }
    s+=std::string(" \n");

    for (int h=0; h<hauteur; h++){
        s+=std::string("|");

        for (int l=0; l<largeur; l++){
            s+=std::string(" ");
        }

        s+=std::string("|\n");
    }
    s+=std::string(" ");

    for (int l=0; l<largeur; l++) {
        s+=std::string("-");
    }
    s+=std::string(" ");


    this->salle = s;
}


std::string Salle::getSalle(){
    return this->salle;
}

Salle::~Salle()
{
    //dtor
}
