//
// Created by henri on 31/01/2018.
//

#ifndef MINESWEEPER_PLATEAU_H
#define MINESWEEPER_PLATEAU_H


#include "Case.h"
#include <vector>
class Plateau {
    public:
        Plateau(int largeur, int hauteur, int nombremine);
        ~Plateau();
        void showPlateau();
        bool getCase(int x,int y, bool parsing = false);
        int getUnknownNumber();
    private:
        int largeur;
        int hauteur;
        int nombremine;
        Case** tableau;
};


#endif //MINESWEEPER_PLATEAU_H