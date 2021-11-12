#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;

// Creation du type énuméré positionX qui va nous permettre de définir la position en X du bateau
enum positionX {A,B,C,D,E,F,G,H,I};

// Creation de l'enregistrement coordBateau qui représente les coordonnées du bateau
struct coordonnee 
{
    positionX coordX;
    int coordY;
};


void afficherRegles();
// BUT : Afficher les règles du jeu


void afficherGrille(char tableau[][9], unsigned int nbLigne, unsigned int nbColonne);
// BUT : Afficher la grille du jeu avec la bataille navale





#endif