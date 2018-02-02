//
// Created by henri on 31/01/2018.
//

#include "Case.h"

Case::Case(bool type)
{
    this->type = type;
}
bool Case::getType() { return this->type; }
void Case::setType(bool type) { this->type = type; }

int Case::getStatus() // 0 pour inconnu; 1 pour -; 2 pour flag
{
    return this->status;
}
void Case::setStatus(int status) { this->status = status; }

void Case::setAffichageValeur(int valeur) { this->affichageValeur = valeur; }
int Case::getAffichageValeur() { return this->affichageValeur; }