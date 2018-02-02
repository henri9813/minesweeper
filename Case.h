//
// Created by henri on 31/01/2018.
//

#ifndef MINESWEEPER_CASE_H
#define MINESWEEPER_CASE_H


class Case {
private:
    bool type;
    int status = 0;
    int affichageValeur = 0;
public:
    Case(bool type = false);
    void setType(bool type);
    int getStatus();
    void setStatus(int status);
    bool getType();

    void setAffichageValeur(int valeur);
    int getAffichageValeur();
};


#endif //MINESWEEPER_CASE_H
