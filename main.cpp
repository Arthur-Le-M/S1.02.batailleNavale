/*
 Programme : Bataille Navale
 But :  Realiser une partie du jeu de société "Bataille Navale"
 Date de dernière modification : 
 Auteur : Chabanat Matis, Le Menn Arthur | TD1 - TP1
 Remarques : 
*/

#include <iostream>
#include "sousProgrammes.h"
#include "game-tools.h"
using namespace std;

int main(void)
{
    /************************************* VARIABLES *************************************/
    // Créer la grille/le plateau de jeu
    const unsigned short int NB_LIGNES = 9;
    const unsigned short int NB_COLONNES = 9;
    char plateau[NB_LIGNES][NB_COLONNES] = {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    // Compteurs
    unsigned short int nbTouches; // Nombre de tirs qui ont touché le bateau
    unsigned short int nbTirs;    // Nombre de tirs effectués depuis le début de la partie

    // Coordonnées du bateau
    const unsigned short int LONG_BATEAU = 4;  // La longueur du bateau
    IndiceCoordonnee coordBateau[LONG_BATEAU]; // Les coordonnées du bateau

    // Concernant le tir
    bool estTouche;             // Indique si le tir touche le navire
    Coordonnee coordTir;        // Représente les coordonnées du tir saisies par le joueur
    IndiceCoordonnee cooTir;    // Représente les indices des coordonnées du tir, à utiliser dans le plateau 
    int y;                      // Variable qui va nous permettre de convertir char en int
    bool abandon;               // True si le joueur souhaite abandonner, false sinon

    // Indicateur de saisie
    bool erreurSaisie; // L'utilisateur à fait une erreur de saisie ou pas

    /************************************* TRATEMENTS *************************************/
    /********** INITIALISATION **********/
    // Mise des variables à leurs statuts initiaux
    erreurSaisie == true;

    // Initialiser les compteurs
    nbTouches = 0;
    nbTirs = 0;

    // Initialiser les coordonnées du bateau
    placerBateau(coordBateau, LONG_BATEAU, NB_COLONNES, NB_LIGNES);

    /********** JOUER LA PARTIE **********/
    while (nbTouches < LONG_BATEAU)
    {
        // Initialisation de la manche
        estTouche = false;

        // Effacer l'écran
        effacer();

        // Affichage de l'entête
        afficherRegles();

        // Affichage des coordonnées du bateau
        afficherCoordBateau(coordBateau, LONG_BATEAU);

        // Afficher la nouvelle grille
        afficherGrille(plateau, NB_LIGNES, NB_COLONNES);

        // Saisie verif des coordonnées
        do
        {
            do
            {
                // Avant la saisie on considère qu'il n'y a pas d'erreur
                erreurSaisie = false;

                // Saisie
                cout << "Votre " << nbTirs+1 << "e tir (ex. A3) ou abandonner (@@) : ";
                cin >> coordTir.coordX;
                cin >> coordTir.coordY;

                // Recherche en coordX
                if (coordTir.coordX != 'A' && coordTir.coordX != 'B' && coordTir.coordX != 'C' && coordTir.coordX != 'D' && coordTir.coordX != 'E' &&
                    coordTir.coordX != 'F' && coordTir.coordX != 'G' && coordTir.coordX != 'H' && coordTir.coordX != 'I' && coordTir.coordX != '@')
                {
                    afficherTexteEnCouleur("Erreur en 'X' !", rouge, true);
                    erreurSaisie = true;
                }

                // Recherche en coordY
                if (coordTir.coordY != '1' && coordTir.coordY != '2' && coordTir.coordY != '3' && coordTir.coordY != '4' && coordTir.coordY != '5' &&
                    coordTir.coordY != '6' && coordTir.coordY != '7' && coordTir.coordY != '8' && coordTir.coordY != '9' && coordTir.coordY != '@')
                {
                    afficherTexteEnCouleur("Erreur en 'Y' !", rouge, true);
                    erreurSaisie = true;
                }
            } while (erreurSaisie == true);

            // Recherche de l'abandon
            if (coordTir.coordX == '@' && coordTir.coordY == '@')
            {
                abandon = true;
                break;
            }
            else
            {
                if (coordTir.coordX != '@' && coordTir.coordY == '@')
                {
                    afficherTexteEnCouleur("Erreur en 'X' !", rouge, true);
                    erreurSaisie = true;
                }
                else if (coordTir.coordX == '@' && coordTir.coordY != '@')
                {
                    afficherTexteEnCouleur("Erreur en 'Y' !", rouge, true);
                    erreurSaisie = true;
                }
            }
        }
        while (erreurSaisie == true);

        

        // Condition de sortie - cas de l'abandon
        if (abandon)
        {
            break;
        }

        // Incrémentation du nombre de Tirs
        nbTirs++;

        // Determiner si le tir touche le bateau ou non
        for (int i = 0; i < LONG_BATEAU; i++)
        {
            if (coordonneeVersIndice(coordTir).coordX == coordBateau[i].coordX && coordonneeVersIndice(coordTir).coordY == coordBateau[i].coordY)
            {
                cout << "Touche !";
                estTouche = true;
                nbTouches++;
            }
        }

        // Marquer la grille
        cooTir.coordX = coordonneeVersIndice(coordTir).coordX;
        cooTir.coordY = coordonneeVersIndice(coordTir).coordY;

        if (estTouche)
        {
            plateau[cooTir.coordY][cooTir.coordX] = 'o';
        }
        else
        {
            plateau[cooTir.coordY][cooTir.coordX] = '.';
        }
    }

    /********** FIN DE LA PARTIE **********/
    // Effacer l'ecran
    effacer();

    // Affichage de l'entête
    afficherRegles();

    // Afficher les coordonnées du bateau
    afficherCoordBateau(coordBateau, LONG_BATEAU);

    // Afficher la grille
    afficherGrille(plateau, NB_LIGNES, NB_COLONNES);

    if (abandon)
    {
        // Afficher le nombre de touches après un certain nombre de tirs si le joueur abandonne
        cout << "A B A N D O N - Bateau touche " << nbTouches << " fois sur " << nbTirs << ".";
    }
    else
    {
        // Afficher le nombre de tirs effectués pour couler le bateau
        cout << "B A T E A U  C O U L E en " << nbTirs << " tirs !" << endl;
    }

    return 0;
}
