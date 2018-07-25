#include <iostream>
#include "Joueur.h"
#include "Carte.h"
#include "Salle.h"
#include "Etage.h"
#include "Besace.h"
#include "Potion.h"

#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;
HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

void jeuPerdu() {
    SetConsoleTextAttribute(Console, 12);
    cout<<"Vous etes mort."<<endl;
}

void jeuGagne() {
    SetConsoleTextAttribute(Console, 10);
    cout<<"Felicitations, vous avez fini DandD !"<<endl;
}

void afficherInfos(Joueur j,Carte carte){
    cout << "PV:" << j.getPV() << " ATQ:" << j.getAtq() << " RES:" << j.getRes()<< " POS:" << carte.getPosJoueur() << endl;
}

int main()
{
    Joueur j;
    Carte carte(3);
    char commande;
    SetConsoleTextAttribute(Console, 11);

    do {
        carte.afficher();
        afficherInfos(j,carte);

        commande=getch();

        try {
        switch (tolower(commande)) {
            case 'a' :
                carte.allerNordOuest(j);
                break ;
            case 'z' :
                carte.allerNord(j);
                break;
            case 'e' :
                carte.allerNordEst(j);
                break ;
            case 'q' :
                carte.allerOuest(j);
                break;
            case 'd' :
                carte.allerEst(j);
                break ;
            case 'w' :
                carte.allerSudOuest(j);
                break ;
            case 'x' :
                carte.allerSud(j);
                break ;
            case 'c' :
                carte.allerSudEst(j);
                break ;
            case 'r' :
                carte.versNord();
                break ;
            case 'f' :
                carte.versOuest();
                break ;
            case 'g' :
                carte.versEst();
                break ;
            case 'v' :
                carte.versSud();
                break ;
            case 'b' :
                j.ouvrirBesace();
                break ;
            case 'i' :
                //infos();
                break ;
            case ' ' :
                break ;
            default : cout << "\nCommande inconnue.\n" ;
        }

        if (j.estMort()){
            jeuPerdu(); break;
        }
        if (j.aGagne()){
            jeuGagne(); break;
        }
        carte.deplacerMonstres(j);

        }
        catch(char const *error)
        {
            cerr<<"Error: "<<error<<endl;
        }

    } while (commande!=' ');

    SetConsoleTextAttribute(Console, 7);

    return 0;
}
