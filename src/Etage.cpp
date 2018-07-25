#include "Etage.h"
#include "Salle.h"
#include <string>
#include <iostream>

Etage::Etage(){
    id=0;
    largeur=0;
    hauteur=0;
    etage="";
}

Etage::Etage(int n){
    switch (n){
        case 1 :
            creerEtage1();
            break;
        case 2 :
            creerEtage2();
            break;
        case 3 :
            creerEtage3();
            break;
        default : break;
    }
}

void Etage::creerEtage1(){
    largeur = 99;
    hauteur = 16;

    posInitialeJ=103;
    posDescJ=1993;
    posEscMont=1992;
    posEscDesc=101;

    nbPot=3;
    int *tabO=new int [nbPot];
    tabO[0] = 491;
    tabO[1] = 2488;
    tabO[2] = 1498;
    posPot = tabO;

    nbMons=3;
    int *tabM = new int [nbMons];
    tabM[0] = 347;
    tabM[1] = 781;
    tabM[2] = 1478;
    posMons = tabM;

    posArmure = 2368;
    posBoss = 2009;

    etage = "  |-----------------|                  |---------------------|                                    \n";
    etage+= "  |                 |                  |                     |                                    \n";
    etage+= "  |                 |                  |                     |                                    \n";
    etage+= "  |                 ====================                     |                |------------------|\n";
    etage+= "  |                 |                  |                     |                |                  |\n";
    etage+= "  |                 |                  |                     ==================                  |\n";
    etage+= "  |-----------------|                  |---------------------|                |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "                                                                              |                  |\n";
    etage+= "            |-----------------------------------------|                       |                  |\n";
    etage+= "            |                                         =========================                  |\n";
    etage+= "            |                                         |                       |---------------=--|\n";
    etage+= "            |                                         |                                       =   \n";
    etage+= "            |                                         |                                       =   \n";
    etage+= "            |                                         |                                       =   \n";
    etage+= "            |                                         |                                       =   \n";
    etage+= "            |                                         |                                  |----=-| \n";
    etage+= "            |                                         |                                  |      | \n";
    etage+= "            |                                         |                                  |      | \n";
    etage+= "            |                                         |                                  |------| \n";
    etage+= "            |                                         |                                           \n";
    etage+= "            |-----------------------------------------|                                           \n";
}

void Etage::creerEtage2(){
    largeur = 99;
    hauteur = 15;
    posInitialeJ=1985;
    posDescJ=1752;
    posEscMont=1851;
    posEscDesc=1984;

    nbPot=3;
    int *tabO = new int [nbPot];
    tabO[0] = 1508;
    tabO[1] = 203;
    tabO[2] = 161;
    posPot = tabO;

    nbMons=3;
    int *tabM = new int [nbMons];
    tabM[0] = 1796;
    tabM[1] = 506;
    tabM[2] = 457;
    posMons = tabM;

    posBoss = 1547;
    posArmure = 1768;
    etage = "                                       |-----------------------------------------------|          \n";
    etage+= "  |-----------------|                  |                                               |          \n";
    etage+= "  |                 |                  |                                               |          \n";
    etage+= "  |                 ====================                                               |          \n";
    etage+= "  |                 |                  |                                               |          \n";
    etage+= "  |                 |                  |                                               |          \n";
    etage+= "  |                 |                  |---------=---------------------------=---------|          \n";
    etage+= "  |                 |                            =                           =                    \n";
    etage+= "  |                 |                            =                           =                    \n";
    etage+= "  |                 |                            =                           =                    \n";
    etage+= "  |-----------=-----|                            =                           =                    \n";
    etage+= "              =                                  =                           =                    \n";
    etage+= "              =                        |---------=-------------|-------------=---------|          \n";
    etage+= "              =                        |                       |                       |          \n";
    etage+= "    |---------=----------|             |                       |                       |          \n";
    etage+= "    |                    |             |                       |                       |          \n";
    etage+= "    |                    |             |                       |                       |          \n";
    etage+= "    |                    |             |                       |                       |          \n";
    etage+= "    |                    |             |-----------------------|-----------------------|          \n";
    etage+= "    |                    |                                                                        \n";
    etage+= "    |                    |                                                                        \n";
    etage+= "    |                    |                                                                        \n";
    etage+= "    |                    |                                                                        \n";
    etage+= "    |--------------------|                                                                        \n";
    etage+= "                                                                                                  \n";
    etage+= "                                                                                                  \n";

}

void Etage::creerEtage3(){
    largeur = 99;
    hauteur = 15;
    posInitialeJ=2184;
    posDescJ=1753;
    posEscMont=1852;
    posEscDesc=2182;

    nbPot=4;
    int *tabO = new int [nbPot];
    tabO[0] = 603;
    tabO[1] = 306;
    tabO[2] = 2116;
    tabO[3] = 2126;
    posPot = tabO;

    nbMons=3;
    int *tabM = new int[nbMons];
    tabM[0] = 345;
    tabM[1] = 1499;
    tabM[2] = 375;
    posMons = tabM;

    posBoss = 1527;
    posArmure = 1052;

    etage = "                                 |-----------------|               |------------------|           \n";
    etage+= "                                 |                 |               |                  |           \n";
    etage+= "      |-------------|            |                 |               |                  |           \n";
    etage+= "      |             ==============                 =================                  |           \n";
    etage+= "      |             |            |                 |               |                  |           \n";
    etage+= "      |             |            |                 |               |                  |           \n";
    etage+= "      |             |            |                 |               |---------=--------|           \n";
    etage+= "      |             |            |                 |                         =                    \n";
    etage+= "      |             |            |                 |     |-------------------=--|                 \n";
    etage+= "      |             |            |                 |     |                      |                 \n";
    etage+= "      |-------=-----|            |                 |     |                      |                 \n";
    etage+= "              =                  |                 |     |                      |                 \n";
    etage+= "              =                  |                 |     |-----------=----------|                 \n";
    etage+= "              =                  |                 |                 =                            \n";
    etage+= "    |---------=----------|       |                 |                 =                            \n";
    etage+= "    |                    |       |                 |          |------=------|                     \n";
    etage+= "    |                    |       |                 |          |             |                     \n";
    etage+= "    |                    |       |                 |          |             |                     \n";
    etage+= "    |                    |       |                 |          |-------------|                     \n";
    etage+= "    |                    |       |                 |                                              \n";
    etage+= "    |                    |       |                 |                                              \n";
    etage+= "    |                    |       |                 |                                              \n";
    etage+= "    |                    |       |-----------------|                                              \n";
    etage+= "    |--------------------|                                                                        \n";
    etage+= "                                                                                                  \n";
    etage+= "                                                                                                  \n";
}

void Etage::retirerPotion(int pos){
    int* tab = new int [nbPot-1];
    int y=0;
    for (int x=0; x<nbPot; x++){
        if (posPot[x]!=pos) {
            tab[y] = posPot[x];
            y++;
        }
    }
    posPot = tab;
    nbPot--;
}

void Etage::retirerBoss(){
    nbBoss--;
}

void Etage::retirerArmure(){
    nbArmure--;
}
std::string Etage::getEtage(){
    return this->etage;
}

int Etage::getId(){
    return this->id;
}

int Etage::getHauteur(){
    return this->hauteur;
}

int Etage::getLargeur(){
    return this->largeur;
}
int Etage::getPosInitialeJ(){
    return this->posInitialeJ;
}

int Etage::getPosDescJ(){
    return this->posDescJ;
}

int Etage::getPosEscMont(){
    return this->posEscMont;
}

int Etage::getPosEscDesc(){
    return this->posEscDesc;
}
int* Etage::getPosPot(){
    return this->posPot;
}
int* Etage::getPosMonstres(){
    return this->posMons;
}
int Etage::getPosBoss(){
    return this->posBoss;
}
int Etage::getPosArmure(){
    return this->posArmure;
}
int Etage::getNbPot(){
    return this->nbPot;
}
int Etage::getNbMonstres(){
    return this->nbMons;
}
int Etage::getNbBoss(){
    return this->nbBoss;
}
int Etage::getNbArmure(){
    return this->nbArmure;
}

Etage::~Etage()
{
    //dtor
}
