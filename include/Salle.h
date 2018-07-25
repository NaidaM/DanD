#ifndef SALLE_H
#define SALLE_H

#include <string>


class Salle
{
    public:
        Salle(int,int);
        virtual ~Salle();

        std::string getSalle();

    protected:

    private:
        int largeur;
        int hauteur;
        std::string salle;
};

#endif // SALLE_H
