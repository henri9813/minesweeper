#include <iostream>
#include "Plateau.h"

using namespace std;

int main() {
    cout << "Démineur" << endl;
    int largeur;
    int hauteur;
    int nombremine;

    cout << "Largeur du plateau: ";
    cin >> largeur;
    cout << "Hauteur du plateau: ";
    cin >> hauteur;
    cout << "Nombre de mines: ";
    cin >> nombremine;

    Plateau plateau = Plateau(largeur, hauteur, nombremine);

    int x, y;
    while(true)
    {
        plateau.showPlateau();
        cout << endl;
        cout << endl;
        cout << "Selectionner une colonne: ";
        cin >> x;
        cout << "Selectionner une ligne: ";
        cin >> y;
        if(x == 100000)
            break;
        plateau.getCase(x,y, false);

    }

    return 0;
}