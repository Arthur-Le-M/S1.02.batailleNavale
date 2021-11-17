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


void placerBateau(coordonnee tableau[], unsigned short int longueurBateau, unsigned short int largeurPlateau, unsigned short int hauteurPlateau)
{
    // VARIABLES
    coordonnee coordBateau;
    bool erreur = true; // condition d'arrêt
    unsigned short int sensBateau; // Sens dans lequel sera le bateau (compris entre 1 et 4)

    while(erreur == true)
    {
        // INITIALISATION
        // Déterminer la coordonnée de base du bateau
        tableau[0].coordX = random(0, largeurPlateau-1);
        tableau[0].coordY = random(0, largeurPlateau-1);
        // Mettre erreur a true
        erreur=true;
        // Determiner dans quel sens sera le bateau
        sensBateau = random(1,4);

        for(int i=0; i < longueurBateau; i++){
        cout << "X :"<<tableau[i].coordX << " Y : "<< tableau[i].coordY << " sens du bateau : " << sensBateau <<endl;
    }

        // PLACEMENT DU BATEAU
        for(unsigned int i=0; i < longueurBateau; i++){
            switch (sensBateau)
            {
            case 1:
                if(tableau[0].coordX + longueurBateau < largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i-1].coordX+1;
                    tableau[i].coordY = tableau[i-1].coordY;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            case 2:
                if(tableau[0].coordY + longueurBateau < largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i-1].coordX;
                    tableau[i].coordY = tableau[i-1].coordY+1;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            case 3:
                if(tableau[0].coordY + longueurBateau < largeurPlateau && tableau[0].coordY + longueurBateau < largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i-1].coordX+1;
                    tableau[i].coordY = tableau[i-1].coordY+1;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            case 4:
                if(tableau[0].coordY - longueurBateau > largeurPlateau && tableau[0].coordY - longueurBateau > largeurPlateau){
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i-1].coordX-1;
                    tableau[i].coordY = tableau[i-1].coordY-1;
                    erreur = false;
                }
                else{
                    i = longueurBateau;
                }
                break;
            default:
                break;
            }
        }
    }

    for(int i=0; i < longueurBateau; i++){
        cout << tableau[i].coordX << tableau[i].coordY; 
    }
}    


