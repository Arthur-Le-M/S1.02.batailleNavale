#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;


// Creation de l'enregistrement coordBateau qui représente les coordonnées du bateau
struct coordonnee 
{
    int coordX;
    int coordY;
};


void afficherRegles();
// BUT : Afficher les règles du jeu


void afficherGrille(char tableau[][9], unsigned int nbLigne, unsigned int nbColonne);
// BUT : Afficher la grille du jeu avec la bataille navale


void placerBateau(coordonnee tableau[], unsigned short int longueurBateau, unsigned short int largeurPlateau, unsigned short int hauteurPlateau);
// BUT : Déterminer les coordonnées du bateau sur un plateau de largeurPlateau par hauteurPlateau


#endif