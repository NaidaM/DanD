#ifndef POTION_H
#define POTION_H

#include <Objet.h>


class Potion : public Objet
{
    public:
        Potion(int, bool=false);
        virtual ~Potion();
};

#endif // POTION_H
