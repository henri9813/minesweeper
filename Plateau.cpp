//
// Created by henri on 31/01/2018.
//

#include "Plateau.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Plateau::Plateau(int largeur, int hauteur, int nombremine) {
    this->hauteur = hauteur;
    this->largeur = largeur;
    this->nombremine = nombremine;
    srand (time(NULL));
    int probabilite;

    int aire = largeur*hauteur;

    this->tableau = new Case*[hauteur];
    for(int j = 0; j < hauteur; j++)
    {
        this->tableau[j] = new Case[largeur];
    }

    int coordonnees_x;
    int coordonnees_y;
    while(nombremine > 0)
    {
        coordonnees_x = rand() % (largeur);
        coordonnees_y = rand() % (hauteur);
        if(!this->tableau[coordonnees_y][coordonnees_x].getType())
        {
            this->tableau[coordonnees_y][coordonnees_x].setType(true);
            nombremine--;
        }

    }
    std::cout << "Sorti du programme ";
}

Plateau::~Plateau()
{
    for(int j = 0; j < hauteur; j++)
    {
        delete[] this->tableau[j];
    }
    delete[] tableau;
}

void Plateau::showPlateau()
{
    std::cout << std::endl;
    for(int j = 0; j < this->hauteur; j++)
    {
        for(int i = 0; i < this->largeur; i++)
        {
            switch(this->tableau[j][i].getStatus())
            {
                case 0:
                    std::cout << "[?]";
                    break;
                case 1:
                    std::cout << "[-]";
                    break;
                case 2:
                    std::cout << "[ ]";
                    break;
                case 3:
                    std::cout << "["<< this->tableau[j][i].getAffichageValeur() << "]";
                    break;
                default:
                    std::cout << "[x]";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void Plateau::getCase(int x, int y, bool parsing) {
    if(this->tableau[y][x].getStatus() != 0)
    {
        std::cout << "[Demineur] Case déjà découverte ! :-)" << std::endl;
        return;
    }
    if(!this->tableau[y][x].getType()) //CA NE VA PAS FAIRE BOOM !!!!!
        this->tableau[y][x].setStatus(2); //TKT Morray :-) #systèmePower
    else
    {
        this->tableau[y][x].setStatus(1);
        return;
    } //boom;
    int minecompteur = 0;
    /**
     * Compteur des mines adjacentes
     */
    if(x > 0) //Si x est supérieur à 0 alors on peut regarder les cases de gauches
    {
        if(y-1 >= 0)
            if(this->tableau[y-1][x-1].getType() == 1)
                minecompteur++;
        if(this->tableau[y][x-1].getType() == 1)
            minecompteur++;
        if(y < this->hauteur-1)
            if(this->tableau[y+1][x-1].getType() == 1)
                minecompteur++;
    }
    if(y-1 >= 0)
        if(this->tableau[y-1][x].getType() == 1)
            minecompteur++;
    if(y < this->hauteur-1)
        if(this->tableau[y+1][x].getType() == 1)
            minecompteur++;
    if(x < this->largeur)
    {
        if(y-1 >= 0)
            if(this->tableau[y-1][x+1].getType() == 1)
                minecompteur++;
        if(this->tableau[y][x+1].getType() == 1)
            minecompteur++;
        if(y < this->hauteur-1)
            if(this->tableau[y+1][x+1].getType() == 1)
                minecompteur++;
    }
    if(minecompteur > 0)
    {
        this->tableau[y][x].setStatus(3);
        this->tableau[y][x].setAffichageValeur(minecompteur);
        return;
    }

    if(x > 0)
        if(this->tableau[y][x-1].getStatus() == 0)
            this->getCase(x-1, y, true);
    if(x < this->largeur)
        if(this->tableau[y][x+1].getStatus() == 0)
            this->getCase(x+1, y, true);
    if(y > 0)
    {
        if(this->tableau[y-1][x].getStatus() == 0)
        {
            this->getCase(x, y-1, true);
        }
    }
    if(y < this->hauteur-1)
        if(this->tableau[y+1][x].getStatus() == 0)
            this->getCase(x, y+1, true);

}