#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;

// Creation de l'enregistrement IndiceCoordonnee qui représente l'indice d'une coordonnée dans le tableau 2 dimensions.
struct IndiceCoordonnee
{
    int coordX;
    int coordY;
};

// Creation de l'enregistrement Coordonnee qui représente les coordonnées saisies par le joueur.
struct Coordonnee
{
    char coordX;
    char coordY;
};

void afficherRegles();
// BUT : Afficher les règles du jeu

void afficherGrille(char tableau[][9], unsigned int nbLigne, unsigned int nbColonne);
// BUT : Afficher la grille du jeu avec la bataille navale

void placerBateau(IndiceCoordonnee tableau[], unsigned short int longueurBateau, unsigned short int largeurPlateau, unsigned short int hauteurPlateau);
// BUT : Déterminer les coordonnées du bateau sur un plateau de largeurPlateau par hauteurPlateau

void afficherCoordBateau(IndiceCoordonnee tableau[], unsigned short int longueurBateau);
// BUT : Afficher les coordonnées du bateau grâce a ses indices de coordonnées (placés dans le tableau)
// Précondition : les coordonnées traitées sont des indices de coordonnées

Coordonnee indiceVersCoordonnee(IndiceCoordonnee indice);
// BUT : transformer une variable de type indiceCoordonnee en une variable de type Coordonnee

IndiceCoordonnee coordonneeVersIndice(Coordonnee coordonnee);
// BUT : transformer une variable de type Coordonnee en une variable de type indiceCoordonnee

#endif