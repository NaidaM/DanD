#ifndef MONSTRE_H
#define MONSTRE_H

#include "Objet.h"
#include "Epee.h"
#include "Potion.h"
#include <time.h>
#include <string>

class Joueur;

class Monstre
{
    public:
        Monstre();
        virtual ~Monstre();

        std::string getNom();
        int getPV();
        void setPV(int);
        int getAtq();
        void setAtq(int);
        int getRes();
        void setRes(int);
        std::string getDeplacement();
        Objet getDrop();
        bool getADrop();
        int getPosition();
        void setPosition(int);

        void attaquer(Joueur&);
        int recevoirDegats(int);

        bool estFinal();


    protected:
        std::string nom;
        std::string type;
        std::string deplacement = "statique";
        Objet drop;
        char icone;
        int atq;
        int res;
        int pv;
        bool aDrop = false;
        int position;
        bool mfinal = false;

    private:
};

#endif // MONSTRE_H
