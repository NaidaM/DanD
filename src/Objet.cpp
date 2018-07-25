#include "Objet.h"

Objet::Objet()
{
}

std::string Objet::getNom(){
    return nom;
}

std::string Objet::getType(){
    return type;
}

int Objet::getEffet(){
    return effet;
}

Objet::~Objet()
{
    //dtor
}
