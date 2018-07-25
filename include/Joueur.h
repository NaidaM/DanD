#ifndef JOUEUR_H
#define JOUEUR_H

#include "Monstre.h"
#include "Besace.h"
#include<limits>


class Joueur
{
    public:
        Joueur();
        Joueur(int,int,int);
        virtual ~Joueur();

        bool estMort();
        bool aGagne();

        void ouvrirBesace();
        void ramasserObjet(Objet);
        void utiliserObjet(Objet,bool=false);

        bool combattre(Monstre);
        void recevoirDegats(int);
        void attaquer(Monstre&);

        int getPosition();
        void setPosition(int);
        int getPV();
        void setPV(int);
        int getAtq();
        void setAtq(int);
        int getRes();
        void setRes(int);
        Besace getBesace();
        void setBesace(Besace);

    protected:

    private:
        int position;
        int atq;
        int res;
        int pv;
        Besace besace;

        bool mort = false;
        bool gagne = false;

        // Caractéristiques de départ du Joueur :
        const int initPV = 100;
        const int initAtq = 20;
        const int initRes = 5;

        const int maxPV = 100;
};

#endif // JOUEUR_H
