#include <iostream>
#include "Plateau.h"

using namespace std;

//Réalisé par:
//222364 - Henri Devigne - Valenciennes

int main() {
    system("cls");
    cout << "________                 .__                            \n"
            "\\______ \\   ____   _____ |__| ____   ____  __ _________ \n"
            " |    |  \\_/ __ \\ /     \\|  |/    \\_/ __ \\|  |  \\_  __ \\\n"
            " |    `   \\  ___/|  Y Y  \\  |   |  \\  ___/|  |  /|  | \\/\n"
            "/_______  /\\___  >__|_|  /__|___|  /\\___  >____/ |__|   \n"
            "        \\/     \\/      \\/        \\/     \\/              " << endl;
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
    bool RAS = true; //Rien à signaler :-P
    while(RAS && plateau.getUnknownNumber() != nombremine)
    {
        system("cls");
        cout << "________                 .__                            \n"
                "\\______ \\   ____   _____ |__| ____   ____  __ _________ \n"
                " |    |  \\_/ __ \\ /     \\|  |/    \\_/ __ \\|  |  \\_  __ \\\n"
                " |    `   \\  ___/|  Y Y  \\  |   |  \\  ___/|  |  /|  | \\/\n"
                "/_______  /\\___  >__|_|  /__|___|  /\\___  >____/ |__|   \n"
                "        \\/     \\/      \\/        \\/     \\/              " << endl << endl << endl;
        plateau.showPlateau();
        cout << endl;
        cout << endl;
        cout << "Selectionner une colonne: ";
        cin >> x;
        cout << "Selectionner une ligne: ";
        cin >> y;
        if(x == 100000)
            break;
        //Si la case choisi est une mine :'(
        if(plateau.getCase(x,y, false))
        {
            RAS = false;
        }
    }
    if(plateau.getUnknownNumber() == nombremine)
        cout << "VICTOIRE !!!!! Vous etes un veritable Gentleman ! " << endl;
    else
    {
        system("cls");
        plateau.showPlateau();
        cout << "Tu as perdu !!!!!!! Vous n'etes pas un Gentleman ! " << endl;
    }
    cout << "Appuyez sur entrer pour recommencer le jeu";
    cin;
    main();
    return 0;
}