/*
 Programme : Bataille Navale
 But :  Realiser une partie du jeu de société "Bataille Navale"
 Date de dernière modification : 
 Auteur : Chabanat Matis, Le Menn Arthur | TD1 - TP1
 Remarques : 
*/

#include<iostream>
#include "sousProgrammes.h"
#include "game-tools.h"
using namespace std;

int main1 (void)
{
    // VARIABLES
    // Créer la grille/le plateau de jeu
    const unsigned short int NB_LIGNES = 9;
    const unsigned short int NB_COLONNES = 9;
    char plateau[NB_LIGNES][NB_COLONNES] = {
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',' '
    };
    
    // Compteurs
    unsigned short int nbTouches; // Nombre de tirs qui ont touché le bateau
    unsigned short int nbTirs; // Nombre de tirs effectués depuis le début de la partie

    // Coordonnées du bateau
    const unsigned short int LONG_BATEAU = 4; // La longueur du bateau
    IndiceCoordonnee coordBateau[LONG_BATEAU]; // Les coordonnées du bateau

    // Concernant le tir
    bool estTouche; // Indique si le tir touche le navire
    Coordonnee coordTir; // Représente les coordonnées du tir saisies par le joueur
    int y; // Variable qui va nous permettre de convertir char en int

    // Indicateur de saisie
    bool erreurSaisie; // L'utilisateur à fait une erreur de saisie ou pas

    // TRAITEMENTS
    /********** INITIALISATION **********/ 
    // Affichage de l'entête
    afficherRegles();

    // Initialiser les coordonnées du bateau
    placerBateau(coordBateau, LONG_BATEAU, NB_COLONNES, NB_LIGNES);

    // Initialiser les compteurs 
    nbTouches = 0;
    nbTirs = 0;


    /********** JOUER LA PARTIE **********/
    while (nbTouches < LONG_BATEAU) 
    {
        // Initialisation de la manche
        estTouche = false;

        // Effacer l'écran
        effacer();

        // Afficher la nouvelle grille
        afficherGrille(plateau, NB_LIGNES, NB_COLONNES);

        // Saisie verif des coordonnées
        do
        {
            // Avant la saisie on considère qu'il n'y a pas d'erreur
            erreurSaisie = false;

            // Saisie
            cout << "Votre " << nbTirs << "eme tir (ex. A3) ou abandonner (@@) : ";
            cin >> coordTir.coordX;
            cin >> coordTir.coordY;

            // Verification de la position en X
            if (coordTir.coordX != 'A' && coordTir.coordX != 'B' && coordTir.coordX != 'C' && coordTir.coordX != 'D' && coordTir.coordX != 'E' && 
                coordTir.coordX != 'F' && coordTir.coordX != 'G' && coordTir.coordX != 'H' && coordTir.coordX != 'I')
            {
                afficherTexteEnCouleur("Erreur en 'X' !",rouge,true);
                erreurSaisie = true;
            }
            
            // Passage de char à int pour coord Y
            y = int (coordTir.coordY);

            // Verification de la position en Y
            if (y < 1 || y > 9)
            {
                afficherTexteEnCouleur("Erreur en 'Y' !",rouge,true);
                erreurSaisie = true;
            }
        }
        while (erreurSaisie == true);
        
    
        // Determiner si le tir touche le bateau ou non
        for(int i=0; i<LONG_BATEAU; i++){
            if(coordonneeVersIndice(coordTir) == coordBateau[i]){
            cout << "Touché !";
            estTouche = true;
            }
        }
        

        // Marquer la grille
    }



    /********** FIN DE LA PARTIE **********/
    // Afficher les coordonnées du bateau


    // Afficher la grille
    afficherGrille(plateau,NB_LIGNES,NB_COLONNES);

    // Afficher le nombre de tirs effectués pour couler le bateau
    cout << "Il a fallu " << nbTirs << " tirs pour detruire le bateau ennemi !" << endl;




    return 0;
}

int main(void){
    int const longueurBateau = 4;
    IndiceCoordonnee tableau[longueurBateau];
    Coordonnee nouveauTab[longueurBateau];

    placerBateau(tableau, longueurBateau,9,9);

    for(int i=0; i < longueurBateau; i++){
        nouveauTab[i] = indiceVersCoordonnee(tableau[i]);
        cout << "X :"<<nouveauTab[i].coordX << " Y : "<< nouveauTab[i].coordY <<endl;
    }
}
