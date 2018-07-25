#include "Arumure.h"

Arumure::Arumure(int niveau)
{
    type ="armure";
    nom = "Armure niv. "+ (niveau+1);
    effet = 10 + niveau*5;
}

Arumure::~Arumure()
{
    //dtor
}
