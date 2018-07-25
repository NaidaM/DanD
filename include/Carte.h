#ifndef CARTE_H
#define CARTE_H

#include "Joueur.h"
#include "Etage.h"
#include "Etage.h"
#include "Objet.h"
#include "Potion.h"
#include "Epee.h"
#include "Armure.h"
#include "Monstre.h"
#include "Blob.h"
#include "Boss.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
class Carte
{
    public:
        Carte(int);
        virtual ~Carte();

        int getPosJoueur();

        //Deplacements du joueur :
        void versNord();
        void versSud();
        void versEst();
        void versOuest();

        void allerOuest(Joueur&);
        void allerEst(Joueur&);
        void allerSud(Joueur&);
        void allerNord(Joueur&);
        void allerNordOuest(Joueur&);
        void allerSudOuest(Joueur&);
        void allerNordEst(Joueur&);
        void allerSudEst(Joueur&);

        void deplacerJoueur(Joueur&, int, char);

        //Deplacements de monstre
        void deplacerMonstres(Joueur&);

        void afficher();
        std::string getCarte();
    protected:

    private:
        Etage etage;
        std::string carte;
        int nbEtages;
        int etageActuel;
        int posJoueur;
        int hauteur,largeur;

        static const int maxEtages=10;
        Etage etages[maxEtages];

        Monstre* tabMonstresEtage;
        int tailleTabM;
        void retirerMonstre(int);

        void allerEtageSup();
        void allerEtageInf();

        int deplacementAleatoire(int);
        Monstre getMonstreAt(int);

        const int vision = 4*largeur+largeur/2;
};

#endif // CARTE_H
