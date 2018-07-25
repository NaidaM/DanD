#include "Potion.h"

Potion::Potion(int niveau, bool rouge)
{
    std::string s = std::to_string(niveau+1);
    nom = "Potion ";
    type = "potion";
    effet=20+niveau*5;

    if (rouge) {
        effet = -(effet);
        nom+= "Rouge ";
    }

    nom+= "niv. "+s;
}

Potion::~Potion()
{
    //dtor
}
