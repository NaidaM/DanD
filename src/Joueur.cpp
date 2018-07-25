#include "Joueur.h"

Joueur::Joueur()
{
    this->pv = initPV;
    this->atq = initAtq;
    this->res = initRes;
    this->besace = Besace();
}

/*Joueur::Joueur(int pv, int atq, int res)
{
    this->pv = pv;
    this->atq = atq;
    this->res = res;
    this->besace = Besace();
}*/

void Joueur::ramasserObjet(Objet o){
    this->besace.ajouter(o);
    std::cout<< "Vous avez ramasse 1 " << o.getNom() << "."<< std::endl;
}

bool Joueur::combattre (Monstre m){
    std::cout<< "\nUn combat contre " << m.getNom() << " commence !"<<std::endl;
    int commande;
    bool victoire = false;
    do {
        std::cout<<"\nQue voulez-vous faire ?\n1-Attaquer   2-Utiliser un objet  3-Fuir"<<std::endl;
        while (!(std::cin >> commande) || (commande != 1 && commande != 2 && commande != 3)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrez 1, 2, 3\n";
        }

        switch (commande){
        case 1:
            attaquer(m); break;
        case 2:
            ouvrirBesace(); break;
        case 3:
            std::cout<<"Vous prenez la fuite"<<std::endl; break;
        }
        if (commande==3)break;

        if(m.getPV()<=0){
            std::cout<<"Vous avez vaincu "<< m.getNom()<<std::endl;
            victoire=true;
            if (m.estFinal()){
                gagne=true;
            }
            else if (m.getADrop()){
                    std::cout<<m.getNom()<< " a lache 1 " << m.getDrop().getNom() << " !"<<std::endl;
                    ramasserObjet(m.getDrop());
            }
            break;
        }
        m.attaquer(*this);

        if (this->pv == 0) {
            mort=true;break;
        }

    } while (commande!=3 && this->pv>0 && m.getPV()>0);
    return victoire;
}

void Joueur::recevoirDegats(int d){
    int degats = d-res;
    if (degats<0) degats = 0;
    this->pv -= degats;
    if (this->pv<0)this->pv = 0;
    std::cout<<degats <<" degats recus ! Il vous reste "<<getPV()<<" PV"<<std::endl;
}

void Joueur::attaquer (Monstre &m){
    std::cout<<m.recevoirDegats(atq)<<" degats infliges ! ";
    std::cout<< m.getNom()<<" a encore "<< m.getPV() << "PV"<<std::endl;
}

void Joueur::ouvrirBesace(){
    if (this->besace.getNbObjets()<1) std::cout<<"Votre besace est vide."<<std::endl;

    else {
        this->besace.ouvrir();

        int i,j;
        std::cout<<"\nSelectionner un objet, 0 pour fermer la besace : ";
        while(!(std::cin >> i) || i <0 || i>besace.getNbObjets()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrez un nombre correspondant a un objet ou 0 pour fermer la besace.\n";
        }
        if (i!=0){
            Objet selection = this->besace.selectionnerObjet(i-1);

            std::cout<<"Que voulez vous faire de "<< selection.getNom()<< " ?\n0-Annuler   1-Utiliser   2-Jeter"<<std::endl;

            while(!(std::cin >> j) || (j!=0 && j !=1 && j!=2)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Entrez 1 ou 2.\n";
            }

            if (j==1){
                utiliserObjet(selection);
                this->besace.jeter(i-1);
            }
            if (j==2){
                this->besace.jeter(i-1);
            }
        }
    }
}

void Joueur::utiliserObjet(Objet obj, bool enCombat) {
    if (obj.getType() == "potion"){
            int tmp = this->pv;
            this->pv += obj.getEffet();
            if (this->pv>maxPV) this-> pv = maxPV;
            std::cout<<"Vous avez utilise " << obj.getNom() << " : " << this->pv - tmp << " PV recuperes." << std::endl;
    }
    else if (obj.getType() == "arme")this->atq += obj.getEffet();
    else if (obj.getType() == "armure")this->res += obj.getEffet();
}

int Joueur::getPosition() {
    return this->position;
}

void Joueur::setPosition(int pos){
    this->position = pos;
}

int Joueur::getPV() {
    return this->pv;
}

void Joueur::setPV(int pv){
    this->pv = pv;
}

int Joueur::getAtq() {
    return this->atq;
}

void Joueur::setAtq(int atq){
    this->atq = atq;
}

int Joueur::getRes() {
    return this->res;
}

void Joueur::setRes(int res){
    this->res = res;
}

Besace Joueur::getBesace(){
    return besace;
}

void Joueur::setBesace(Besace b){
    this-> besace = b;
}

bool Joueur::estMort(){
    return mort;
}

bool Joueur::aGagne(){
    return gagne;
}


Joueur::~Joueur()
{
    //dtor
}
