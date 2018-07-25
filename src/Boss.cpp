#include "Boss.h"

Boss::Boss(int niveau, int nivMax)
{
    std::string s = std::to_string(niveau+1);
    this->nom= "Maitre d'armes niv. "+s;
    this->pv = 40 + niveau*30;
    this->atq= 20 + niveau*10;
    this->res= 10 + niveau*10;
    this->drop=Epee(niveau);
    this->aDrop= true;
    if (niveau == nivMax-1) mfinal=true;
}

Boss::~Boss()
{
    //dtor
}
