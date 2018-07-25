#include "Armure.h"

Armure::Armure(int niveau)
{
    type ="armure";
    std::string s = std::to_string(niveau+1);
    nom = "Armure niv. "+ s;
    effet = 10 + niveau*5;
}

Armure::~Armure()
{
    //dtor
}
