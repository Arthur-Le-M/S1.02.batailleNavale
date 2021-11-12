#include "sousProgrammes.h"

void afficherRegles()
{
    afficherTexteEnCouleur("B A T A I L L E  N A V A L E",bleu,true);
    cout << endl;
    cout << "Vous devez couler un bateau de 4 cases" << endl;
    cout << "(vertical ou horizontal ou diagonal)." << endl;
    cout << endl;
}


void afficherGrille(char tableau[][9], unsigned int nbLigne, unsigned int nbColonne)
{
    // Declaration des indices des boucles 
    unsigned int i;
    unsigned int j;

    cout << "  A B C D E F G H I" << endl;

    for (i = 0; i <= (nbLigne-1) ; i++)
    {
        cout << i+1 << " ";
        
        for (j = 0; j <= (nbColonne-1); j++)
        {
            cout << tableau[i][j] << " ";
        }

        // Passage à la ligne
        cout << endl;
    }
    

}


