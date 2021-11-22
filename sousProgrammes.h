#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;

// Creation de l'enregistrement coordBateau qui représente les coordonnées du bateau
struct IndiceCoordonnee
{
    int coordX;
    int coordY;
};

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

Coordonnee indiceVersCoordonnee(IndiceCoordonnee indice);
// BUT : transformer une variable de type indiceCoordonnee en une variable de type Coordonnee

IndiceCoordonnee coordonneeVersIndice(Coordonnee coordonnee);
// BUT : transformer une variable de type Coordonnee en une variable de type indiceCoordonnee

#endif