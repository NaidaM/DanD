#ifndef OBJET_H
#define OBJET_H

#include <string>

class Joueur;

class Objet
{
    public:
        Objet();
        virtual ~Objet();

        std::string getNom();
        std::string getType();
        int getEffet();

    protected:
        std::string nom;
        std::string type;
        int effet;

    private:

};

#endif // OBJET_H
