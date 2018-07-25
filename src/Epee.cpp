#include "Epee.h"

Epee::Epee(int niveau)
{
    type ="arme";
    std::string s = std::to_string(niveau+1);
    nom = "Epee niv. "+ s;
    effet = 10 + niveau*5;
}

Epee::~Epee()
{
    //dtor
}
