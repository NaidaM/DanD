#include "Monstre.h"
#include "Joueur.h"
#include <string>

Monstre::Monstre()
{
}

void Monstre::attaquer(Joueur &j){
    j.recevoirDegats(this->atq);
}

int Monstre::recevoirDegats(int d) {
    int degats = d-res;
    if (degats<0) degats = 0;
    this->pv -= degats;
    if (this->pv<0)this->pv = 0;
    return degats;
}

std::string Monstre::getNom() {
    return this->nom;
}

int Monstre::getPV() {
    return this->pv;
}

void Monstre::setPV(int pv){
    this->pv = pv;
}

int Monstre::getAtq() {
    return this->atq;
}

void Monstre::setAtq(int atq){
    this->atq = atq;
}

int Monstre::getRes() {
    return this->res;
}

void Monstre::setRes(int res){
    this->res = res;
}

Objet Monstre::getDrop(){
    return this->drop;
}
bool Monstre::getADrop(){
    return this->aDrop;
}
bool Monstre::estFinal(){
    return mfinal;
}

std::string Monstre::getDeplacement(){
    return this->deplacement;
}

int Monstre::getPosition(){
    return this->position;
}

void Monstre::setPosition(int newPos){
    this->position = newPos;
}

Monstre::~Monstre()
{
    //dtor
}
