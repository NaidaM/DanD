#ifndef BESACE_H
#define BESACE_H

#include <Objet.h>
#include <iostream>

class Besace
{
    public:
        Besace();
        virtual ~Besace();
        void ouvrir();
        void ajouter(Objet);
        void jeter(int);
        int getNbObjets();
        Objet selectionnerObjet(int);
    protected:

    private:
        Objet* objets;
        int nbObjets;
        //const int maxObj=100;

};

#endif // BESACE_H
