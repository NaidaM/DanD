#include "Blob.h"

Blob::Blob(int niveau, int position)
{
    std::string s = std::to_string(niveau+1);
    this->nom= "Blob niv " + s;
    this->pv = 40+niveau*20;
    this->atq= 15+niveau*10;
    this->res= 5+niveau*10;
    this->position = position;

    srand(time(NULL));
	int auraDrop=rand()%3;

	if (auraDrop == 1){
        this->aDrop = true;
        int rouge=rand()%4;

        if (rouge == 1)
            this->drop = Potion(niveau, true);
        else this->drop = Potion(niveau);
	}

   /* niveau %= 3;
    switch (niveau){
    case 0:
        deplacement = "neutre";
    case 1:
        deplacement = "tp";
    case 2:
        deplacement = "versJoueur";
    }*/

    deplacement = "neutre";
}

Blob::~Blob()
{

}
