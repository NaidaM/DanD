#ifndef ETAGE_H
#define ETAGE_H

#include "Salle.h"
#include <string>


class Etage
{
    public:
        Etage();
        Etage(int);
        virtual ~Etage();

        std::string getEtage();

        int getId();
        int getHauteur();
        int getLargeur();
        int getPosInitialeJ();
        int getPosEscMont();
        int getPosEscDesc();
        int getPosDescJ();

        int *getPosPot();
        int *getPosMonstres();
        int getPosBoss();
        int getPosArmure();
        int getNbPot();
        int getNbMonstres();
        int getNbBoss();
        int getNbArmure();

        void retirerPotion(int);
        void retirerBoss();
        void retirerArmure();

    protected:

    private:
        int id;
        int largeur, hauteur;

        int posInitialeJ;
        int posDescJ;
        int posEscMont;
        int posEscDesc;

        int nbPot;
        int *posPot;
        int nbMons;
        int *posMons;
        int nbBoss;
        int posBoss;
        int nbArmure;
        int posArmure;

        void creerEtage1();
        void creerEtage2();
        void creerEtage3();

        std::string etage;
};

#endif // ETAGE_H
