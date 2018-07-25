#include "Carte.h"

Carte::Carte(int nombreEtages)
{
    this->nbEtages=nombreEtages;
    this->etageActuel=0;

    for(int i = 0; i<nbEtages; i++){
		etages[i]=Etage(i+1);
	}

    srand(time(NULL));

	for(int i = 0; i< nbEtages;i++){
        int alea=rand()%nbEtages;
        Etage tmp = etages[i];
		etages[i] = etages[alea];
		etages[alea] = tmp;
	}

    this->carte = etages[0].getEtage();
    this->hauteur = etages[0].getHauteur();
    this->largeur = etages[0].getLargeur();

    this->posJoueur = etages[0].getPosInitialeJ();
    this->carte[posJoueur]='>';
    if(nbEtages>1)this->carte[etages[0].getPosEscMont()]='+';

    int* tabP = etages[0].getPosPot();
    int tailleP = etages[0].getNbPot();

    for (int i = 0; i<tailleP; i++){
        carte[tabP[i]] = 'P';
    }
    int* tabM = etages[0].getPosMonstres();
    tailleTabM = etages[0].getNbMonstres();
    tabMonstresEtage = new Monstre [tailleTabM];

    for (int i = 0; i<tailleTabM; i++){
        tabMonstresEtage[i] = Blob(etageActuel, tabM[i]);
        carte[tabM[i]] = 'B';
    }

    carte[(etages[etageActuel].getPosBoss())] = 'M';
    carte[(etages[etageActuel].getPosArmure())] = 'A';
}

void Carte::versEst(){
    this->carte[posJoueur] = '>';
}
void Carte::versOuest(){
    this->carte[posJoueur] = '<';
}
void Carte::versNord(){
    this->carte[posJoueur] = '^';
}
void Carte::versSud(){
    this->carte[posJoueur] = 'v';
}

void Carte::deplacerJoueur(Joueur &j, int nouvellePos, char iconeJoueur){
    switch(this->carte[nouvellePos]) {
        case ' ':
            this->carte[posJoueur]=' ';
            this->posJoueur=nouvellePos;
            this->carte[posJoueur]=iconeJoueur;
            break;
        case '=':
            if (carte[nouvellePos+1] == '=') {
                this->carte[posJoueur]=' ';
                this->posJoueur=nouvellePos;
                do {
                    this->posJoueur++;
                } while (this->carte[posJoueur+1]=='=');
                this->posJoueur++;
            }
            else if (carte[nouvellePos-1] == '=') {
                this->carte[posJoueur]=' ';
                this->posJoueur=nouvellePos;
                do {
                    this->posJoueur--;
                } while (this->carte[posJoueur-1]=='=');
                this->posJoueur--;
            }
            else if (carte[nouvellePos-this->largeur] == '=') {
                this->carte[posJoueur]=' ';
                this->posJoueur=nouvellePos;
                do {
                    this->posJoueur-=this->largeur;
                } while (this->carte[posJoueur-this->largeur]=='=');
                this->posJoueur-=this->largeur;
            }
            else if (carte[nouvellePos+this->largeur] == '=') {
                this->carte[posJoueur]=' ';
                this->posJoueur=nouvellePos;
                do {
                    this->posJoueur+=this->largeur;
                } while (this->carte[posJoueur+this->largeur]=='=');
                this->posJoueur+=this->largeur;
            }
            this->carte[posJoueur]=iconeJoueur;
            break;
        case '+':
            allerEtageSup();
            break;
        case '_':
            allerEtageInf();
            break;
        case 'P':
            this->carte[posJoueur]=' ';
            this->posJoueur = nouvellePos;
            this->carte[posJoueur]=iconeJoueur;
            j.ramasserObjet(Potion(etageActuel));
            etages[etageActuel].retirerPotion(posJoueur);
            break;
        case 'B':
            this->carte[posJoueur]=iconeJoueur;
            if (j.combattre(getMonstreAt(nouvellePos))){
                this->carte[nouvellePos]=' ';
                retirerMonstre(nouvellePos);
            }
            break;
        case 'M':
            this->carte[posJoueur]=iconeJoueur;
            if (j.combattre(Boss(etageActuel,nbEtages))){
                this->carte[nouvellePos]=' ';
                etages[etageActuel].retirerBoss();
            }
            break;
        case 'A':
            this->carte[posJoueur]=' ';
            this->posJoueur = nouvellePos;
            this->carte[posJoueur]=iconeJoueur;
            j.ramasserObjet(Armure(etageActuel));
            etages[etageActuel].retirerArmure();
            break;
        default:
            break;
    }

}

void Carte::allerEst(Joueur &j){
    deplacerJoueur(j, posJoueur+1, '>');
}

void Carte::allerOuest(Joueur &j){
    deplacerJoueur(j, posJoueur-1, '<');
}

void Carte::allerSud(Joueur &j){
    deplacerJoueur(j, posJoueur+largeur, 'v');
}

void Carte::allerNord(Joueur &j){
    deplacerJoueur(j, posJoueur-largeur, '^');
}

void Carte::allerNordEst(Joueur &j){
    deplacerJoueur(j, posJoueur-largeur+1, '>');
}

void Carte::allerNordOuest(Joueur &j){
    deplacerJoueur(j, posJoueur-largeur-1, '<');
}

void Carte::allerSudOuest(Joueur &j){
    deplacerJoueur(j, posJoueur+largeur-1, '<');
}

void Carte::allerSudEst(Joueur &j){
    deplacerJoueur(j, posJoueur+largeur+1, '>');
}

void Carte::allerEtageSup(){
    etageActuel++;
    carte = etages[etageActuel].getEtage();
    posJoueur = etages[etageActuel].getPosInitialeJ();
    carte[posJoueur]='>';

    carte[etages[etageActuel].getPosEscDesc()]='_';
    if (etageActuel!=nbEtages-1)carte[etages[etageActuel].getPosEscMont()]='+';

    int* tabP = etages[etageActuel].getPosPot();
    int tailleP = etages[etageActuel].getNbPot();
    for (int i = 0; i<tailleP; i++){
        carte[tabP[i]] = 'P';
    }

    int* tabM = etages[etageActuel].getPosMonstres();
    tailleTabM = etages[etageActuel].getNbMonstres();
    tabMonstresEtage = new Monstre [tailleTabM];

    for (int i = 0; i<tailleTabM; i++){
        tabMonstresEtage[i] = Blob(etageActuel, tabM[i]);
        carte[tabM[i]] = 'B';
    }

    if (etages[etageActuel].getNbBoss()!=0)carte[(etages[etageActuel].getPosBoss())] = 'M';
    if (etages[etageActuel].getNbArmure()!=0)carte[(etages[etageActuel].getPosArmure())] = 'A';
}

void Carte::allerEtageInf(){
    etageActuel--;
    carte = etages[etageActuel].getEtage();
    posJoueur = etages[etageActuel].getPosDescJ();
    carte[posJoueur]='>';

    if (etageActuel!=0)carte[etages[etageActuel].getPosEscDesc()]='_';
    carte[etages[etageActuel].getPosEscMont()]='+';

    int* tabP = etages[etageActuel].getPosPot();
    int tailleP = etages[etageActuel].getNbPot();
    for (int i = 0; i<tailleP; i++){
        carte[tabP[i]] = 'P';
    }

    int* tabM = etages[etageActuel].getPosMonstres();
    tailleTabM = etages[etageActuel].getNbMonstres();
    tabMonstresEtage = new Monstre [tailleTabM];

    for (int i = 0; i<tailleTabM; i++){
        tabMonstresEtage[i] = Blob(etageActuel, tabM[i]);
        carte[tabM[i]] = 'B';
    }

    if (etages[etageActuel].getNbBoss()!=0)carte[(etages[etageActuel].getPosBoss())] = 'M';
    if (etages[etageActuel].getNbArmure()!=0)carte[(etages[etageActuel].getPosArmure())] = 'A';
}

void Carte::deplacerMonstres(Joueur &j){
    for (int i = 0; i< tailleTabM; i++){
        if (tabMonstresEtage[i].getDeplacement() == "neutre"){
            int currPos = tabMonstresEtage[i].getPosition();
            int nouvPos= deplacementAleatoire(currPos);
            if (carte[nouvPos]=='<' ||carte[nouvPos]=='>' || carte[nouvPos]=='^' ||carte[nouvPos]=='v') {
                Monstre m = getMonstreAt(currPos);
                m.attaquer(j);  //le monstre attaque le joueur et force le combat
                if (j.combattre(m)){
                    this->carte[currPos]=' ';
                    retirerMonstre(currPos);
                };
            }
            else { carte[currPos]=' ';
            carte[nouvPos]='B';
            tabMonstresEtage[i].setPosition(nouvPos);
            }
        }
    }
}

int Carte::deplacementAleatoire (int positionInitiale){
    int nouvellePosition;
    do {
    srand(GetTickCount());
        int aleaDeplacement=(positionInitiale+rand())%8;
        switch (aleaDeplacement) {
        case 0:
            nouvellePosition = positionInitiale+1; //a droite
            break;
        case 1:
            nouvellePosition= positionInitiale-1; //a gauche
            break;
        case 2:
            nouvellePosition= positionInitiale+this->largeur; //en bas
            break;
        case 3:
            nouvellePosition= positionInitiale-this->largeur; //en haut
            break;
        case 4:
            nouvellePosition= positionInitiale+this->largeur+1;
            break;
        case 5:
            nouvellePosition= positionInitiale -(this->largeur-1);
            break;
        case 6:
            nouvellePosition= positionInitiale + (this->largeur-1);
            break;
        case 7:
            nouvellePosition= positionInitiale- (this->largeur+1);
            break;
        }
    }
    while (carte[nouvellePosition]!= ' ' && carte[nouvellePosition]!= '<'&& carte[nouvellePosition]!= '>'&& carte[nouvellePosition]!= '^'&& carte[nouvellePosition]!= 'v');

    return nouvellePosition;
}

Monstre Carte::getMonstreAt(int position){
    for (int i=0; i < etages[etageActuel].getNbMonstres(); i++){
        if (tabMonstresEtage[i].getPosition() == position) {
            return tabMonstresEtage[i];
        }
    }
    std::string erreur = "Erreur Carte::getMonstreAt(" + std::to_string (position) + ")";
    throw std::string(erreur);
}

void Carte::retirerMonstre(int position){
    if (tailleTabM-1 == 0) {
        tabMonstresEtage = new Monstre [etages[etageActuel].getNbMonstres()];
    }
    else {
        Monstre* t= new Monstre [tailleTabM-1];
        int y=0;
        for (int x=0; x<tailleTabM; x++){
            if (tabMonstresEtage[x].getPosition()!=position) {
                t[y] = tabMonstresEtage[x];
                y++;
            }
        }
        tabMonstresEtage = t;
    }
    tailleTabM--;
}

int Carte::getPosJoueur(){
    return this->posJoueur;
}

std::string Carte::getCarte(){
    return this->carte;
}

void Carte::afficher(){
    /*std::string carteCachee = this->carte;
    for (int i = 0; i<posJoueur-(vision);i++){
        if (carteCachee[i] == 'P' || carteCachee[i] == 'P' || carteCachee[i] == 'M') carteCachee[i]=' ';
    }
    for (int i = posJoueur+(vision)+1; i<carteCachee.length();i++){
        if (carteCachee[i] == 'P' || carteCachee[i] == 'B' || carteCachee[i] == 'M'|| carteCachee[i] == 'A') carteCachee[i]=' ';
    }

    int tmpPos;
    for (int i = 6; i>0; i--) {
        for (int j = 0; j<posJoueur-; j++ {

        }
    }
    std::cout<<carteCachee<< std::endl;*/
    std::cout<<carte<< std::endl;
}

Carte::~Carte()
{
    //dtor
}
